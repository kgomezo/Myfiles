#include<iostream>
#include<cmath>
#include<functional>

using fptr = double(double);
using fptr2 = double(fptr, double, double, int);

double f(double x);
double trapecio(fptr fun, double a,double b, int n);
double richardson(fptr2 alg, fptr fun, double a, double b, int N, int alpha);

int main(int argc, char **argv){
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double xmin= 0.0;
    const double xmax= 1.0;

    for(int NMAX=1; NMAX <= 1.0e8; NMAX *= 10){
        double num_trapecio = trapecio(f, xmin, xmax, NMAX);
        double num_traprich= richardson(trapecio, f, xmin, xmax, NMAX, 2);
        double theo= (((-6*std::sin(xmax/2)+ 2*std::cos(xmax/2))*std::exp(-xmax))/5)+(((6*std::sin(xmin/2)- 2*std::cos(xmin/2))*std::exp(-xmin))/5)  ;
        double delta_traprich= std::fabs(1-num_traprich/theo);
        double delta_trapecio = std::fabs(1-num_trapecio/theo);
        std::cout << NMAX
                  <<"\t" << delta_trapecio
                  <<"\t" << delta_traprich
                  <<"\t Y: "<< num_traprich
                  <<"\t Ex: "<< theo
                  <<"\n";
    }
    return 0;
}
double f(double x){
    return std::sqrt(1-std::sin(x))*exp(-x) ;
}

double trapecio(fptr fun, double a, double b, int n){
    const double h=(b-a)/n;
    double suma = 0.5*(fun(a)+fun(b));
    for(int ii=1; ii <= n-1; ++ii){
        double xi= a + ii*h;
        suma += fun(xi);
    }
    suma *= h;
    return suma;
}

double richardson(fptr2 alg, fptr fun, double a, double b, int N, int alpha){
    double aux1=alg(fun, a, b, 2*N);
    double aux2=alg(fun, a, b, N);
    return aux1+(aux1-aux2)/(std::pow(2,alpha)-1);
}












    
