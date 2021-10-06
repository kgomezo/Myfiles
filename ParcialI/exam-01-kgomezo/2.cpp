#include <fstream>
#include <cmath>
#include <cstdlib>

using fptr = double(double);
using algptr = double(double, double, fptr);

double potential(double x);
double dev_central(double x, double h, fptr fun);
double dev_richardson(double x, double h, fptr fun, algptr alg);
double forcex(double x, double h, fptr fun, algptr alg);

int main(int argc, char **argv)
{
    //TODO: open the file stream and set the formatting:

    // print data
    const double h = std::atof(argv[1]);
    const double xmin = 0.0;
    const double xmax = 2.5;
    const int N = (xmax-xmin)/h;
    std::ofstream fout("fuerza.txt");
    fout.precision(15); fout.setf(std::ios::scientific);
    
    for(int ii = 0; ii < N; ++ii) {
        double x = xmin + ii*h;
        fout << x << "\t"
             << -2*std::sin(x) -2*x*std::cos(x) << "\t"
             << forcex(x, h, potential, dev_central) << "\n";
    }
    fout.close();
    // TODO : close any file stream
    
    return 0;
}

double potential(double x){
    return 2*x*std::sin(x);
}
double dev_central(double x, double h, fptr fun){
    return ((fun(x+h/2)-fun(x-h/2))/h); }

double dev_richardson(double x, double h, fptr fun, algptr alg){
    double val1= alg(x,h,fun);
    double val2= alg(x, h/2, fun);
    return (4*val2 - val1)/3.0;
}
double forcex(double x, double h, fptr fun, algptr alg){
    return -alg(x,h,fun);
}







