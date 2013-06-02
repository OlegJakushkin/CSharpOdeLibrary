/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.9
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIGCSHARP
#define SWIG_DIRECTORS


#ifdef __cplusplus
/* SwigValueWrapper is described in swig.swg */
template<typename T> class SwigValueWrapper {
  struct SwigMovePointer {
    T *ptr;
    SwigMovePointer(T *p) : ptr(p) { }
    ~SwigMovePointer() { delete ptr; }
    SwigMovePointer& operator=(SwigMovePointer& rhs) { T* oldptr = ptr; ptr = 0; delete oldptr; ptr = rhs.ptr; rhs.ptr = 0; return *this; }
  } pointer;
  SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
  SwigValueWrapper(const SwigValueWrapper<T>& rhs);
public:
  SwigValueWrapper() : pointer(0) { }
  SwigValueWrapper& operator=(const T& t) { SwigMovePointer tmp(new T(t)); pointer = tmp; return *this; }
  operator T&() const { return *pointer.ptr; }
  T *operator&() { return pointer.ptr; }
};

template <typename T> T SwigValueInit() {
  return T();
}
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/* Support for throwing C# exceptions from C/C++. There are two types: 
 * Exceptions that take a message and ArgumentExceptions that take a message and a parameter name. */
typedef enum {
  SWIG_CSharpApplicationException,
  SWIG_CSharpArithmeticException,
  SWIG_CSharpDivideByZeroException,
  SWIG_CSharpIndexOutOfRangeException,
  SWIG_CSharpInvalidCastException,
  SWIG_CSharpInvalidOperationException,
  SWIG_CSharpIOException,
  SWIG_CSharpNullReferenceException,
  SWIG_CSharpOutOfMemoryException,
  SWIG_CSharpOverflowException,
  SWIG_CSharpSystemException
} SWIG_CSharpExceptionCodes;

typedef enum {
  SWIG_CSharpArgumentException,
  SWIG_CSharpArgumentNullException,
  SWIG_CSharpArgumentOutOfRangeException
} SWIG_CSharpExceptionArgumentCodes;

typedef void (SWIGSTDCALL* SWIG_CSharpExceptionCallback_t)(const char *);
typedef void (SWIGSTDCALL* SWIG_CSharpExceptionArgumentCallback_t)(const char *, const char *);

typedef struct {
  SWIG_CSharpExceptionCodes code;
  SWIG_CSharpExceptionCallback_t callback;
} SWIG_CSharpException_t;

typedef struct {
  SWIG_CSharpExceptionArgumentCodes code;
  SWIG_CSharpExceptionArgumentCallback_t callback;
} SWIG_CSharpExceptionArgument_t;

static SWIG_CSharpException_t SWIG_csharp_exceptions[] = {
  { SWIG_CSharpApplicationException, NULL },
  { SWIG_CSharpArithmeticException, NULL },
  { SWIG_CSharpDivideByZeroException, NULL },
  { SWIG_CSharpIndexOutOfRangeException, NULL },
  { SWIG_CSharpInvalidCastException, NULL },
  { SWIG_CSharpInvalidOperationException, NULL },
  { SWIG_CSharpIOException, NULL },
  { SWIG_CSharpNullReferenceException, NULL },
  { SWIG_CSharpOutOfMemoryException, NULL },
  { SWIG_CSharpOverflowException, NULL },
  { SWIG_CSharpSystemException, NULL }
};

static SWIG_CSharpExceptionArgument_t SWIG_csharp_exceptions_argument[] = {
  { SWIG_CSharpArgumentException, NULL },
  { SWIG_CSharpArgumentNullException, NULL },
  { SWIG_CSharpArgumentOutOfRangeException, NULL }
};

static void SWIGUNUSED SWIG_CSharpSetPendingException(SWIG_CSharpExceptionCodes code, const char *msg) {
  SWIG_CSharpExceptionCallback_t callback = SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions)/sizeof(SWIG_CSharpException_t)) {
    callback = SWIG_csharp_exceptions[code].callback;
  }
  callback(msg);
}

