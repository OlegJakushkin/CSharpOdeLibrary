/* command 
swig.exe -c++ -csharp -namespace OdeLibrary -outdir ./C#/ -o ./C++/OdeProxyWrapper.cxx OdeProxy.i
*/

%module(directors="1") Core

%{
#include "C++/OdeProxy.h"
%}

%include "std_vector.i"

%template(StateType) std::vector<double>;

%feature("director") OdeProxy::Ode;

%include "C++/OdeProxy.h"
