#include "OdeProxy.h"
#include <boost/bind.hpp>
#include <boost/numeric/odeint.hpp>

void OdeProxy::Ode::system( const state_type &x , state_type &dxdt , double t)
{
	std::cout<< "native system" << std::endl;
}

void OdeProxy::Ode::observer(const state_type &x , double t)
{
	std::cout<< "native system" << std::endl;
}

using namespace OdeProxy;

template<class Stepper> size_t integrate(Ode * ode, IntegrateFunction integrateFunction, const Stepper & stepper) {
	using namespace boost::numeric::odeint;
	boost::function<void (const state_type &x , state_type &dxdt , double t)> action = boost::bind(&Ode::system, ode, _1, _2, _3);

	switch(integrateFunction) {
	case IntegrateFunction::Adaptive :
	case IntegrateFunction::IntegrateFunction_Default:
		return integrate_adaptive(
			stepper,
			action,
			ode->initialConditions,
			ode->from,
			ode->to, 
			ode->step,
			boost::bind(&Ode::observer, ode, _1, _2)
			);
		break;
	case IntegrateFunction::Const :
		return integrate_const(
			stepper,
			action,
			ode->initialConditions,
			ode->from,
			ode->to, 
			ode->step,
			boost::bind(&Ode::observer, ode, _1, _2)
			);
		break;
	case IntegrateFunction::N_Steps :
		return integrate_n_steps(
			stepper,
			action,
			ode->initialConditions,
			ode->from,
			ode->to, 
			ode->step,
			boost::bind(&Ode::observer, ode, _1, _2)
			);
		break;
	//case IntegrateFunction::Times :
	//	return integrate_times(
	//		stepper,
	//		action,
	//		ode->initialConditions,
	//		ode->from,
	//		ode->to, 
	//		ode->step,
	//		boost::bind(&Ode::observer, ode, _1, _2)
	//		);
	//	break;
	}
	return 0;
}

int OdeProxy::Solver::Solve(Ode * ode, IntegrateFunction integrateFunction, Stepper stepperType) {
	using namespace boost::numeric::odeint;
	try {
	//OdeInt default integrate function uses a stepper not presented in steppers collection.
	if((integrateFunction == IntegrateFunction::IntegrateFunction_Default) && (stepperType == Stepper::Stepper_Default)) {
		boost::function<void (const state_type &x , state_type &dxdt , double t)> action = boost::bind(&Ode::system, ode, _1, _2, _3);
		return integrate(
			action,
			ode->initialConditions,
			ode->from,
			ode->to, 
			ode->step,
			boost::bind(&Ode::observer, ode, _1, _2)
			);
	}

	//OdeInt euler stepper is does not work with any integration function but N_Steps.
	if((integrateFunction != IntegrateFunction::N_Steps) && (stepperType == Stepper::Euler)) {
		return 0;
	}
	

	switch(stepperType) {
		// We could not make next steppers portable:
		//case Stepper::Adams_Bashforth:
		//return integrate(ode, integrateFunction, adams_bashforth<state_type>())
		//break;
		//case Stepper::Adams_Bashforth_Moulton:
		//return integrate(ode, integrateFunction, adams_bashforth_moulton<state_type>())
		//break;
		//case Stepper::Adams_Moulton:
		//return integrate(ode, integrateFunction, adams_moulton<state_type>())
		//break;
		//case Stepper::Dense_Output_Runge_Kutta:
		//	return integrate(ode, integrateFunction, dense_output_runge_kutta<state_type>());
		//break;
		//case Stepper::Rosenbrock4_Controller:
		//	return integrate(ode, integrateFunction, rosenbrock4_controller<state_type>());
		//break;
		//case Stepper::Rosenbrock4_Dense_Output:
		//return integrate(ode, integrateFunction, rosenbrock4_dense_output<state_type>());
		//break;
		//case Stepper::Symplectic_rkn_sb3a_m4_Mclachlan:
		//return integrate(ode, integrateFunction, symplectic_rkn_sb3a_m4_mclachlan<state_type>());
		//break;
		//case Stepper::Implicit_Euler:
		//	return integrate(ode, integrateFunction, implicit_euler<double>()); //TODO
		//	break;
		//case Stepper::Rosenbrock4:
		//	return integrate(ode, integrateFunction, rosenbrock4<state_type>());
		//	break;
		//case Stepper::Symplectic_rkn_sb3a_Mclachlan:
		//	return integrate(ode, integrateFunction, symplectic_rkn_sb3a_mclachlan<state_type>());
		//	break;
		//	case Stepper::Symplectic_Euler:
		//		return integrate(ode, integrateFunction, symplectic_euler<state_type>());
		//		break;
	case Stepper::Bulirsch_Stoer:
		return integrate(ode, integrateFunction, bulirsch_stoer<state_type>());
		break;
	case Stepper::Bulirsch_Stoer_Dense_Out:
		return integrate(ode, integrateFunction, bulirsch_stoer_dense_out<state_type>());
		break;
	case Stepper::Controlled_Runge_Kutta:
		return integrate(ode, integrateFunction, bulirsch_stoer_dense_out<state_type>());
		break;
	case Stepper::Euler:
		return integrate(ode, integrateFunction, euler<state_type>());
		break;
	case Stepper::Modified_Midpoint:
		return integrate(ode, integrateFunction, modified_midpoint<state_type>());
		break;
	case Stepper::Runge_Kutta4:
		return integrate(ode, integrateFunction, runge_kutta4<state_type>());
		break;
	case Stepper::Runge_Kutta_Cash_Karp54:
		return integrate(ode, integrateFunction, runge_kutta4<state_type>());
		break;
	case Stepper::Runge_Kutta_Dopri5:
	case Stepper::Stepper_Default :
		return integrate(ode, integrateFunction, runge_kutta_dopri5<state_type>());
		break;
	case Stepper::Runge_Kutta_Fehlberg78:
		return integrate(ode, integrateFunction, runge_kutta_fehlberg78<state_type>());
		break;
	}
	} catch(...) {
		return 0;
	}
}