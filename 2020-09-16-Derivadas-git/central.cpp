#include<iostream>
#include<cmath>
//Calcular la derivada central del sin
//graficas x y comparar errores

double f(double x);
double deriv_forward(double x, double h);
double deriv_central(double x, double h);
double richardson_forward(double x, double h);
double richardson_central(double x, double h);

int main(int argc, char**argv){
  const double DX = 0.01; //los pasos
  const double XMIN= 0.0;
  const double XMAX = 2*M_PI;

  const int N = (XMAX - XMIN)/DX;
  for (int ii = 0; ii <= N; ++ii){
    double x = XMIN + ii*DX;
    double error_forward = std::fabs(1- deriv_forward(x, DX)/std::cos(x));
    double error_central = std::fabs(1- deriv_central(x,DX)/std::cos(x));
    double error_richardson_forward = std::fabs(1- richardson_forward(x,DX)/std::cos(x));
    double error_richardson_central = std::fabs(1- richardson_central(x,DX)/std::cos(x));
    /* std::cout << x << "\t" << f(x)
	      << "\t" << deriv_forward(x,DX)
	      << "\n"; */
    
     std::cout << x
	      <<"\t"<< error_forward
	      <<"\t" << error_central
	      <<"\t" << error_richardson_forward
	      <<"\t"<< error_richardson_central
	      <<"\n"; 
  }
  return 0;
  
 }

double f(double x){
  return std::sin(x);

}
double deriv_forward(double x, double h){
  return (f(x+h) - f(x))/h;
}
double deriv_central(double x, double h){
  return (f(x+h/2) - f(x-h/2))/h;
}
double richardson_forward(double x, double h){
  double D1 = deriv_forward(x,h);
  double D2 = deriv_forward(x,h/2);

  return (4*D2 - D1)/3.0;
}
double richardson_central(double x, double h){
  double D1 = deriv_central(x,h);
  double D2 = deriv_central(x,h/2);

  return (4*D2 - D1)/3.0;
}
    
