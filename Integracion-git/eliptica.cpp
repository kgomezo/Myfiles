# include <iostream>
# include <cmath>
using fptr = double(double, double, double);
using integptr = double(double, double, int, double,double, fptr);

double integrand(double a, double b, double x);
double simpson(double xmin, double xmax, int n, double a, double b, fptr fun);
double richardson(double xmin, double xmax, int n, double a, double b, fptr fun, integptr integ_method, int order);
double arc_length(double a, double b, int n);


int main(int argc, char *argv[])
{
    const int N = std::atoi(argv[1]);
    const double A = 2.0, B = 1.0;
    std::cout.precision(15); std::cout.setf(std::ios::scientific);

    std::cout << N << "\t" << arc_length(A, B, N) << "\n";
    return 0;
}


double integrand(double a, double b, double x)
{
    double e=(std::sqrt(a*a - b*b))/a;
    double f=std::sqrt(1-((e*e)*sin(x)*sin(x)));
    return f;
    
}


double arc_length(double a, double b, int n)
{
    return 4*a*richardson(0, M_PI/2, n, a, b, integrand, simpson, 4);
}


double simpson(double xmin, double xmax, int n, double a, double b, fptr fun)
{
    const double h = (xmax-xmin)/n;
    double sum1 = 0.0, sum2 = 0.0;
    double suma= 0.0;
    
    for (int ii = 1; ii <= n/2 - 1; ++ii) {
        double x = xmin + 2*ii*h;
        sum1 += fun(a, b, x);
            }

    
    for (int ii = 1; ii <= n/2; ++ii) {
        double x = xmin + (2*ii-1)*h;
        sum2 += fun(a, b, x);
    }
    suma = h*(fun(a,b,xmin)+ 2*sum1 + 4*sum2 + fun(a,b,xmax))/3;
    
    return suma;
}


double richardson(double xmin, double xmax, int n, double a, double b, fptr fun, integptr integ_method, int order)
{
    double phi1 = integ_method(xmin, xmax, 2*n, a, b, fun);
    double phi2 = integ_method(xmin, xmax, n, a, b, fun);
    return phi1 + (phi1 - phi2)/(std::pow(2, order) - 1);
}





        
