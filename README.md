CSharpOdeLibrary
================

Simple C# ODE Solver Library (Wrapper around Boost.OdeInt)


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

            //Say we have a class describing our system:
            var myLorenz = new LorenzOde
                {
                    From = 0,
                    To = 25,
                    Step = 0.1,
                    InitialConditions = new StateType(new[] { 10, 1.0, 1.0 })
                };

            // All we need to solve it:
            solver.Solve(myLorenz);

            //library class provides a simple to use Lambda API for ODE system defenition (example of lorenz, 50 steps)
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

            // And all we need to solve it:
            solver.Solve(lorenz);
        }
    }
}
```

We also provide Windows Forms application.
