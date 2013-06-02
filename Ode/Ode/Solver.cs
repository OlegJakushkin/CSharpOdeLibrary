/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

#region

using System;
using System.Runtime.InteropServices;

#endregion

namespace OdeLibrary
{
    public class Solver : IDisposable
    {
        protected bool SwigcMemOwn;
        private HandleRef _swigCPtr;

        internal Solver(IntPtr cPtr, bool cMemoryOwn)
        {
            SwigcMemOwn = cMemoryOwn;
            _swigCPtr = new HandleRef(this, cPtr);
        }

        public Solver() : this(CorePinvoke.new_Solver(), true)
        {
        }

        public StepperTypeCode StepperCode
        {
            set { CorePinvoke.Solver_StepperCode_set(_swigCPtr, (int) value); }
            get
            {
                var ret = (StepperTypeCode) CorePinvoke.Solver_StepperCode_get(_swigCPtr);
                return ret;
            }
        }

        public virtual void Dispose()
        {
            lock (this)
            {
                if (_swigCPtr.Handle != IntPtr.Zero)
                {
                    if (SwigcMemOwn)
                    {
                        SwigcMemOwn = false;
                        CorePinvoke.delete_Solver(_swigCPtr);
                    }
                    _swigCPtr = new HandleRef(null, IntPtr.Zero);
                }
                GC.SuppressFinalize(this);
            }
        }

        internal static HandleRef GetCPtr(Solver obj)
        {
            return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj._swigCPtr;
        }

        ~Solver()
        {
            Dispose();
        }

        public int ConvenienceSolve(Ode od, double from, double step, double to)
        {
            var ret = CorePinvoke.Solver_ConvenienceSolve(_swigCPtr, Ode.GetCPtr(od), from, step, to);
            return ret;
        }

        public int Solve(Ode ode, double from, double step, double to,
                         IntegrateFunctionTypeCode integrateFunctionTypeCode)
        {
            var ret = CorePinvoke.Solver_Solve__SWIG_0(_swigCPtr, Ode.GetCPtr(ode), from, step, to,
                                                       (int) integrateFunctionTypeCode);
            return ret;
        }

        public int Solve(Ode ode, double from, double step, double to)
        {
            var ret = CorePinvoke.Solver_Solve__SWIG_1(_swigCPtr, Ode.GetCPtr(ode), from, step, to);
            return ret;
        }

        public int Solve(Ode ode, double from, double step, int stepsCount)
        {
            var ret = CorePinvoke.Solver_Solve__SWIG_2(_swigCPtr, Ode.GetCPtr(ode), from, step, stepsCount);
            return ret;
        }

        public int Solve(Ode ode, StateType timePoints, double step)
        {
            var ret = CorePinvoke.Solver_Solve__SWIG_3(_swigCPtr, Ode.GetCPtr(ode), StateType.GetCPtr(timePoints), step);
            if (CorePinvoke.SWIGPendingException.Pending) throw CorePinvoke.SWIGPendingException.Retrieve();
            return ret;
        }
    }
}