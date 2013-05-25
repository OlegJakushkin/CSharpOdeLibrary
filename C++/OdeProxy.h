#ifndef ODEPROXY_H
#define ODEPROXY_H

#include <iostream>
#include <vector>

namespace OdeProxy {

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
        int Solve(Ode * ode);
    };
}


#endif // ODEPROXY_H