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
    public class Ode : IDisposable
    {
        private HandleRef _swigCPtr;
        protected bool SwigCMemOwn;

        internal Ode(IntPtr cPtr, bool cMemoryOwn)
        {
            SwigCMemOwn = cMemoryOwn;
            _swigCPtr = new HandleRef(this, cPtr);
        }

        internal static HandleRef GetCPtr(Ode obj)
        {
            return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj._swigCPtr;
        }

        ~Ode()
        {
            Dispose();
        }

        public virtual void Dispose()
        {
            lock (this) {
                if (_swigCPtr.Handle != IntPtr.Zero) {
                    if (SwigCMemOwn) {
                        SwigCMemOwn = false;
                        CorePinvoke.delete_Ode(_swigCPtr);
                    }
                    _swigCPtr = new HandleRef(null, IntPtr.Zero);
                }
                GC.SuppressFinalize(this);
            }
        }

        // ReSharper disable InconsistentNaming
        protected virtual void system(StateType x, StateType dxdt, double t)
        {
            // ReSharper restore InconsistentNaming
            if (SwigDerivedClassHasMethod("system", SwigMethodTypes0))
                CorePinvoke.Ode_systemSwigExplicitOde(_swigCPtr, StateType.GetCPtr(x), StateType.GetCPtr(dxdt), t);
            else CorePinvoke.Ode_system(_swigCPtr, StateType.GetCPtr(x), StateType.GetCPtr(dxdt), t);
            if (CorePinvoke.SwigPendingException.Pending) throw CorePinvoke.SwigPendingException.Retrieve();
        }

        // ReSharper disable InconsistentNaming
        protected virtual void observer(StateType x, double t)
        {
            // ReSharper restore InconsistentNaming
            if (SwigDerivedClassHasMethod("observer", SwigMethodTypes1))
                CorePinvoke.Ode_observerSwigExplicitOde(_swigCPtr, StateType.GetCPtr(x), t);
            else CorePinvoke.Ode_observer(_swigCPtr, StateType.GetCPtr(x), t);
            if (CorePinvoke.SwigPendingException.Pending) throw CorePinvoke.SwigPendingException.Retrieve();
        }

        public StateType InitialConditions
        {
            set { CorePinvoke.Ode_initialConditions_set(_swigCPtr, StateType.GetCPtr(value)); }
            get
            {
                var cPtr = CorePinvoke.Ode_initialConditions_get(_swigCPtr);
                var ret = (cPtr == IntPtr.Zero) ? null : new StateType(cPtr, false);
                return ret;
            }
        }

        public double From
        {
            set { CorePinvoke.Ode_from_set(_swigCPtr, value); }
            get
            {
                var ret = CorePinvoke.Ode_from_get(_swigCPtr);
                return ret;
            }
        }

        public double To
        {
            set { CorePinvoke.Ode_to_set(_swigCPtr, value); }
            get
            {
                var ret = CorePinvoke.Ode_to_get(_swigCPtr);
                return ret;
            }
        }

        public double Step
        {
            set { CorePinvoke.Ode_step_set(_swigCPtr, value); }
            get
            {
                var ret = CorePinvoke.Ode_step_get(_swigCPtr);
                return ret;
            }
        }

        public Ode()
            : this(CorePinvoke.new_Ode(), true)
        {
            SwigDirectorConnect();
        }

        private void SwigDirectorConnect()
        {
            if (SwigDerivedClassHasMethod("system", SwigMethodTypes0))
                _swigDelegate0 = SwigDirectorsystem;
            if (SwigDerivedClassHasMethod("observer", SwigMethodTypes1))
                _swigDelegate1 = SwigDirectorobserver;
            CorePinvoke.Ode_director_connect(_swigCPtr, _swigDelegate0, _swigDelegate1);
        }

        private bool SwigDerivedClassHasMethod(string methodName, Type[] methodTypes)
        {
            var methodInfo = GetType()
                                 .GetMethod(methodName,
                                            System.Reflection.BindingFlags.Public |
                                            System.Reflection.BindingFlags.NonPublic |
                                            System.Reflection.BindingFlags.Instance, null, methodTypes, null);
            var hasDerivedMethod = methodInfo.DeclaringType != null && methodInfo.DeclaringType.IsSubclassOf(typeof(Ode));
            return hasDerivedMethod;
        }

        private void SwigDirectorsystem(IntPtr x, IntPtr dxdt, double t)
        {
            system(new StateType(x, false), new StateType(dxdt, false), t);
        }

        private void SwigDirectorobserver(IntPtr x, double t)
        {
            observer(new StateType(x, false), t);
        }

        public delegate void SwigDelegateOde0(IntPtr x, IntPtr dxdt, double t);

        public delegate void SwigDelegateOde1(IntPtr x, double t);

        private SwigDelegateOde0 _swigDelegate0;
        private SwigDelegateOde1 _swigDelegate1;

        private static readonly Type[] SwigMethodTypes0 = new[] { typeof(StateType), typeof(StateType), typeof(double) };

        private static readonly Type[] SwigMethodTypes1 = new[] { typeof(StateType), typeof(double) };
    }
}