static void SWIGUNUSED SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpExceptionArgumentCodes code, const char *msg, const char *param_name) {
  SWIG_CSharpExceptionArgumentCallback_t callback = SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback;
  if ((size_t)code < sizeof(SWIG_csharp_exceptions_argument)/sizeof(SWIG_CSharpExceptionArgument_t)) {
    callback = SWIG_csharp_exceptions_argument[code].callback;
  }
  callback(msg, param_name);
}


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionCallbacks_Core(
                                                SWIG_CSharpExceptionCallback_t applicationCallback,
                                                SWIG_CSharpExceptionCallback_t arithmeticCallback,
                                                SWIG_CSharpExceptionCallback_t divideByZeroCallback, 
                                                SWIG_CSharpExceptionCallback_t indexOutOfRangeCallback, 
                                                SWIG_CSharpExceptionCallback_t invalidCastCallback,
                                                SWIG_CSharpExceptionCallback_t invalidOperationCallback,
                                                SWIG_CSharpExceptionCallback_t ioCallback,
                                                SWIG_CSharpExceptionCallback_t nullReferenceCallback,
                                                SWIG_CSharpExceptionCallback_t outOfMemoryCallback, 
                                                SWIG_CSharpExceptionCallback_t overflowCallback, 
                                                SWIG_CSharpExceptionCallback_t systemCallback) {
  SWIG_csharp_exceptions[SWIG_CSharpApplicationException].callback = applicationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpArithmeticException].callback = arithmeticCallback;
  SWIG_csharp_exceptions[SWIG_CSharpDivideByZeroException].callback = divideByZeroCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIndexOutOfRangeException].callback = indexOutOfRangeCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidCastException].callback = invalidCastCallback;
  SWIG_csharp_exceptions[SWIG_CSharpInvalidOperationException].callback = invalidOperationCallback;
  SWIG_csharp_exceptions[SWIG_CSharpIOException].callback = ioCallback;
  SWIG_csharp_exceptions[SWIG_CSharpNullReferenceException].callback = nullReferenceCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOutOfMemoryException].callback = outOfMemoryCallback;
  SWIG_csharp_exceptions[SWIG_CSharpOverflowException].callback = overflowCallback;
  SWIG_csharp_exceptions[SWIG_CSharpSystemException].callback = systemCallback;
}

#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterExceptionArgumentCallbacks_Core(
                                                SWIG_CSharpExceptionArgumentCallback_t argumentCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentNullCallback,
                                                SWIG_CSharpExceptionArgumentCallback_t argumentOutOfRangeCallback) {
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentException].callback = argumentCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentNullException].callback = argumentNullCallback;
  SWIG_csharp_exceptions_argument[SWIG_CSharpArgumentOutOfRangeException].callback = argumentOutOfRangeCallback;
}


/* Callback for returning strings to C# without leaking memory */
typedef char * (SWIGSTDCALL* SWIG_CSharpStringHelperCallback)(const char *);
static SWIG_CSharpStringHelperCallback SWIG_csharp_string_callback = NULL;


#ifdef __cplusplus
extern "C" 
#endif
SWIGEXPORT void SWIGSTDCALL SWIGRegisterStringCallback_Core(SWIG_CSharpStringHelperCallback callback) {
  SWIG_csharp_string_callback = callback;
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, msg, ""); return nullreturn; } else

/* -----------------------------------------------------------------------------
 * director.swg
 *
 * This file contains support for director classes so that C# proxy 
 * methods can be called from C++.
 * ----------------------------------------------------------------------------- */

#ifdef __cplusplus

#if defined(DEBUG_DIRECTOR_OWNED)
#include <iostream>
#endif
#include <string>

namespace Swig {
  /* Director base class - not currently used in C# directors */
  class Director {
  };

  /* Base class for director exceptions */
  class DirectorException {
  protected:
    std::string swig_msg;

  public:
    DirectorException(const char* msg) : swig_msg(msg) {
    }
    DirectorException(const std::string &msg) : swig_msg(msg) {
    }
    const std::string& what() const {
      return swig_msg;
    }
    virtual ~DirectorException() {
    }
  };

  /* Pure virtual method exception */
  class DirectorPureVirtualException : public Swig::DirectorException {
  public:
    DirectorPureVirtualException(const char* msg) : DirectorException(std::string("Attempt to invoke pure virtual method ") + msg) {
    }
  };
}

