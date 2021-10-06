#include <iostream>
#include <vector>
#include <cmath>

const double DELTA = 0.05;
const double XMIN = 0.0;
const double XMAX = 1.0;
const double YMIN = 0.0;
const double YMAX = 1.2;
const int NX = (XMAX-XMIN)/DELTA;
const int NY = (YMAX-YMIN)/DELTA;
const int NSTEPS = 1000;

typedef std::vector<double> data_t;

void initial_conditions(data_t & data, int nx, int ny);
void boundary_conditions(data_t & data, int nx, int ny);
int evolve(data_t & data, int nx, int ny, int maxnsteps, double eps);
double relaxation_step(data_t & data, int nx, int ny);
void print_screen(const data_t & data, int nx, int ny);
void start_gnuplot(void);
void print_gnuplot(const data_t & data, int nx, int ny);


int main(int argc, char **argv)
{
    // declare data structures
    data_t potential(NX*NY);


    for(double eps = 1.0e-1; eps >= 1.0e-4; eps /= 2.0) {
        // set initial and boundary conditions
        initial_conditions(potential, NX, NY);
        boundary_conditions(potential, NX, NY);
        // evolve and print
        int actual_nsteps = evolve(potential, NX, NY, NSTEPS, eps);
        std::cout << eps << "  " << actual_nsteps << "\n";
    }
    return 0;
}

void initial_conditions(data_t & data, int nx, int ny)
{
    for(int ix = 0; ix < nx; ++ix) {
        for(int iy = 0; iy < ny; ++iy) {
            data[ix*ny + iy] = 1.0;
        }
    }
}
void boundary_conditions(data_t & data, int nx, int ny)
{
    int ix, iy;
    // first row
    ix = 0;
    for(int iy = 0; iy < ny; ++iy) {
        data[ix*ny + iy] = 100.0;
    }
    // last row
    ix = nx-1;
    for(int iy = 0; iy < ny; ++iy) {
        data[ix*ny + iy] = 0.0;
    }
    // first row
    iy = 0;
    for(int ix = 1; ix < nx; ++ix) {
        data[ix*ny + iy] = 0.0;
    }
    // last row
    iy = ny-1;
    for(int ix = 1; ix < nx; ++ix) {
        data[ix*ny + iy] = 0.0;
    }
    //new
    ix = nx/2;
    for(int iy = ny/3; iy <= 2*ny/3; ++iy) {
        data[ix*ny + iy] = -50.0;
    }
}

int evolve(data_t & data, int nx, int ny, int maxnsteps, double eps)
{
    //start_gnuplot();

    int istep = 0;
    for(istep = 0; istep < maxnsteps; ++istep) {
        double maxdelta = relaxation_step(data, nx, ny);
        if (maxdelta <= eps) break;
        //print_screen(data, nx, ny);
        //print_gnuplot(data, nx, ny);
    }
    return istep;
}

double relaxation_step(data_t & data, int nx, int ny)
{
    // recorrer toda la matriz y aplicar el algoritmo,
    // teniendo cuidado con no modificar las condiciones de
    // frontera
    double maxdelta = -1;
    for(int ix = 1; ix < nx-1; ++ix) {
        for(int iy = 1; iy < ny-1; ++iy) {
            // check that this cell is NOT a boundary condition or a border
            if ( (ix == nx/2) && (ny/3 <= iy) && (iy <= 2*ny/3) ) continue;
            // update the cell
            double newval = (data[(ix+1)*ny + iy] + data[(ix-1)*ny + iy] + data[ix*ny + iy+1] + data[ix*ny + iy-1])/4.0;
            double delta = std::fabs(1 - newval/data[ix*ny + iy]);
            if ( delta > maxdelta) {
                maxdelta = delta;
            }
            data[ix*ny + iy] = newval;
        }
    }
    return maxdelta;
}
void print_screen(const data_t & data, int nx, int ny)
{
    for(int ix = 0; ix < nx; ++ix) {
        for(int iy = 0; iy < ny; ++iy) {
            std::cout << data[ix*ny + iy] << "  ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}

void start_gnuplot(void)
{
    std::cout << "set pm3d\n";
    std::cout << "set contour base\n";
    std::cout << "set term gif animate\n";
    std::cout << "set output 'anim.gif'\n";
}

void print_gnuplot(const data_t & data, int nx, int ny)
{
    std::cout << "splot '-' w l lt 3 \n";
    for(int ix = 0; ix < nx; ++ix) {
        double x = XMIN + ix*DELTA;
        for(int iy = 0; iy < ny; ++iy) {
            double y = YMIN + iy*DELTA;
            std::cout << x << "  " << y << "  " << data[ix*ny + iy] << "\n";
        }
        std::cout << "\n";
    }
    std::cout << "e\n";
}
