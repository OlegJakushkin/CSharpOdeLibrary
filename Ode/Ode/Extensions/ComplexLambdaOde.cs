#region

using System;

#endregion

namespace OdeLibrary
{
    public class ComplexLambdaOde : ComplexOde
    {
        public Action<ComplexStateType, ComplexStateType, double> OdeSystem { get; set; }

        public Action<ComplexStateType, double> OdeObserver { get; set; }

        protected override void system(ComplexStateType x, ComplexStateType dxdt, double t)
        {
            if (OdeSystem != null)
            {
                OdeSystem(x, dxdt, t);
            }
        }

        protected override void observer(ComplexStateType x, double t)
        {
            if (OdeObserver != null)
            {
                OdeObserver(x, t);
            }
        }
    }
  
}