#endif /* __cplusplus */



#include "OdeProxy.h"


#include <stdexcept>


#include <vector>
#include <algorithm>
#include <stdexcept>

SWIGINTERN std::vector< double > *new_std_vector_Sl_double_Sg___SWIG_2(int capacity){
        std::vector< double >* pv = 0;
        if (capacity >= 0) {
          pv = new std::vector< double >();
          pv->reserve(capacity);
       } else {
          throw std::out_of_range("capacity");
       }
       return pv;
      }
SWIGINTERN double std_vector_Sl_double_Sg__getitemcopy(std::vector< double > *self,int index){
        if (index>=0 && index<(int)self->size())
          return (*self)[index];
        else
          throw std::out_of_range("index");
      }
SWIGINTERN std::vector< double >::const_reference std_vector_Sl_double_Sg__getitem(std::vector< double > *self,int index){
        if (index>=0 && index<(int)self->size())
          return (*self)[index];
        else
          throw std::out_of_range("index");
      }
SWIGINTERN void std_vector_Sl_double_Sg__setitem(std::vector< double > *self,int index,double const &val){
        if (index>=0 && index<(int)self->size())
          (*self)[index] = val;
        else
          throw std::out_of_range("index");
      }
SWIGINTERN void std_vector_Sl_double_Sg__AddRange(std::vector< double > *self,std::vector< double > const &values){
        self->insert(self->end(), values.begin(), values.end());
      }
SWIGINTERN std::vector< double > *std_vector_Sl_double_Sg__GetRange(std::vector< double > *self,int index,int count){
        if (index < 0)
          throw std::out_of_range("index");
        if (count < 0)
          throw std::out_of_range("count");
        if (index >= (int)self->size()+1 || index+count > (int)self->size())
          throw std::invalid_argument("invalid range");
        return new std::vector< double >(self->begin()+index, self->begin()+index+count);
      }
SWIGINTERN void std_vector_Sl_double_Sg__Insert(std::vector< double > *self,int index,double const &x){
        if (index>=0 && index<(int)self->size()+1)
          self->insert(self->begin()+index, x);
        else
          throw std::out_of_range("index");
      }
SWIGINTERN void std_vector_Sl_double_Sg__InsertRange(std::vector< double > *self,int index,std::vector< double > const &values){
        if (index>=0 && index<(int)self->size()+1)
          self->insert(self->begin()+index, values.begin(), values.end());
        else
          throw std::out_of_range("index");
      }
SWIGINTERN void std_vector_Sl_double_Sg__RemoveAt(std::vector< double > *self,int index){
        if (index>=0 && index<(int)self->size())
          self->erase(self->begin() + index);
        else
          throw std::out_of_range("index");
      }
SWIGINTERN void std_vector_Sl_double_Sg__RemoveRange(std::vector< double > *self,int index,int count){
        if (index < 0)
          throw std::out_of_range("index");
        if (count < 0)
          throw std::out_of_range("count");
        if (index >= (int)self->size()+1 || index+count > (int)self->size())
          throw std::invalid_argument("invalid range");
        self->erase(self->begin()+index, self->begin()+index+count);
      }
SWIGINTERN std::vector< double > *std_vector_Sl_double_Sg__Repeat(double const &value,int count){
        if (count < 0)
          throw std::out_of_range("count");
        return new std::vector< double >(count, value);
      }
SWIGINTERN void std_vector_Sl_double_Sg__Reverse__SWIG_0(std::vector< double > *self){
        std::reverse(self->begin(), self->end());
      }
SWIGINTERN void std_vector_Sl_double_Sg__Reverse__SWIG_1(std::vector< double > *self,int index,int count){
        if (index < 0)
          throw std::out_of_range("index");
        if (count < 0)
          throw std::out_of_range("count");
        if (index >= (int)self->size()+1 || index+count > (int)self->size())
          throw std::invalid_argument("invalid range");
        std::reverse(self->begin()+index, self->begin()+index+count);
      }
SWIGINTERN void std_vector_Sl_double_Sg__SetRange(std::vector< double > *self,int index,std::vector< double > const &values){
        if (index < 0)
          throw std::out_of_range("index");
        if (index+values.size() > self->size())
          throw std::out_of_range("index");
        std::copy(values.begin(), values.end(), self->begin()+index);
      }
