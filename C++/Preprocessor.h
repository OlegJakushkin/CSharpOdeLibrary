#define PP_Ode_Specialization(TypeName) \
	template <> \
	void OdeProxy::OdeTemplate<TypeName>::system(const std::vector<TypeName> &x, std::vector<TypeName> &dxdt, double t); \
	template <> \
	void OdeProxy::OdeTemplate<TypeName>::observer(const std::vector<TypeName> &x, double t);

#define PP_Solver_Specialization(TypeName) \
	template <> \
	int OdeProxy::SolverTemplate<TypeName>::ConvenienceSolve(OdeProxy::OdeTemplate<TypeName> *od, double from, double step, double to); \
	template <> \
	int OdeProxy::SolverTemplate<TypeName>::Solve(OdeProxy::OdeTemplate<TypeName> *ode, double from, double step, double to, \
	OdeProxy::IntegrateFunctionTypeCode integrateFunctionTypeCode); \
	template <> \
	int OdeProxy::SolverTemplate<TypeName>::Solve(OdeProxy::OdeTemplate<TypeName> *ode, double from, double step, int stepsCount); \
	template <> \
	int OdeProxy::SolverTemplate<TypeName>::Solve(OdeProxy::OdeTemplate<TypeName> *ode, std::vector<double> &timePoints, double step); 

