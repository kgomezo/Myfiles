#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>

double statistics1(const double data[], int size);
void fillarray(double data[], int size);

int main(int argc, char **argv)
{
    // array declaration
    int N = 100000; 
    double array [N] {0.0};

    // array filling
    fillarray(array, N); 
    
    // processing
    double result = statistics1(array, N);
    std::cout << result << std::endl;

    return 0;
}

void fillarray(double data[], int size)
{
    // double x = -19.8765;
    // std::fill(data, data+size, x);
    // std::iota(data, data+size, 1); // (1 + 2 + 3 + 4 + .. + N)/N = N(N+1)/2N = (N+1)/2
    // numeros aleatorios
    const int SEED = 0;
    std::mt19937 mt(SEED);
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    for (int ii = 0; ii < size; ++ii) {
        data[ii] = dist(mt);
    }
}


double statistics1(const double data[], int size)
{
    double mean = 0.0;

    for(int ii = 0; ii < size; ++ii) {
        mean += data[ii];
    }
    
    return mean/size;
}
