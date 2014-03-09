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

		StateType InitialConditions;
		virtual ~OdeTemplate() {}

		virtual void system(const StateType &x, StateType &dxdt, double t);
		virtual void observer(const StateType &x, double t);
	};

	template <class T>
	class SolverTemplate {
	  public:
		typedef std::vector<T> StateType;

		StepperTypeCode StepperCode;

		int ConvenienceSolve(OdeTemplate<T> *od, double from, double step, double to);

		int Solve(OdeTemplate<T> *ode, double from, double step, double to,
				  IntegrateFunctionTypeCode integrateFunctionTypeCode = IntegrateFunctionTypeCode::Adaptive);
		int Solve(OdeTemplate<T> *ode, double from, double step, int stepsCount);
		int Solve(OdeTemplate<T> *ode, std::vector<double> &timePoints, double step);
	};
}

#ifndef SWIG
	PP_Ode_Specialization(double)
	PP_Ode_Specialization(std::complex<double>)

	PP_Solver_Specialization(double)
	PP_Solver_Specialization(std::complex<double>)
#endif

#endif // ODEPROXY_H