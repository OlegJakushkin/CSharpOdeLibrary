#ifndef ODEPROXY_H
#define ODEPROXY_H

#include <iostream>
#include <vector>

namespace OdeProxy {

	enum IntegrateFunctionTypeCode {
		Adaptive,
		Const
	};

	enum GenerationFunctionTypeCode {
		None,
		Dense,
		Controlled
	};

	enum StepperTypeCode {
		RungeKuttaDopri5,
		Euler,
		ModifiedMidpoint,
		RungeKutta4,
		RungeKuttaCashKarp54,
		RungeKuttaFehlberg78,
		ControlledRungeKutta,
		BulirschStoer,
		BulirschStoerDenseOut
	};

	typedef std::vector< double > StateType;

	class Ode {
	public:
		virtual void system( const StateType &x , StateType &dxdt , double t );
		virtual void observer( const StateType &x , double t );
		StateType InitialConditions;
		virtual ~Ode(){}
	};

	class Solver {
	public:
		StepperTypeCode StepperCode;

		int ConvenienceSolve(Ode * od, double from, double step, double to);

		int Solve(Ode * ode, double from, double step, double to, IntegrateFunctionTypeCode integrateFunctionTypeCode = IntegrateFunctionTypeCode::Adaptive);
		int Solve(Ode * ode, double from, double step, int stepsCount);
		int Solve(Ode * ode, StateType & timePoints, double step);
	};
}

#endif // ODEPROXY_H