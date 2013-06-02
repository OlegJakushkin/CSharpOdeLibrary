#include "OdeProxy.h"
#include <boost/bind.hpp>
#include <boost/numeric/odeint.hpp>

void OdeProxy::Ode::system( const StateType &x , StateType &dxdt , double t)
{
	std::cout<< "native system" << std::endl;
}

void OdeProxy::Ode::observer(const StateType &x , double t)
{
	std::cout<< "native system" << std::endl;
}

using namespace OdeProxy;

struct IntegrateAdaptiveConst
{
	IntegrateFunctionTypeCode integrateFunction;
	double From;
	double Step;
	double To;

	template<class Stepper>
	size_t operator()(Ode * ode, const Stepper & stepper) {
		using namespace boost::numeric::odeint;
		boost::function<void (const StateType &x , StateType &dxdt , double t)> action = boost::bind(&Ode::system, ode, _1, _2, _3);

		switch(integrateFunction) {
		case IntegrateFunctionTypeCode::Adaptive :
			return integrate_adaptive(
				stepper,
				action,
				ode->InitialConditions,
				From,
				To, 
				Step,
				boost::bind(&Ode::observer, ode, _1, _2)
				);
			break;
		case IntegrateFunctionTypeCode::Const :
			return integrate_const(
				stepper,
				action,
				ode->InitialConditions,
				From,
				To, 
				Step,
				boost::bind(&Ode::observer, ode, _1, _2)
				);
			break;
		}
	}
};

struct IntegrateCountedSteps
{
	int StepsCount;
	double From;
	double Step;

	template<class Stepper>
	size_t operator()(Ode * ode, const Stepper & stepper) {
		using namespace boost::numeric::odeint;
		boost::function<void (const StateType &x , StateType &dxdt , double t)> action = boost::bind(&Ode::system, ode, _1, _2, _3);

		return integrate_n_steps(
			stepper,
			action,
			ode->InitialConditions,
			From,
			Step,
			StepsCount,
			boost::bind(&Ode::observer, ode, _1, _2)
		);
	}
};

struct IntegrateTimed
{
	double Step;
	OdeProxy::StateType & TimePoints;
	IntegrateTimed(StateType & timePoints) : TimePoints(timePoints){}

	template<class Stepper>
	size_t operator()(Ode * ode, const Stepper & stepper) {
		using namespace boost::numeric::odeint;
		boost::function<void (const StateType &x , StateType &dxdt , double t)> action = boost::bind(&Ode::system, ode, _1, _2, _3);

		return integrate_times(
			stepper,
			action,
			ode->InitialConditions,
			TimePoints.begin(),
			TimePoints.end(), 
			Step,
			boost::bind(&Ode::observer, ode, _1, _2)
		);
	}
};

struct SelectStepper
{
	template<class IntegrateFunctor>
	size_t operator()(Ode * ode, StepperTypeCode & stepperType, IntegrateFunctor & integrate) {
		using namespace boost::numeric::odeint;
		try {
			switch(stepperType) {
			case StepperTypeCode::BulirschStoer:
				return integrate(ode, bulirsch_stoer<StateType>());
				break;
			case StepperTypeCode::BulirschStoerDenseOut:
				return integrate(ode, bulirsch_stoer_dense_out<StateType>());
				break;
			case StepperTypeCode::ControlledRungeKutta:
				return integrate(ode, bulirsch_stoer_dense_out<StateType>());
				break;
			case StepperTypeCode::Euler:
				return integrate(ode, euler<StateType>());
				break;
			case StepperTypeCode::ModifiedMidpoint:
				return integrate(ode, modified_midpoint<StateType>());
				break;
			case StepperTypeCode::RungeKutta4:
				return integrate(ode, runge_kutta4<StateType>());
				break;
			case StepperTypeCode::RungeKuttaCashKarp54:
				return integrate(ode, runge_kutta4<StateType>());
				break;
			case StepperTypeCode::RungeKuttaDopri5:
				return integrate(ode, runge_kutta_dopri5<StateType>());
				break;
			case StepperTypeCode::RungeKuttaFehlberg78:
				return integrate(ode, runge_kutta_fehlberg78<StateType>());
				break;
			}
		} catch(...) {
			return 0;
		}
	}
};

int OdeProxy::Solver::ConvenienceSolve(Ode * ode, double from, double step, double to) {
	using namespace boost::numeric::odeint;

		boost::function<void (const StateType &x , StateType &dxdt , double t)> action = boost::bind(&Ode::system, ode, _1, _2, _3);
		return integrate(
			action,
			ode->InitialConditions,
			from,
			to, 
			step,
			boost::bind(&Ode::observer, ode, _1, _2)
			);
}

int OdeProxy::Solver::Solve(Ode * ode, double from, double step, double to, IntegrateFunctionTypeCode integrateFunctionTypeCode ) {
	IntegrateAdaptiveConst integrate;
	integrate.From = from;
	integrate.Step = step;
	integrate.To = to;
	integrate.integrateFunction = integrateFunctionTypeCode;

	SelectStepper stepper;
	return stepper(ode, StepperCode, integrate);
}

int OdeProxy::Solver::Solve(Ode * ode, double from, double step, int stepsCount) {
	IntegrateCountedSteps integrate;
	integrate.From = from;
	integrate.Step = step;
	integrate.StepsCount = stepsCount;
	SelectStepper stepper;
	return stepper(ode, StepperCode, integrate);
}

int OdeProxy::Solver::Solve(Ode * ode, StateType & timePoints, double step) {
	IntegrateTimed integrate(timePoints);
	integrate.Step = step;
	SelectStepper steper;
	return steper(ode, StepperCode, integrate);
}