/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

using System;
using System.Runtime.InteropServices;

namespace OdeLibrary
{
    public class Solver : IDisposable
    {
        private HandleRef _swigCPtr;
        protected bool SwigCMemOwn;

        internal Solver(IntPtr cPtr, bool cMemoryOwn)
        {
            SwigCMemOwn = cMemoryOwn;
            _swigCPtr = new HandleRef(this, cPtr);
        }

        internal static HandleRef GetCPtr(Solver obj)
        {
            return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj._swigCPtr;
        }

        ~Solver()
        {
            Dispose();
        }

        public virtual void Dispose()
        {
            lock (this) {
                if (_swigCPtr.Handle != IntPtr.Zero) {
                    if (SwigCMemOwn) {
                        SwigCMemOwn = false;
                        CorePinvoke.delete_Solver(_swigCPtr);
                    }
                    _swigCPtr = new HandleRef(null, IntPtr.Zero);
                }
                GC.SuppressFinalize(this);
            }
        }

        public int Solve(Ode ode, IntegrateFunction integrateFunction, Stepper stepper)
        {
            var ret = CorePinvoke.Solver_Solve__SWIG_0(_swigCPtr, Ode.GetCPtr(ode), (int)integrateFunction,
                                                       (int)stepper);
            return ret;
        }

        public int Solve(Ode ode, IntegrateFunction integrateFunction)
        {
            var ret = CorePinvoke.Solver_Solve__SWIG_1(_swigCPtr, Ode.GetCPtr(ode), (int)integrateFunction);
            return ret;
        }

        public int Solve(Ode ode)
        {
            var ret = CorePinvoke.Solver_Solve__SWIG_2(_swigCPtr, Ode.GetCPtr(ode));
            return ret;
        }

        public Solver()
            : this(CorePinvoke.new_Solver(), true)
        {
        }
    }
}
