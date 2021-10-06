#include <iostream>
#include <fstream>
//#include <string>
#include <random>
//#include <cstdlib>
#include <vector>

int main(int argc, char **argv)
{
    const int SEED = std::atoi(argv[1]);;
    const int SAMPLES = std::atoi(argv[2]); //numero de muestras. Entre mas meta mas se acerca a una dist uniforme
    const double A = -2.0; //distribucion uniforme entre -2 y 2
    const double B = 2.0;
    const double XMIN = -5.0;
    const double XMAX = 5.0;
    const int NBINS = 40;
    const double DX = (XMAX-XMIN)/NBINS;

    std::vector<double> histo(NBINS, 0.0);
    std::mt19937 gen(SEED);
    std::normal_distribution<double> dist(0, 1); //uniform_distribution
    std::ofstream fout("data.txt");
    for (int ii = 0; ii < SAMPLES; ++ii) {
        double r = dist(gen);
        fout << r << "\n";
        int bin = int((r - XMIN)/DX);
        if (0 <= bin && bin < NBINS) {
            histo[bin]++;
        }
    }
    fout.close();

    fout.open("histo.txt");
    for (int ii = 0; ii < NBINS; ii++) {
        fout << XMIN + ii*DX << "\t" << histo[ii]/(DX*SAMPLES) << "\n"; //tomo todo el contador que tome de la cjita
    }//estamos imprimiendo la densidad de probabilidad
    fout.close();

    return 0;
}