SWIGINTERN bool std_vector_Sl_double_Sg__Contains(std::vector< double > *self,double const &value){
        return std::find(self->begin(), self->end(), value) != self->end();
      }
SWIGINTERN int std_vector_Sl_double_Sg__IndexOf(std::vector< double > *self,double const &value){
        int index = -1;
        std::vector< double >::iterator it = std::find(self->begin(), self->end(), value);
        if (it != self->end())
          index = (int)(it - self->begin());
        return index;
      }
SWIGINTERN int std_vector_Sl_double_Sg__LastIndexOf(std::vector< double > *self,double const &value){
        int index = -1;
        std::vector< double >::reverse_iterator rit = std::find(self->rbegin(), self->rend(), value);
        if (rit != self->rend())
          index = (int)(self->rend() - 1 - rit);
        return index;
      }
SWIGINTERN bool std_vector_Sl_double_Sg__Remove(std::vector< double > *self,double const &value){
        std::vector< double >::iterator it = std::find(self->begin(), self->end(), value);
        if (it != self->end()) {
          self->erase(it);
	  return true;
        }
        return false;
      }


/* ---------------------------------------------------
 * C++ director class methods
 * --------------------------------------------------- */

#include "OdeProxyWrapper.h"

SwigDirector_Ode::SwigDirector_Ode() : OdeProxy::Ode(), Swig::Director() {
  swig_init_callbacks();
}

void SwigDirector_Ode::system(OdeProxy::StateType const &x, OdeProxy::StateType &dxdt, double t) {
  void * jx = 0 ;
  void * jdxdt = 0 ;
  double jt  ;
  
  if (!swig_callbacksystem) {
    OdeProxy::Ode::system(x,dxdt,t);
    return;
  } else {
    jx = (OdeProxy::StateType *) &x; 
    jdxdt = (OdeProxy::StateType *) &dxdt; 
    jt = t;
    swig_callbacksystem(jx, jdxdt, jt);
  }
}

void SwigDirector_Ode::observer(OdeProxy::StateType const &x, double t) {
  void * jx = 0 ;
  double jt  ;
  
  if (!swig_callbackobserver) {
    OdeProxy::Ode::observer(x,t);
    return;
  } else {
    jx = (OdeProxy::StateType *) &x; 
    jt = t;
    swig_callbackobserver(jx, jt);
  }
}

SwigDirector_Ode::~SwigDirector_Ode() {
  
}


void SwigDirector_Ode::swig_connect_director(SWIG_Callback0_t callbacksystem, SWIG_Callback1_t callbackobserver) {
  swig_callbacksystem = callbacksystem;
  swig_callbackobserver = callbackobserver;
}

void SwigDirector_Ode::swig_init_callbacks() {
  swig_callbacksystem = 0;
  swig_callbackobserver = 0;
}


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT void SWIGSTDCALL CSharp_StateType_Clear(void * jarg1) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  (arg1)->clear();
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_Add(void * jarg1, double jarg2) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  double *arg2 = 0 ;
  double temp2 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  temp2 = (double)jarg2; 
  arg2 = &temp2; 
  (arg1)->push_back((double const &)*arg2);
}


SWIGEXPORT unsigned long SWIGSTDCALL CSharp_StateType_size(void * jarg1) {
  unsigned long jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  std::vector< double >::size_type result;
  
  arg1 = (std::vector< double > *)jarg1; 
  result = ((std::vector< double > const *)arg1)->size();
  jresult = (unsigned long)result; 
  return jresult;
}


