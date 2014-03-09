#region

using System;

#endregion

namespace OdeLibrary
{
    public class LambdaOde : Ode
    {
        public Action<StateType, StateType, double> OdeSystem { get; set; }

        public Action<StateType, double> OdeObserver { get; set; }

        protected override void system(StateType x, StateType dxdt, double t)
        {
            if (OdeSystem != null)
            {
                OdeSystem(x, dxdt, t);
            }
        }

        protected override void observer(StateType x, double t)
        {
            if (OdeObserver != null)
            {
                OdeObserver(x, t);
            }
        }
    }
  
}