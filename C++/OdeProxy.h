#ifndef ODEPROXY_H
#define ODEPROXY_H

#include <iostream>
#include <complex>
#include <vector>

#include "Preprocessor.h"

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

	template <class T>
	class OdeTemplate {
	  public:
		typedef std::vector<T> StateType;

		virtual void system(const StateType &x, StateType &dxdt, double t);
		virtual void observer(const StateType &x, double t);
		StateType InitialConditions;
		virtual ~OdeTemplate() {}

		#ifndef SWIG
		// Ode<double>
		PP_Ode_Specialization(double)
		#endif
	};

	template <class T>
	class SolverTemplate {
	  public:
		typedef std::vector<T> StateType;

		StepperTypeCode StepperCode;

		int ConvenienceSolve(OdeTemplate<T> *od, T from, T step, T to);

		int Solve(OdeTemplate<T> *ode, T from, T step, T to,
				  IntegrateFunctionTypeCode integrateFunctionTypeCode = IntegrateFunctionTypeCode::Adaptive);
		int Solve(OdeTemplate<T> *ode, T from, T step, int stepsCount);
		int Solve(OdeTemplate<T> *ode, std::vector<double> &timePoints, T step);

		#ifndef SWIG
		// Solver<double>
		PP_Solver_Specialization(double)
		#endif
	};
};

#endif // ODEPROXY_H