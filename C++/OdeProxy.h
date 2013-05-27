#ifndef ODEPROXY_H
#define ODEPROXY_H

#include <iostream>
#include <vector>

namespace OdeProxy {


	enum IntegrateFunction {
		IntegrateFunction_Default,
		Const,
		N_Steps,
		Adaptive,
		//Times,
	};

	enum Stepper {
		Stepper_Default,
		Euler,
		Modified_Midpoint,
		Runge_Kutta4,
		Runge_Kutta_Cash_Karp54,
		Runge_Kutta_Dopri5,
		Runge_Kutta_Fehlberg78,
		//Adams_Bashforth,
		//Adams_Moulton,
		//Adams_Bashforth_Moulton,
		Controlled_Runge_Kutta,
		//Dense_Output_Runge_Kutta,
		Bulirsch_Stoer,
		Bulirsch_Stoer_Dense_Out,
		//Implicit_Euler,
		//Rosenbrock4,
		//Rosenbrock4_Controller,
		//Rosenbrock4_Dense_Output,
		//Symplectic_Euler,
		//Symplectic_rkn_sb3a_Mclachlan,
		//Symplectic_rkn_sb3a_m4_Mclachlan
	};

    typedef std::vector< double > state_type;

    class Ode {
    public:
		virtual void system( const state_type &x , state_type &dxdt , double t );
		virtual void observer( const state_type &x , double t );
        state_type initialConditions;
        double from;
        double to;
        double step;
		virtual ~Ode(){}
    };

    class Solver {
    public:
        int Solve(Ode * ode, IntegrateFunction integrateFunction = IntegrateFunction::IntegrateFunction_Default, Stepper stepper = Stepper::Stepper_Default);
    };
}


#endif // ODEPROXY_H