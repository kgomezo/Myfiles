#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <cstdlib>

using fptr = double(double);
using fptr2 = double(fptr, double, double, int);

double f(double x);
double trapecio(fptr fun, double a, double b, int N);
double richardson(fptr2 alg, fptr fun, double a, double b,double eps);

int main(int argc, char **argv){
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double eps = std::atof(argv[1]);
    std::cout << richardson(trapecio, f, 0, 1, eps) <<"\n";


    return 0;
}

double f(double x){
    return std::pow(x,0.1)*(1.2-x)*(1-std::exp(20*(x-1)));

}

double trapecio(fptr fun, double a, double b, int N){
    double  h=(b-a)/N;
    double sum=0.5*(fun(a)+fun(b));
    for(int i=1; i<=N-1;++i){
        double xi= a + i*h ;
        sum += fun(xi);
        return sum;
    }
    return h*sum;

}

double richardson(fptr2 alg, fptr fun, double a, double b,double eps){
       
    int N=1;
    double diff= 10;
    double val2=0, val1=0;
    while (diff > eps){
        val1=(4*alg(fun, a, b,2*N)-alg(fun,a,b,N))/3;
        val2=(4*alg(fun, a, b, 2*N)-alg(fun, a, b, N))/3;
        diff=std::fabs(1-val1/val2)*100;
        N*=2; }
    std::cout<<"n: "<<N<<"\n";
    std::cout<<"diff: "<< diff <<"\n";
    return val1; }
        
  /*  for (int N=2; ; N*=2){
       double val2=(4*alg(fun, a, b, 2*N)-alg(fun, a, b, N))/3;
       double diff=std::fabs(1-val1/val2);
        
        if(diff <= eps){
            std::cout<<"n:"<< N <<"\n";
            std::cout<<"dif:" << diff <<"\n";
            return val2;
        }
   
    }
}*/
