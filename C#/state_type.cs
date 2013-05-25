/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace OdeLibrary {

using System;
using System.Runtime.InteropServices;

public class state_type : IDisposable, System.Collections.IEnumerable
#if !SWIG_DOTNET_1
    , System.Collections.Generic.IList<double>
#endif
 {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal state_type(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(state_type obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~state_type() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          CorePINVOKE.delete_state_type(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public state_type(System.Collections.ICollection c) : this() {
    if (c == null)
      throw new ArgumentNullException("c");
    foreach (double element in c) {
      this.Add(element);
    }
  }

  public bool IsFixedSize {
    get {
      return false;
    }
  }

  public bool IsReadOnly {
    get {
      return false;
    }
  }

  public double this[int index]  {
    get {
      return getitem(index);
    }
    set {
      setitem(index, value);
    }
  }

  public int Capacity {
    get {
      return (int)capacity();
    }
    set {
      if (value < size())
        throw new ArgumentOutOfRangeException("Capacity");
      reserve((uint)value);
    }
  }

  public int Count {
    get {
      return (int)size();
    }
  }

  public bool IsSynchronized {
    get {
      return false;
    }
  }

#if SWIG_DOTNET_1
  public void CopyTo(System.Array array)
#else
  public void CopyTo(double[] array)
#endif
  {
    CopyTo(0, array, 0, this.Count);
  }

#if SWIG_DOTNET_1
  public void CopyTo(System.Array array, int arrayIndex)
#else
  public void CopyTo(double[] array, int arrayIndex)
#endif
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

#if SWIG_DOTNET_1
  public void CopyTo(int index, System.Array array, int arrayIndex, int count)
#else
  public void CopyTo(int index, double[] array, int arrayIndex, int count)
#endif
  {
    if (array == null)
      throw new ArgumentNullException("array");
    if (index < 0)
      throw new ArgumentOutOfRangeException("index", "Value is less than zero");
    if (arrayIndex < 0)
      throw new ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (count < 0)
      throw new ArgumentOutOfRangeException("count", "Value is less than zero");
    if (array.Rank > 1)
      throw new ArgumentException("Multi dimensional array.", "array");
    if (index+count > this.Count || arrayIndex+count > array.Length)
      throw new ArgumentException("Number of elements to copy is too large.");
    for (int i=0; i<count; i++)
      array.SetValue(getitemcopy(index+i), arrayIndex+i);
  }

#if !SWIG_DOTNET_1
  System.Collections.Generic.IEnumerator<double> System.Collections.Generic.IEnumerable<double>.GetEnumerator() {
    return new state_typeEnumerator(this);
  }
#endif

  System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() {
    return new state_typeEnumerator(this);
  }

  public state_typeEnumerator GetEnumerator() {
    return new state_typeEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class state_typeEnumerator : System.Collections.IEnumerator
#if !SWIG_DOTNET_1
    , System.Collections.Generic.IEnumerator<double>
#endif
  {
    private state_type collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public state_typeEnumerator(state_type collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public double Current {
      get {
        if (currentIndex == -1)
          throw new InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new InvalidOperationException("Collection modified.");
        return (double)currentObject;
      }
    }

    // Type-unsafe IEnumerator.Current
    object System.Collections.IEnumerator.Current {
      get {
        return Current;
      }
    }

    public bool MoveNext() {
      int size = collectionRef.Count;
      bool moveOkay = (currentIndex+1 < size) && (size == currentSize);
      if (moveOkay) {
        currentIndex++;
        currentObject = collectionRef[currentIndex];
      } else {
        currentObject = null;
      }
      return moveOkay;
    }

    public void Reset() {
      currentIndex = -1;
      currentObject = null;
      if (collectionRef.Count != currentSize) {
        throw new InvalidOperationException("Collection modified.");
      }
    }

#if !SWIG_DOTNET_1
    public void Dispose() {
        currentIndex = -1;
        currentObject = null;
    }
#endif
  }

  public void Clear() {
    CorePINVOKE.state_type_Clear(swigCPtr);
  }

  public void Add(double x) {
    CorePINVOKE.state_type_Add(swigCPtr, x);
  }

  private uint size() {
    uint ret = CorePINVOKE.state_type_size(swigCPtr);
    return ret;
  }

  private uint capacity() {
    uint ret = CorePINVOKE.state_type_capacity(swigCPtr);
    return ret;
  }

  private void reserve(uint n) {
    CorePINVOKE.state_type_reserve(swigCPtr, n);
  }

  public state_type() : this(CorePINVOKE.new_state_type__SWIG_0(), true) {
  }

  public state_type(state_type other) : this(CorePINVOKE.new_state_type__SWIG_1(state_type.getCPtr(other)), true) {
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public state_type(int capacity) : this(CorePINVOKE.new_state_type__SWIG_2(capacity), true) {
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  private double getitemcopy(int index) {
    double ret = CorePINVOKE.state_type_getitemcopy(swigCPtr, index);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private double getitem(int index) {
    double ret = CorePINVOKE.state_type_getitem(swigCPtr, index);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private void setitem(int index, double val) {
    CorePINVOKE.state_type_setitem(swigCPtr, index, val);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public void AddRange(state_type values) {
    CorePINVOKE.state_type_AddRange(swigCPtr, state_type.getCPtr(values));
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public state_type GetRange(int index, int count) {
    IntPtr cPtr = CorePINVOKE.state_type_GetRange(swigCPtr, index, count);
    state_type ret = (cPtr == IntPtr.Zero) ? null : new state_type(cPtr, true);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Insert(int index, double x) {
    CorePINVOKE.state_type_Insert(swigCPtr, index, x);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public void InsertRange(int index, state_type values) {
    CorePINVOKE.state_type_InsertRange(swigCPtr, index, state_type.getCPtr(values));
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAt(int index) {
    CorePINVOKE.state_type_RemoveAt(swigCPtr, index);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveRange(int index, int count) {
    CorePINVOKE.state_type_RemoveRange(swigCPtr, index, count);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public static state_type Repeat(double value, int count) {
    IntPtr cPtr = CorePINVOKE.state_type_Repeat(value, count);
    state_type ret = (cPtr == IntPtr.Zero) ? null : new state_type(cPtr, true);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Reverse() {
    CorePINVOKE.state_type_Reverse__SWIG_0(swigCPtr);
  }

  public void Reverse(int index, int count) {
    CorePINVOKE.state_type_Reverse__SWIG_1(swigCPtr, index, count);
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetRange(int index, state_type values) {
    CorePINVOKE.state_type_SetRange(swigCPtr, index, state_type.getCPtr(values));
    if (CorePINVOKE.SWIGPendingException.Pending) throw CorePINVOKE.SWIGPendingException.Retrieve();
  }

  public bool Contains(double value) {
    bool ret = CorePINVOKE.state_type_Contains(swigCPtr, value);
    return ret;
  }

  public int IndexOf(double value) {
    int ret = CorePINVOKE.state_type_IndexOf(swigCPtr, value);
    return ret;
  }

  public int LastIndexOf(double value) {
    int ret = CorePINVOKE.state_type_LastIndexOf(swigCPtr, value);
    return ret;
  }

  public bool Remove(double value) {
    bool ret = CorePINVOKE.state_type_Remove(swigCPtr, value);
    return ret;
  }

}

}
