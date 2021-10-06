#include <iostream>
#include <fstream>
#include <vector>

const double XMIN = 0.0; // cm
const double XMAX = 10; // cm
const double DX = 2; // cm
const int NX = (XMAX-XMIN)/DX + 1;
const double dt = 0.1; // s
const double tmax = 21;
const int tsteps = tmax/dt;
const double T0 = 100; // C
const double TF = 50; // C
const double K = 0.835;
const double LAMBDA = K*dt/(DX*DX);

template <class state_t>
void initial_conditions(state_t & data);

template <class state_t>
void evolve(state_t & data, int nsteps);

template <class state_t>
void print(const state_t & data, int step);

int main(int argc, char **argv)
{
    std::vector<double> T(NX, 0.0);

    initial_conditions(T);

    evolve(T, tsteps);


    return 0;
}

template <class state_t>
void initial_conditions(state_t & data)
{
    for (auto & val : data) {
        val = 0;
    }
    data[0] = T0;
    data[data.size() - 1] = TF;
}

template <class state_t>
void evolve(state_t & data, int nsteps)
{
    print(data, 0);
    for (int l = 1; l < nsteps; ++l) {
        for(int ii = 1; ii < data.size() - 1; ++ii) {
            data[ii] = data[ii] + LAMBDA*(data[ii+1] - 2*data[ii] + data[ii-1]);
        }
        if (l % 30 == 0) {
            print(data, l);
        }
    }
}

template <class state_t>
void print(const state_t & data, int step)
{
    std::string fname = "temp_" + std::to_string(step) + ".txt";
    std::ofstream fout(fname);
    for (int ii = 0; ii < data.size(); ++ii) {
        fout << XMIN + ii*DX << "\t" << data[ii] << "\n";
    }
    fout.close();

}
