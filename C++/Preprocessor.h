#define PP_Ode_Specialization(TypeName) \
	template <> \
	void OdeTemplate<TypeName>::system(const std::vector<TypeName> &x, std::vector<TypeName> &dxdt, double t); \
	template <> \
	void OdeTemplate<TypeName>::observer(const std::vector<TypeName> &x, double t);

#define PP_Solver_Specialization(TypeName) \
	template <> \
	int SolverTemplate<TypeName>::ConvenienceSolve(OdeTemplate<TypeName> *od, TypeName from, TypeName step, TypeName to); \
	template <> \
	int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, TypeName from, TypeName step, TypeName to, \
	IntegrateFunctionTypeCode integrateFunctionTypeCode); \
	template <> \
	int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, TypeName from, TypeName step, int stepsCount); \
	template <> \
	int SolverTemplate<TypeName>::Solve(OdeTemplate<TypeName> *ode, std::vector<double> &timePoints, TypeName step); 

