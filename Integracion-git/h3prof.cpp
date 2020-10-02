#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <cstdlib>

using fptr = double(double);
using fptr2 = double(fptr, double, double, int);

double f(double x);
double trapecio(fptr fun, double a, double b, int N);
double richardson(fptr2 alg, fptr func, double a, double b,double eps);

int main(int argc, char **argv){
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double eps = std::atof(argv[1]);
    std::cout << richardson(trapecio, f, 0, 1, eps) <<"\n";


    return 0;
}

double f(double x){
    return std::pow(x,0.1)*(1.2-x)*(1-std::exp(20*(x-1)));

}

double trapecio(fptr func, double a, double b, int N){
    double  h=(b-a)/N;
    double sum=0.5*(func(a)+func(b));
    for(int ii=1; ii<=N-1;++ii){
        double x= a + ii*h ;
        sum += func(x);
    }
    return h*sum;

}

double richardson(fptr2 alg, fptr func, double a, double b,double eps){
    int N=1;
    double val1=0, val2= 0, diff = 0;

    do{
        val1=(4*alg(func, a, b, 2*N)-alg(func, a, b, N))/3;
        N*=2;
        val2=(4*alg(func, a, b, 2*N)-alg(func, a, b, N))/3;
        diff=std::fabs(1-val1/val2); }
    while(diff > eps);

    std::cout<<"n: "<< N <<"\n";
    std::cout<<"diff : "<< diff <<"\n";
    
    return val2;
}