SWIGEXPORT unsigned long SWIGSTDCALL CSharp_StateType_capacity(void * jarg1) {
  unsigned long jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  std::vector< double >::size_type result;
  
  arg1 = (std::vector< double > *)jarg1; 
  result = ((std::vector< double > const *)arg1)->capacity();
  jresult = (unsigned long)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_reserve(void * jarg1, unsigned long jarg2) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  std::vector< double >::size_type arg2 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (std::vector< double >::size_type)jarg2; 
  (arg1)->reserve(arg2);
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_StateType__SWIG_0() {
  void * jresult ;
  std::vector< double > *result = 0 ;
  
  result = (std::vector< double > *)new std::vector< double >();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_StateType__SWIG_1(void * jarg1) {
  void * jresult ;
  std::vector< double > *arg1 = 0 ;
  std::vector< double > *result = 0 ;
  
  arg1 = (std::vector< double > *)jarg1;
  if (!arg1) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "std::vector< double > const & type is null", 0);
    return 0;
  } 
  result = (std::vector< double > *)new std::vector< double >((std::vector< double > const &)*arg1);
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_StateType__SWIG_2(int jarg1) {
  void * jresult ;
  int arg1 ;
  std::vector< double > *result = 0 ;
  
  arg1 = (int)jarg1; 
  try {
    result = (std::vector< double > *)new_std_vector_Sl_double_Sg___SWIG_2(arg1);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return 0;
  }
  
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT double SWIGSTDCALL CSharp_StateType_getitemcopy(void * jarg1, int jarg2) {
  double jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  double result;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  try {
    result = (double)std_vector_Sl_double_Sg__getitemcopy(arg1,arg2);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return 0;
  }
  
  jresult = result; 
  return jresult;
}


SWIGEXPORT double SWIGSTDCALL CSharp_StateType_getitem(void * jarg1, int jarg2) {
  double jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  double *result = 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  try {
    result = (double *) &std_vector_Sl_double_Sg__getitem(arg1,arg2);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return 0;
  }
  
  jresult = *result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_setitem(void * jarg1, int jarg2, double jarg3) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  double *arg3 = 0 ;
  double temp3 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  temp3 = (double)jarg3; 
  arg3 = &temp3; 
  try {
    std_vector_Sl_double_Sg__setitem(arg1,arg2,(double const &)*arg3);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return ;
  }
  
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_AddRange(void * jarg1, void * jarg2) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  std::vector< double > *arg2 = 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (std::vector< double > *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "std::vector< double > const & type is null", 0);
    return ;
  } 
  std_vector_Sl_double_Sg__AddRange(arg1,(std::vector< double > const &)*arg2);
}


SWIGEXPORT void * SWIGSTDCALL CSharp_StateType_GetRange(void * jarg1, int jarg2, int jarg3) {
  void * jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  int arg3 ;
  std::vector< double > *result = 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (int)jarg3; 
  try {
    result = (std::vector< double > *)std_vector_Sl_double_Sg__GetRange(arg1,arg2,arg3);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return 0;
  }
  catch(std::invalid_argument &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentException, (&_e)->what(), "");
    return 0;
  }
  
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_Insert(void * jarg1, int jarg2, double jarg3) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  double *arg3 = 0 ;
  double temp3 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  temp3 = (double)jarg3; 
  arg3 = &temp3; 
  try {
    std_vector_Sl_double_Sg__Insert(arg1,arg2,(double const &)*arg3);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return ;
  }
  
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_InsertRange(void * jarg1, int jarg2, void * jarg3) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  std::vector< double > *arg3 = 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (std::vector< double > *)jarg3;
  if (!arg3) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "std::vector< double > const & type is null", 0);
    return ;
  } 
  try {
    std_vector_Sl_double_Sg__InsertRange(arg1,arg2,(std::vector< double > const &)*arg3);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return ;
  }
  
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_RemoveAt(void * jarg1, int jarg2) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  try {
    std_vector_Sl_double_Sg__RemoveAt(arg1,arg2);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return ;
  }
  
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_RemoveRange(void * jarg1, int jarg2, int jarg3) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  int arg3 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (int)jarg3; 
  try {
    std_vector_Sl_double_Sg__RemoveRange(arg1,arg2,arg3);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return ;
  }
  catch(std::invalid_argument &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentException, (&_e)->what(), "");
    return ;
  }
  
}


