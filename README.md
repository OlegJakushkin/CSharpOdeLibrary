CSharp Ode Library
================
[CSharpOdeLibrary][1] by Oleg Jakushkin and Olga Sedova.

Free use of this software is granted under the terms of the GNU Lesser General Public License (LGPL). For details see the files LICENSE.LESSER.md and LICENSE.md 

Simple C# ODE Solver Library (Wrapper around Boost.OdeInt). 

Say you want to define ODE system like that:
```CSharp
           var lorenz = new LambdaOde
            {
                From = 0,
                To = 25,
                Step = 0.1,
                InitialConditions = new StateType(new[] { 10, 1.0, 1.0 }),
                OdeObserver = (x, t) => Console.WriteLine("{0} : {1} : {2}", x[0], x[1], x[2]),
                OdeSystem =
                (x, dxdt, t) => {
                    const double sigma = 10.0;
                    const double r = 28.0;
                    const double b = 8.0 / 3.0;
                    dxdt[0] = sigma * (x[1] - x[0]);
                    dxdt[1] = r * x[0] - x[1] - x[0] * x[2];
                    dxdt[2] = -b * x[2] + x[0] * x[1];
                }
            };
```

Or as Your Own Class:
```CSharp
using System;
using OdeLibrary;

namespace OdeTest
{
    class LorenzOde : Ode
    {
        protected override void observer(StateType x, double t)
        {
            if (x.Capacity != 0)
            {
                Console.WriteLine("{0} : {1} : {2}", x[0], x[1], x[2]);
            }
        }

        protected override void system(StateType x, StateType dxdt, double t)
        {
            const double sigma = 10.0;
            const double r = 28.0;
            const double b = 8.0/3.0;
            dxdt[0] = sigma * (x[1] - x[0]);
            dxdt[1] = r * x[0] - x[1] - x[0] * x[2];
            dxdt[2] = -b * x[2] + x[0] * x[1];
        }
    }
}
```

or with **Complex Numbers**:
```
var stuartLandauOscillator = new ComplexLambdaOde
{
    InitialConditions =  new ComplexStateType {new Complex(1, 0)},
    OdeObserver = (x, t) => Console.WriteLine("{0}", x[0]),
    OdeSystem =
    (x, dxdt, t) =>
    {
        dxdt[0] = complexEta * x[0] - (complexAlpha *  x[0].Norm()) * x[0];
    }

};
```


You can do it with our library assistance.

Simple, Fast, Modern, C# ODE Solver
===================================
We use Boost.OdeInt as C++ code base. Provide simple C++ wrapper around it. Use SWIG to generate bride between C++ and C#. And provide simple modern interface for its use.

Motivation Exaple (Console sample):
```CSharp
using System;
using OdeLibrary;

namespace OdeTest
{
    class Program
    {
        static void Main()
        {
            //library uses one solver type (more will come if there will be demand): dense output stepper based on runge_kutta_dopri5 with standard error bounds 10^(-6) for the steps.
            var solver = new Solver();

            const double @from = 0.0;
            const double to = 25.0;
            const double step = 0.1;
            //Say we have a class describing our system:
            var myLorenz = new LorenzOde
                {
                    InitialConditions = new StateType(new[] { 10, 1.0, 1.0 })
                };

            // All we need to solve it:
            solver.ConvenienceSolve(myLorenz, from, to, step);


            //library class provides a simple to use Lambda API for ODE system defenition (example of lorenz, 50 steps)
            var lorenz = new LambdaOde
            {
                InitialConditions = new StateType(new[] { 10, 1.0, 1.0 }),
                OdeObserver = (x, t) => Console.WriteLine("{0} : {1} : {2}", x[0], x[1], x[2]),
                OdeSystem =
                (x, dxdt, t) => {
                    const double sigma = 10.0;
                    const double r = 28.0;
                    const double b = 8.0 / 3.0;
                    dxdt[0] = sigma * (x[1] - x[0]);
                    dxdt[1] = r * x[0] - x[1] - x[0] * x[2];
                    dxdt[2] = -b * x[2] + x[0] * x[1];
                }

            };

            // And all we need to solve it:
            solver.ConvenienceSolve(lorenz, from, to, step);

            // We can select stepper that our stepper would use
            solver.StepperCode = StepperTypeCode.RungeKutta4;

            // We can select how our IntegrateFunction will work: 
            solver.Solve(lorenz, from, step, to, IntegrateFunctionTypeCode.Adaptive);

            // We can integrate for first N steps
            solver.Solve(lorenz, from, step, 5 );

            // Or at given time periods
            solver.Solve(lorenz, new StateType(new[] { 0, 10.0, 100.0, 1000.0 }), step);

            Console.ReadLine();
        }
    }
}
```

