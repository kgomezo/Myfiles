#include <iostream>
#include <fstream>

#ifndef __INTEGRATION_H_
#define __INTEGRATION_H_

template<typename system_t, typename state_t>
void euler(system_t deriv, state_t & data, double t, double h)
{
    state_t dydt(data.size());
    deriv(data, dydt, t);

    for(int ii = 0; ii < data.size(); ++ii) {
        data[ii] = data[ii] + h*dydt[ii];
    }
}

template<typename system_t, typename state_t>
    void rk4(system_t deriv, state_t & data, double t, double h)
{
    state_t dydt(data.size());
    state_t k1(data.size()), k2(data.size()),
        k3(data.size()), k4(data.size()), aux(data.size());

    // k1
    deriv(data, dydt, t);
    for(int ii = 0; ii < data.size(); ++ii) {
        k1[ii] = h*dydt[ii];
    }
    // k2 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k1[ii]/2;
    }
    // k2
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k2[ii] = h*dydt[ii];
    }
    // k3 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k2[ii]/2;
    }
    // k3
    deriv(aux, dydt, t + h/2);
    for(int ii = 0; ii < data.size(); ++ii) {
        k3[ii] = h*dydt[ii];
    }
    // k4 aux
    for(int ii = 0; ii < data.size(); ++ii) {
        aux[ii] = data[ii] + k3[ii];
    }
    // k4
    deriv(aux, dydt, t + h);
    for(int ii = 0; ii < data.size(); ++ii) {
        k4[ii] = h*dydt[ii];
    }

    // write new data
    for(int ii = 0; ii < data.size(); ++ii) {
        data[ii] = data[ii] + (k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
    }

}

template<typename system_t, typename state_t>
void integrate(system_t deriv, state_t & data, double tmin, double tmax, double dt)
{
    const int NSTEPS = (tmax-tmin)/dt;
    std::ofstream fout("reactors.txt");
    fout.precision(10);
    
    for (int ii = 0; ii <= NSTEPS; ++ii) {
        double t = tmin + ii*dt;
        fout<<t<<"\t";
        fout<<data[0]<<"\t";
        fout<<data[1]<<"\t";
        fout<<data[2]<<"\t";
        fout<<data[3]<<"\n";

        rk4(deriv, data, t , dt);
        t += dt;
    }
}


#endif // __INTEGRATION_H_
