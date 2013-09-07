/* command 
swig.exe -c++ -csharp -namespace OdeLibrary -outdir ./C#/ -o ./C++/OdeProxyWrapper.cxx OdeProxy.i
*/

%{
#include "OdeProxy.h"
%}

%module(directors="1") Core

%include "std_vector.i"

%template(StateType) std::vector<double>;

%include "C++/OdeProxy.h"

%feature("director") OdeProxy::OdeTemplate<double>;


%template(Ode) OdeProxy::OdeTemplate<double>;
%template(Solver) OdeProxy::SolverTemplate<double>;

%feature("director") OdeProxy::OdeTemplate<double>;