SWIGEXPORT void * SWIGSTDCALL CSharp_StateType_Repeat(double jarg1, int jarg2) {
  void * jresult ;
  double *arg1 = 0 ;
  int arg2 ;
  double temp1 ;
  std::vector< double > *result = 0 ;
  
  temp1 = (double)jarg1; 
  arg1 = &temp1; 
  arg2 = (int)jarg2; 
  try {
    result = (std::vector< double > *)std_vector_Sl_double_Sg__Repeat((double const &)*arg1,arg2);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return 0;
  }
  
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_Reverse__SWIG_0(void * jarg1) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  std_vector_Sl_double_Sg__Reverse__SWIG_0(arg1);
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_Reverse__SWIG_1(void * jarg1, int jarg2, int jarg3) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  int arg3 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (int)jarg3; 
  try {
    std_vector_Sl_double_Sg__Reverse__SWIG_1(arg1,arg2,arg3);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return ;
  }
  catch(std::invalid_argument &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentException, (&_e)->what(), "");
    return ;
  }
  
}


SWIGEXPORT void SWIGSTDCALL CSharp_StateType_SetRange(void * jarg1, int jarg2, void * jarg3) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  int arg2 ;
  std::vector< double > *arg3 = 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (std::vector< double > *)jarg3;
  if (!arg3) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "std::vector< double > const & type is null", 0);
    return ;
  } 
  try {
    std_vector_Sl_double_Sg__SetRange(arg1,arg2,(std::vector< double > const &)*arg3);
  }
  catch(std::out_of_range &_e) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentOutOfRangeException, 0, (&_e)->what());
    return ;
  }
  
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_StateType_Contains(void * jarg1, double jarg2) {
  unsigned int jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  double *arg2 = 0 ;
  double temp2 ;
  bool result;
  
  arg1 = (std::vector< double > *)jarg1; 
  temp2 = (double)jarg2; 
  arg2 = &temp2; 
  result = (bool)std_vector_Sl_double_Sg__Contains(arg1,(double const &)*arg2);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_StateType_IndexOf(void * jarg1, double jarg2) {
  int jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  double *arg2 = 0 ;
  double temp2 ;
  int result;
  
  arg1 = (std::vector< double > *)jarg1; 
  temp2 = (double)jarg2; 
  arg2 = &temp2; 
  result = (int)std_vector_Sl_double_Sg__IndexOf(arg1,(double const &)*arg2);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_StateType_LastIndexOf(void * jarg1, double jarg2) {
  int jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  double *arg2 = 0 ;
  double temp2 ;
  int result;
  
  arg1 = (std::vector< double > *)jarg1; 
  temp2 = (double)jarg2; 
  arg2 = &temp2; 
  result = (int)std_vector_Sl_double_Sg__LastIndexOf(arg1,(double const &)*arg2);
  jresult = result; 
  return jresult;
}


SWIGEXPORT unsigned int SWIGSTDCALL CSharp_StateType_Remove(void * jarg1, double jarg2) {
  unsigned int jresult ;
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  double *arg2 = 0 ;
  double temp2 ;
  bool result;
  
  arg1 = (std::vector< double > *)jarg1; 
  temp2 = (double)jarg2; 
  arg2 = &temp2; 
  result = (bool)std_vector_Sl_double_Sg__Remove(arg1,(double const &)*arg2);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_StateType(void * jarg1) {
  std::vector< double > *arg1 = (std::vector< double > *) 0 ;
  
  arg1 = (std::vector< double > *)jarg1; 
  delete arg1;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Ode_system(void * jarg1, void * jarg2, void * jarg3, double jarg4) {
  OdeProxy::Ode *arg1 = (OdeProxy::Ode *) 0 ;
  OdeProxy::StateType *arg2 = 0 ;
  OdeProxy::StateType *arg3 = 0 ;
  double arg4 ;
  
  arg1 = (OdeProxy::Ode *)jarg1; 
  arg2 = (OdeProxy::StateType *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "OdeProxy::StateType const & type is null", 0);
    return ;
  } 
  arg3 = (OdeProxy::StateType *)jarg3;
  if (!arg3) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "OdeProxy::StateType & type is null", 0);
    return ;
  } 
  arg4 = (double)jarg4; 
  (arg1)->system((OdeProxy::StateType const &)*arg2,*arg3,arg4);
}


SWIGEXPORT void SWIGSTDCALL CSharp_Ode_systemSwigExplicitOde(void * jarg1, void * jarg2, void * jarg3, double jarg4) {
  OdeProxy::Ode *arg1 = (OdeProxy::Ode *) 0 ;
  OdeProxy::StateType *arg2 = 0 ;
  OdeProxy::StateType *arg3 = 0 ;
  double arg4 ;
  
  arg1 = (OdeProxy::Ode *)jarg1; 
  arg2 = (OdeProxy::StateType *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "OdeProxy::StateType const & type is null", 0);
    return ;
  } 
  arg3 = (OdeProxy::StateType *)jarg3;
  if (!arg3) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "OdeProxy::StateType & type is null", 0);
    return ;
  } 
  arg4 = (double)jarg4; 
  (arg1)->OdeProxy::Ode::system((OdeProxy::StateType const &)*arg2,*arg3,arg4);
}


