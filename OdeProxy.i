/* command 
swig.exe swig -c++ -csharp -namespace OdeLibrary -outdir ./C#/ -o ./C++/OdeProxyWrapper.cxx OdeProxy.i
*/

%module(directors="1") Core

%{
#include "C++/OdeProxy.h"
%}

%include "std_string.i"
%include "std_vector.i"

%template(state_type) std::vector<double>;

%feature("director") OdeProxy::Ode;

%include "C++/OdeProxy.h"
