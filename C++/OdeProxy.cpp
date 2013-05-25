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

int OdeProxy::Solver::Solve(OdeProxy::Ode * ode) {
    using namespace boost::numeric::odeint;

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