Or Windows Forms application example:
![Windows Forms using ZedGraph   ODE solver Demo application](https://github.com/OlegJakushkin/CSharpOdeLibrary/blob/master/WinFormsODEGraphDemo.PNG?raw=true)

```CSharp
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using OdeLibrary;

namespace OdeTestWF
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //library uses one solver type (more will come if there will be demand): dense output stepper based on runge_kutta_dopri5 with standard error bounds 10^(-6) for the steps.
            var solver = new Solver();

            var columns = new List<double>();
            var rows = new List<double>();

            //library class provides a simple to use Lambda API for ODE system defenition (example of lorenz, 50 steps)
            var lorenz = new LambdaOde
            {
                From = 0,
                To = 25,
                Step = 0.1,
                InitialConditions = new StateType(new[] { 10, 1.0, 1.0 }),
                OdeObserver = 
                (x, t) => {
                    columns.Add(x[0]);
                    rows.Add(x[2]);
                },
                OdeSystem = 
                (x, dxdt, t) => {
                    const double sigma = 10.0;
                    const double r = 28.0;
                    const double b = 8.0 / 3.0;
                    dxdt[0] = sigma * (x[1] - x[0]);
                    dxdt[1] = r * x[0] - x[1] - x[0] * x[2];
                    dxdt[2] = -b * x[2] + x[0] * x[1];
                }

            };

            // And all we need to solve it:
            solver.ConvenienceSolve(lorenz);

            //Draw ZedGraph
            var graph = zg1;
            var graphPane = zg1.GraphPane;
            graphPane.Title.Text = "Graph";
            graphPane.XAxis.Title.Text = "x2";
            graphPane.YAxis.Title.Text = "x0";
            graph.IsShowPointValues = true;

            graphPane.AddCurve(
                                     "Lorenz",
                                     rows.ToArray(),
                                     columns.ToArray(),
                                     Color.CornflowerBlue);

            graph.AxisChange();
            graph.Invalidate();
            graph.Refresh();
        }
    }
}
```

How to use OdeLibrary
======================

 - Download latest repo.
 - Open folder Libraries
 - Add Project refrence to OdeLibrary.dll
 - Copy Core.dll into folder with your application


This is Utilety library because we do not support new Numeric Steppers or Integrate Functions Creation or any other type of OdeInt library extension.

What parts of Boost.OdeInt we do provide:
-----------------------------------------

Steppers [description of all Steppers in C++ OdeInt][1]:
 - Euler,
 - ModifiedMidpoint,
 - RungeKutta4,
 - RungeKuttaCashKarp54,
 - RungeKuttaDopri5,
 - RungeKuttaFehlberg78,
 - ControlledRungeKutta,
 - BulirschStoer,
 - BulirschStoerDenseOut,

And Integrate Functions [description of all Integrate Functions in C++ OdeInt][2]:
 - Const,
 - Adaptive

We also support N first steps integration:
```CSharp
    solver.Solve(ode, from, step, constStepsAmmount );
```

As wall as integration at given time points:
```CSharp
    solver.Solve(ode, new StateType(new[] { 0, 10.0, 100.0, 1000.0 }), step);
```

*[Demonstration Windows Forms Solution][3]:*

![Windows Forms using ZedGraph   ODE solver Demo application](https://github.com/OlegJakushkin/CSharpOdeLibrary/blob/master/WinFormsODEGraphDemo.PNG?raw=true)
![Windows Forms using ZedGraph   ODE solver Demo application](https://github.com/OlegJakushkin/CSharpOdeLibrary/blob/master/WinFormsODEGraphDemoDefaultSolver.PNG?raw=true)


  [1]: http://www.boost.org/doc/libs/1_53_0/libs/numeric/odeint/doc/html/boost_numeric_odeint/odeint_in_detail/steppers.html
  [2]: http://www.boost.org/doc/libs/1_53_0/libs/numeric/odeint/doc/html/boost_numeric_odeint/odeint_in_detail/integrate_functions.html
  [3]: https://github.com/OlegJakushkin/CSharpOdeLibrary/releases/tag/v1.0
