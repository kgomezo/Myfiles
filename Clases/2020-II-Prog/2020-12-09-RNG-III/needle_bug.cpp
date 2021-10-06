#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <cstdlib>
#include <vector>


int main(int argc, char **argv)
{
    const int SEED = std::atoi(argv[1]);
    const int SAMPLES = std::atoi(argv[2]);

    std::mt19937 gen(SEED);
    std::uniform_real_distribution<double> ug(0, 1/2);
    std::uniform_real_distribution<double> vg(0, M_PI/2.0);
    int samples = 0;
    double prob = 0;
    while (samples < SAMPLES) {
        double u = ug(gen);
        double v = vg(gen);
        if (2*u < std::sin(v)) {
            prob++;
        }
        samples++;
    }
    std::cout << "Integral: " << prob/SAMPLES << "\n";
    return 0;
}
