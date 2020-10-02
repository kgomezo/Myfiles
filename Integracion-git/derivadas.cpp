#include<iostream>
#include<cmath>
#include<functional>

using fptr = double(double);
using fptr2 = double(double, double,fptr);

double f(double x);
double fdevtheo(double x);
double forward(double x, double h,fptr fun);
double central(double x, double h,fptr fun);
double richardson(double x, double h, fptr2 alg, fptr fun);


int main(void)
{

    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double X = 2.0;
    const double DEV_EXACT = fdevtheo(X);
    double h = 0;
    double deltac, deltaf, deltar; // percentual diffs


    for (double h = 1.0e-1; h >= 1.0e-8; h /= 10.0) {
        deltaf = std::fabs(1.0 - forward(X, h, f)/DEV_EXACT);
        deltac = std::fabs(1.0 - central(X, h, f)/DEV_EXACT);
        deltar = std::fabs(1.0 - richardson(X, h, central, f)/DEV_EXACT);
        std::cout << h << " \t" << deltaf << "\t" << deltac << "\t" << deltar << "\n";
    }

    
return 0;
}

double f(double x){
    return (std::exp(-2*x)-x); }

double fdevtheo(double x){
    return -2*std::exp(-2*x)-1 ; }

double forward(double x, double h, fptr fun){
    return (fun(x+h) - fun(x))/h ; }

double central(double x, double h, fptr fun){
    return (fun(x+h/2)-fun(x-h/2))/h ; }

double richardson(double x, double h, fptr2 alg, fptr fun){
    double D1= alg(x,h,fun);
    double D2= alg(x,h/2,fun);

    return (4*D2-D1)/3.0; }