SWIGEXPORT void SWIGSTDCALL CSharp_Ode_observer(void * jarg1, void * jarg2, double jarg3) {
  OdeProxy::Ode *arg1 = (OdeProxy::Ode *) 0 ;
  OdeProxy::StateType *arg2 = 0 ;
  double arg3 ;
  
  arg1 = (OdeProxy::Ode *)jarg1; 
  arg2 = (OdeProxy::StateType *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "OdeProxy::StateType const & type is null", 0);
    return ;
  } 
  arg3 = (double)jarg3; 
  (arg1)->observer((OdeProxy::StateType const &)*arg2,arg3);
}


SWIGEXPORT void SWIGSTDCALL CSharp_Ode_observerSwigExplicitOde(void * jarg1, void * jarg2, double jarg3) {
  OdeProxy::Ode *arg1 = (OdeProxy::Ode *) 0 ;
  OdeProxy::StateType *arg2 = 0 ;
  double arg3 ;
  
  arg1 = (OdeProxy::Ode *)jarg1; 
  arg2 = (OdeProxy::StateType *)jarg2;
  if (!arg2) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "OdeProxy::StateType const & type is null", 0);
    return ;
  } 
  arg3 = (double)jarg3; 
  (arg1)->OdeProxy::Ode::observer((OdeProxy::StateType const &)*arg2,arg3);
}


