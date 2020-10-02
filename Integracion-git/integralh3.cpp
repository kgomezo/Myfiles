#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <cstdlib>

using fptr  = double(double);
using fptr2 = double(fptr, double, double, int);

double f(double x);
double trapezoid(fptr fun, double a, double b, int n);
double richardson(fptr2 alg, fptr func, double a, double b, double eps, int alpha);

int main(int argc, char **argv)
{
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    const double eps = std::atof(argv[1]);
    std::cout << richardson(trapezoid, f, 0.0, 1.0, eps, 2) << "\n";

  return 0;
}

double f(double x){
  return std::pow(x, 0.1)*(1.2-x)*(-std::expm1((20*(x-1))));
}

double trapezoid(fptr fun, double a, double b, int n){
	const double h= (b-a)/n;
	double suma = 0.5*(fun(a)+fun(b));
	for(int ii=1; ii<=n-1; ++ii){
		double xi= a + ii*h;
		suma += fun(xi);
	}
	suma *= h;
	return suma;
}

double richardson(fptr2 alg, fptr fun, double a, double b, double eps, int alpha){

  int n=0;
  //int nmax = 1000;

  for (int n=1;/* n<= nmax*/ ; n*=2){
   	double val1 = (4*alg(fun,a,b,n)-alg(fun,a,b,n/2))/3; //quite el 2*n, solo n porque en el for ya se esta aumentando 
    double val2 = (4*alg(fun,a,b,2*n)-alg(fun,a,b,n))/3;
    double dif = std::fabs(1-val1/val2);

    if (dif <= eps){
      	std::cout <<"n:"<< n <<"\n";
    	  std::cout <<"diff: "<< dif <<"\n";
        return val2; //val1 + (val1 - val2)/(std::pow(2, alpha) -1);
        
		}
  }
  return 0;

}
