#include <vector>
#include "integration.h"

const double A0 = 20 ; // ??
const double TAU = 5; // ??
const double K = 0.12; // ?
const double TA = 0;
const double TB = 50.0;
const double H  = 0.01;

typedef std::vector<double> state_t;

void fderiv(const state_t & y, state_t & dydt, double t)
{
  
    dydt[0] = ((A0 - y[0])/TAU) - K*y[0];
    dydt[1] = ((y[0]-y[1])/TAU) - K*y[1];
    dydt[2] = (-y[2]/TAU) + K*y[0];
    dydt[3] = ((y[2]-y[3])/TAU) + K*y[1];
    
    
     // FILL HERE
}


int main (int argc, char **argv)
{
    std::vector<double> y = {0.0, 0.0, 0.0, 0.0}; // {A10, A20, B10, B20}


    //for(int ii = 0; ii < TB; ++ii){
        integrate(fderiv, y, TA, TB, H);


    return 0;
}
