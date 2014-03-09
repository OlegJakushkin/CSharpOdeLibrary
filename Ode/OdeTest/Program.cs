using System;
using System.Linq;
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
            Console.WriteLine("Complex Test");

            var complexSolver = new ComplexSolver(); 

            const double eta = 2;
            const double alpha = 1;

            var complexEta = new Complex(1, eta);
            var complexAlpha = new Complex(1,alpha);

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

            // And all we need to solve it:
            complexSolver.ConvenienceSolve(stuartLandauOscillator, from, to, step);

            // We can select stepper that our stepper would use
            complexSolver.StepperCode = StepperTypeCode.RungeKutta4;

            // We can select how our IntegrateFunction will work: 
            complexSolver.Solve(stuartLandauOscillator, from, step, to, IntegrateFunctionTypeCode.Adaptive);

            // We can integrate for first N steps
            complexSolver.Solve(stuartLandauOscillator, from, step, 5);

            // Or at given time periods
            complexSolver.Solve(stuartLandauOscillator, new StateType(new[] { 0, 10.0, 100.0, 1000.0 }), step);

            Console.ReadLine();
        }
    }
}
