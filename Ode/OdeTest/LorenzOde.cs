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