SWIGEXPORT void SWIGSTDCALL CSharp_Ode_InitialConditions_set(void * jarg1, void * jarg2) {
  OdeProxy::Ode *arg1 = (OdeProxy::Ode *) 0 ;
  OdeProxy::StateType *arg2 = (OdeProxy::StateType *) 0 ;
  
  arg1 = (OdeProxy::Ode *)jarg1; 
  arg2 = (OdeProxy::StateType *)jarg2; 
  if (arg1) (arg1)->InitialConditions = *arg2;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_Ode_InitialConditions_get(void * jarg1) {
  void * jresult ;
  OdeProxy::Ode *arg1 = (OdeProxy::Ode *) 0 ;
  OdeProxy::StateType *result = 0 ;
  
  arg1 = (OdeProxy::Ode *)jarg1; 
  result = (OdeProxy::StateType *)& ((arg1)->InitialConditions);
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Ode(void * jarg1) {
  OdeProxy::Ode *arg1 = (OdeProxy::Ode *) 0 ;
  
  arg1 = (OdeProxy::Ode *)jarg1; 
  delete arg1;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_Ode() {
  void * jresult ;
  OdeProxy::Ode *result = 0 ;
  
  result = (OdeProxy::Ode *)new SwigDirector_Ode();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_Ode_director_connect(void *objarg, SwigDirector_Ode::SWIG_Callback0_t callback0, SwigDirector_Ode::SWIG_Callback1_t callback1) {
  OdeProxy::Ode *obj = (OdeProxy::Ode *)objarg;
  SwigDirector_Ode *director = dynamic_cast<SwigDirector_Ode *>(obj);
  if (director) {
    director->swig_connect_director(callback0, callback1);
  }
}


SWIGEXPORT void SWIGSTDCALL CSharp_Solver_StepperCode_set(void * jarg1, int jarg2) {
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  OdeProxy::StepperTypeCode arg2 ;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  arg2 = (OdeProxy::StepperTypeCode)jarg2; 
  if (arg1) (arg1)->StepperCode = arg2;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Solver_StepperCode_get(void * jarg1) {
  int jresult ;
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  OdeProxy::StepperTypeCode result;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  result = (OdeProxy::StepperTypeCode) ((arg1)->StepperCode);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Solver_ConvenienceSolve(void * jarg1, void * jarg2, double jarg3, double jarg4, double jarg5) {
  int jresult ;
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  OdeProxy::Ode *arg2 = (OdeProxy::Ode *) 0 ;
  double arg3 ;
  double arg4 ;
  double arg5 ;
  int result;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  arg2 = (OdeProxy::Ode *)jarg2; 
  arg3 = (double)jarg3; 
  arg4 = (double)jarg4; 
  arg5 = (double)jarg5; 
  result = (int)(arg1)->ConvenienceSolve(arg2,arg3,arg4,arg5);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Solver_Solve__SWIG_0(void * jarg1, void * jarg2, double jarg3, double jarg4, double jarg5, int jarg6) {
  int jresult ;
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  OdeProxy::Ode *arg2 = (OdeProxy::Ode *) 0 ;
  double arg3 ;
  double arg4 ;
  double arg5 ;
  OdeProxy::IntegrateFunctionTypeCode arg6 ;
  int result;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  arg2 = (OdeProxy::Ode *)jarg2; 
  arg3 = (double)jarg3; 
  arg4 = (double)jarg4; 
  arg5 = (double)jarg5; 
  arg6 = (OdeProxy::IntegrateFunctionTypeCode)jarg6; 
  result = (int)(arg1)->Solve(arg2,arg3,arg4,arg5,arg6);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Solver_Solve__SWIG_1(void * jarg1, void * jarg2, double jarg3, double jarg4, double jarg5) {
  int jresult ;
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  OdeProxy::Ode *arg2 = (OdeProxy::Ode *) 0 ;
  double arg3 ;
  double arg4 ;
  double arg5 ;
  int result;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  arg2 = (OdeProxy::Ode *)jarg2; 
  arg3 = (double)jarg3; 
  arg4 = (double)jarg4; 
  arg5 = (double)jarg5; 
  result = (int)(arg1)->Solve(arg2,arg3,arg4,arg5);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Solver_Solve__SWIG_2(void * jarg1, void * jarg2, double jarg3, double jarg4, int jarg5) {
  int jresult ;
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  OdeProxy::Ode *arg2 = (OdeProxy::Ode *) 0 ;
  double arg3 ;
  double arg4 ;
  int arg5 ;
  int result;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  arg2 = (OdeProxy::Ode *)jarg2; 
  arg3 = (double)jarg3; 
  arg4 = (double)jarg4; 
  arg5 = (int)jarg5; 
  result = (int)(arg1)->Solve(arg2,arg3,arg4,arg5);
  jresult = result; 
  return jresult;
}


SWIGEXPORT int SWIGSTDCALL CSharp_Solver_Solve__SWIG_3(void * jarg1, void * jarg2, void * jarg3, double jarg4) {
  int jresult ;
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  OdeProxy::Ode *arg2 = (OdeProxy::Ode *) 0 ;
  OdeProxy::StateType *arg3 = 0 ;
  double arg4 ;
  int result;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  arg2 = (OdeProxy::Ode *)jarg2; 
  arg3 = (OdeProxy::StateType *)jarg3;
  if (!arg3) {
    SWIG_CSharpSetPendingExceptionArgument(SWIG_CSharpArgumentNullException, "OdeProxy::StateType & type is null", 0);
    return 0;
  } 
  arg4 = (double)jarg4; 
  result = (int)(arg1)->Solve(arg2,*arg3,arg4);
  jresult = result; 
  return jresult;
}


SWIGEXPORT void * SWIGSTDCALL CSharp_new_Solver() {
  void * jresult ;
  OdeProxy::Solver *result = 0 ;
  
  result = (OdeProxy::Solver *)new OdeProxy::Solver();
  jresult = (void *)result; 
  return jresult;
}


SWIGEXPORT void SWIGSTDCALL CSharp_delete_Solver(void * jarg1) {
  OdeProxy::Solver *arg1 = (OdeProxy::Solver *) 0 ;
  
  arg1 = (OdeProxy::Solver *)jarg1; 
  delete arg1;
}


#ifdef __cplusplus
}
#endif

