#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <vector>

const int NSTEPS= 8;
const double MAX_LENGTH = 5;

int main(int argc, char **argv)
{
    const int SEED = std::atoi(argv[1]);
    const int SAMPLES = std::atoi(argv[2]);

    std::mt19937 gen(SEED);
 
    //std::uniform_real_distribution<double> ug(1, 5);
    std::uniform_real_distribution<double> thetag(0, 2*M_PI);
    int samples = 0
    double prob = 0;
    //lo que recorre primer paso es 1+costhetha . en el segundo
    //1+costheta2 + ... + costheta7 queremos longitud total de L < 5
    //por cada uno tenemos que hacer la simulacion de los 8 steps
    //nos da la longitud total, la comparamos con 5
    //cada muestra es un camino
    while (samples < SAMPLES) {
        double length = 1;
        for (int istep = 1; istep < NSTEPS; ++istep){
            double angle = thetag(gen);
            length += std::cos(angle);
        }
        
        //double v = vg(gen);

        if (length > MAX_LENGTH) {
            prob++;
        }
        samples++;
    }
    std::cout << "Prob: " << prob/SAMPLES << "\n";
    return 0;
}
