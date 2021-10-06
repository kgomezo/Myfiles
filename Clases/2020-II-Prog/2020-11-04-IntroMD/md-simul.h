#ifndef __MD_SIMUL_H_
#define __MD_SIMUL_H_

#include <iostream>
#include "particle.h"

const double G = -9.81;
const double B = 2.79;
const int NSTEPS = 1000;
const double DT = 0.01;

// function declarations
void initial_conditions(Particle & body);
void compute_force(Particle & body);
void time_integration(Particle & body, const double & dt);
void start_integration(Particle & body, const double & dt);
void print(Particle & body, double time);

#endif // __MD_SIMUL_H_
