#ifndef UTILITIES_H
#define UTILITIES_H

#include "OdeProxy.h"
using namespace OdeProxy;


template<class T>
struct IntegrateCountedSteps
{
	typedef std::vector< T > StateType;

	int StepsCount;
	double From;
	double Step;

	template<class Stepper>
	size_t operator()(OdeTemplate<T> * ode, const Stepper & stepper) {
		using namespace boost::numeric::odeint;
		boost::function<void (const StateType &x , StateType &dxdt , double t)> action = boost::bind(&OdeTemplate<T>::system, ode, _1, _2, _3);

		return integrate_n_steps(
			stepper,
			action,
			ode->InitialConditions,
			From,
			Step,
			StepsCount,
			boost::bind(&OdeTemplate<T>::observer, ode, _1, _2)
			);
	}
};

template<class T>
struct IntegrateTimed
{
	typedef std::vector< T > StateType;

	double Step;
	std::vector<double> & TimePoints;
	IntegrateTimed(std::vector<double> & timePoints) : TimePoints(timePoints){}

	template<class Stepper>
	size_t operator()(OdeTemplate<T> * ode, const Stepper & stepper) {
		using namespace boost::numeric::odeint;
		boost::function<void (const StateType &x , StateType &dxdt , double t)> action = boost::bind(&OdeTemplate<T>::system, ode, _1, _2, _3);

		return integrate_times(
			stepper,
			action,
			ode->InitialConditions,
			TimePoints.begin(),
			TimePoints.end(), 
			Step,
			boost::bind(&OdeTemplate<T>::observer, ode, _1, _2)
			);
	}
};

template<class T>
struct SelectStepper
{
	typedef std::vector< T > StateType;

	template<class IntegrateFunctor>
	size_t operator()(OdeTemplate<T> * ode, StepperTypeCode & stepperType, IntegrateFunctor & integrate) {
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

template<class T>
struct IntegrateAdaptiveConst
{
	typedef std::vector< T > StateType;

	IntegrateFunctionTypeCode integrateFunction;
	double From;
	double Step;
	double To;

	template<class Stepper>
	size_t operator()(OdeTemplate<T> * ode, const Stepper & stepper) {
		using namespace boost::numeric::odeint;
		boost::function<void (const StateType &x , StateType &dxdt , double t)> action = boost::bind(&OdeTemplate<T>::system, ode, _1, _2, _3);

		switch(integrateFunction) {
		case IntegrateFunctionTypeCode::Adaptive :
			return integrate_adaptive(
				stepper,
				action,
				ode->InitialConditions,
				From,
				To, 
				Step,
				boost::bind(&OdeTemplate<T>::observer, ode, _1, _2)
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
				boost::bind(&OdeTemplate<T>::observer, ode, _1, _2)
				);
			break;
		}
	}
};

#endif //UTILITIES_H