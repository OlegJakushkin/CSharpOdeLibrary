#include <boost/bind.hpp>
#include <boost/numeric/odeint.hpp>

#include "OdeProxy.h"
#include "Utilities.h"

using namespace std;
using namespace OdeProxy;

#define PP_Ode_Specialization_Implementation(TypeName) \
template <> \
void OdeTemplate<TypeName>::system(const vector<TypeName> &x, vector<TypeName> &dxdt, double t) { \
    cout << "native system" << endl; \
} \
template <> \
void OdeTemplate<double>::observer(const vector<TypeName> &x, double t) { \
	cout << "native system" << endl; \
}

#define PP_Solver_Specialization_Implementation(TypeName) \
template <> \
int SolverTemplate<TypeName>::ConvenienceSolve(OdeTemplate<TypeName> *ode, TypeName from, TypeName step, TypeName to) { \
    using namespace boost::numeric::odeint; \
	\
    boost::function<void(const vector<TypeName> & x, vector<TypeName> & dxdt, double t)> action = \
        boost::bind(&OdeTemplate<TypeName>::system, ode, _1, _2, _3); \
    return integrate( \
        action, ode->InitialConditions, from, to, step, boost::bind(&OdeTemplate<TypeName>::observer, ode, _1, _2)); \
} \
template <> \
int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, \
                                  TypeName from, \
                                  TypeName step, \
                                  TypeName to, \
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
int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, TypeName from, TypeName step, int stepsCount) { \
    IntegrateCountedSteps<TypeName> integrate; \
    integrate.From = from; \
    integrate.Step = step; \
    integrate.StepsCount = stepsCount; \
    SelectStepper<TypeName> stepper; \
    return stepper(ode, StepperCode, integrate); \
} \
int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, StateType &timePoints, TypeName step) { \
    IntegrateTimed<TypeName> integrate(timePoints); \
    integrate.Step = step; \
    SelectStepper<TypeName> steper; \
    return steper(ode, StepperCode, integrate); \
}

PP_Ode_Specialization_Implementation(double)
PP_Solver_Specialization_Implementation(double)

