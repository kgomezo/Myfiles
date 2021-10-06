#include <iostream>
#include <fstream>
#include <cmath>

using fptr = double(double);
double f(double x);
double read_params(void); // returns the precision read from params.txt
double bisection(double xl, double xu, double eps, fptr fun);

int main(void)
{
  std::cout.precision(15); std::cout.setf(std::ios::scientific);
  const double xmin = 0.5;
  const double xmax = 2.0;
  const double eps = read_params();
  double root = bisection(xmin, xmax, eps, f);
  std::cout << root << "\t" << f(root) << std::endl;

  return 0;
}
double f(double x){
  return ((std::pow(x,3))- 2*std::sin(x));
}


double bisection(double xl, double xu, double eps, fptr fun){
  const int NITERMAX= 1000;
  double xr = 1;
  int niter = 0;
  double x=0; 
  while (niter <= NITERMAX){
    xr=0.5*(xl + xu);
    if (std::fabs(fun(xr)) <= eps){break ;}

    else if (fun(xr)*fun(xu)> 0) { xu = xr; }

    else { xl = xr; }
    niter ++;
  }
  return xr;
}

double read_params(void){
  double eps = 0.0;
  std::ifstream fin("params.txt");
  fin >> eps;
  fin.close();
  std::cout <<eps<<"\n";
  return eps;
}






    
