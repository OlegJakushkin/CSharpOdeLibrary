#include <boost/bind.hpp>
#include <boost/numeric/odeint.hpp>

#include "OdeProxy.h"
#include "Utilities.h"

using namespace std;
using namespace OdeProxy;
typedef std::complex<double> complexNumber;


#define PP_Ode_Specialization_Implementation(TypeName) \
template <> \
void OdeTemplate<TypeName>::system(const vector<TypeName> &x, vector<TypeName> &dxdt, double t) { \
    cout << "native system" << endl; \
} \
template <> \
void OdeTemplate<TypeName>::observer(const vector<TypeName> &x, double t) { \
	cout << "native system" << endl; \
}

#define PP_Solver_Specialization_Implementation(TypeName) \
template <> \
int SolverTemplate<TypeName>::ConvenienceSolve(OdeTemplate<TypeName> *ode, double from, double step, double to) { \
    using namespace boost::numeric::odeint; \
	\
    boost::function<void(const vector<TypeName> & x, vector<TypeName> & dxdt, double t)> action = \
        boost::bind(&OdeTemplate<TypeName>::system, ode, _1, _2, _3); \
    return integrate( \
        action, ode->InitialConditions, from, to, step, boost::bind(&OdeTemplate<TypeName>::observer, ode, _1, _2)); \
} \
template <> \
int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, \
                                  double from, \
                                  double step, \
                                  double to, \
                                  IntegrateFunctionTypeCode integrateFunctionTypeCode) { \
    IntegrateAdaptiveConst<TypeName> integrate; \
    integrate.From = from; \
    integrate.Step = step; \
    integrate.To = to; \
    integrate.integrateFunction = integrateFunctionTypeCode; \
    SelectStepper<TypeName> stepper; \
    return stepper(ode, StepperCode, integrate); \
} \
template <> \
int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, double from, double step, int stepsCount) { \
    IntegrateCountedSteps<TypeName> integrate; \
    integrate.From = from; \
    integrate.Step = step; \
    integrate.StepsCount = stepsCount; \
    SelectStepper<TypeName> stepper; \
    return stepper(ode, StepperCode, integrate); \
} \
int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, vector<double> &timePoints, double step) { \
    IntegrateTimed<TypeName> integrate(timePoints); \
    integrate.Step = step; \
    SelectStepper<TypeName> steper; \
    return steper(ode, StepperCode, integrate); \
}

PP_Ode_Specialization_Implementation(double)
PP_Solver_Specialization_Implementation(double)

PP_Ode_Specialization_Implementation(complexNumber)
PP_Solver_Specialization_Implementation(complexNumber)