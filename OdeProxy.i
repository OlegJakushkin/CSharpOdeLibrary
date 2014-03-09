/* command 
swig.exe -c++ -csharp -namespace OdeLibrary -outdir ./C#/ -o ./C++/OdeProxyWrapper.cxx OdeProxy.i
*/

%include "std_complex.i"
%include "std_vector.i"

%{
#include "OdeProxy.h"
%}
%include "C++/OdeProxy.h"

%module(directors="1") Core

%feature("director") OdeProxy::OdeTemplate<double>;
%template(StateType) std::vector<double>;
%template(Ode) OdeProxy::OdeTemplate<double>;
%template(Solver) OdeProxy::SolverTemplate<double>;

%feature("director") OdeProxy::OdeTemplate<Complex>;
%template(ComplexStateType) std::vector<Complex >;
%template(ComplexOde) OdeProxy::OdeTemplate<Complex>;
%template(ComplexSolver) OdeProxy::SolverTemplate<Complex>;



