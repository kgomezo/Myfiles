#include <iostream>
#include <vector>

const double DELTA = 0.1;
const double XMIN = 0.0;
const double XMAX = 1.0;
const double YMIN = 0.0;
const double YMAX = 1.2;
const int NX = (XMAX-XMIN)/DELTA;
const int NY = (YMAX-YMIN)/DELTA;
const int NSTEPS = 1;


typedef std::vector<double> data_t;

void initial_conditions(data_t & data, int nx, int ny); //por ref porque lo va a modificar
void boundary_conditions(data_t & data, int nx, int ny);
void evolve(data_t & data, int nx, int ny, int nsteps);
void relaxation_step(data_t & data, int nx, int ny);
void print_screen(const data_t & data, int nx, int ny);
void print_gnuplot(const data_t & data, int nx, int ny);

int main(int argc, char **argv){
    //declare data structures. donde vamos a guardar
    // Matrix size: Nx, Ny, Delta, XMIN, XMAX, YMIN, YMAX
    //std::vector<double> Nx*Ny arreglo unidimensional
    data_t potential (NX*NY);

    // set initial boundary conditions
    // initial_conditions(potential, Nx, Ny) sabe el tamaño total pero no internamente

    initial_conditions(potential, NX, NY);//cond iniciales a todo el mundo
    boundary_conditions(potential, NX, NY); //condiciones de frontera.

    // evolucionar.cuantos pasos hacer despues hacer cuando
    //ya no haya cambiado suficiente
    evolve(potential, NX, NY, NSTEPS); // resolucion EPS

    //print

    return 0;
}
//evolve

    //for ii < NSTEPS
    //relaxation_step: recorrer toda la matriz haciendo relajacion
    //y respetando las condiciones de frontera
    //print

void initial_conditions(data_t & data, int nx, int ny){

    for(int ix = 0; ix < nx; ++ix){
        for(int iy = 0; iy < ny; ++iy){
            data[ix*ny + iy] = 1.0; //inicializamos todo con cero
        }
    }
    
}


void boundary_conditions(data_t & data, int nx, int ny){
    //queremos que en la frontera valga 100 voltios+
    int ix, iy;
    //first row
    ix = 0;
    for(int iy = 0; iy < ny; ++iy){
        data[ix*ny + iy] = 100.0;
    }

    ix = nx-1; //last row
    for(int iy= 0; iy < ny; ++iy){
        data[ix*ny + iy] = 0.0; }
    // firt row
    iy = 0;
    for(int ix = 1; ix < nx; ++ix){
        data[ix*ny + iy] = 0.0; }
    //last row
    iy = ny-1;
    for(int ix= 1; ix < nx; ++ix){
        data[ix*ny + iy] = 0.0; }

}


void evolve(data_t & data, int nx, int ny, int nsteps){
    
    for(int istep = 0; istep < nsteps; ++istep){
        relaxation_step(data, nx, ny);
       // print_screen(data, nx, ny);
        print_gnuplot(data,nx, ny);
    }
    
}


void relaxation_step(data_t & data, int nx, int ny){

    for(int ix = 1; ix < nx-1; ++ix){
        for(int iy = 1; iy < ny-1; ++iy){//porque cuando x sea cero noesta def el -1
            //check that this cell is not a boundary condiition or a border
            // if esto es una condicion de frontera continue; no haga lo que esta debajo mio
            //el break se sale del bucle el continue no
            
            data[ix*ny+iy] = (data[(ix+1)*ny + iy] + data[(ix-1)*ny + iy] + data[ix*iy + (iy+1)] + data[ix*iy + (iy-1)])/4;
        }
    }
    
}


void print_screen(const data_t & data, int nx, int ny){

    for(int ix = 0; ix < nx; ++ix){
        for(int iy = 0; iy < ny; ++iy) {
            std::cout << data[ix*ny + iy] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    
}
void print_gnuplot(const data_t & data, int nx, int ny)
{
    for(int ix = 0; ix < nx; ++ix){
        double x = XMIN + ix*DELTA;
        for(int iy = 0; iy < ny; ++iy){
            double y = YMIN + iy*DELTA;
            std::cout << x << " " << y << " " << data[ix*ny + iy] << "\n";
        }
        std::cout<< "\n";
    }
}
