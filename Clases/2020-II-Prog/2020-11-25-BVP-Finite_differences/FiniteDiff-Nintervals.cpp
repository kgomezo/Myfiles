#include <iostream>
#include <eigen3/Eigen/Dense> // virtual machine
#include <cstdlib>

const double L = 10; // m
const double H = 0.01; // m^-2
const double TA = 20; // C
const double T0 = 40;
const double TL = 200;

// T0             TL
// +--+--+--+--+--+

int main(int argc, char **argv)
{
    const int NINT = std::atoi(argv[1]);
    const int N = NINT + 2;
    const double DX = L/(N-1);
    const double ALPHA = 2 + H*DX*DX;
    const double BETA = H*DX*DX*TA;

    Eigen::MatrixXd M(NINT, NINT);
    Eigen::VectorXd b(NINT);
    M.setZero();
    b.setZero();

    // Matrix index = Temp index - 1
    for(int ii = 0; ii < NINT; ++ii){
        M(ii, ii) = ALPHA;
        if (ii == 0) {
            M(ii, ii+1) = -1;
        } else if (ii == NINT-1) {
            M(ii,ii-1) = -1;
        } else {
            M(ii,ii-1) = -1; M(ii, ii+1) = -1;
        }
        b(ii) = BETA;
    }
    b(0) += T0;
    b(NINT-1) += TL;

    //std::cout << M << std::endl;
    //std::cout << b << std::endl;

    Eigen::VectorXd T = M.colPivHouseholderQr().solve(b);

    for (int ii = 0; ii < N; ++ii) {
        double x = 0 + ii*DX;
        double TEMP = T0;
        if (ii == 0) TEMP = T0;
        else if (N-1 == ii) TEMP = TL;
        else TEMP = T[ii-1];
        std::cout << x << "  " << TEMP << std::endl;
    }
    /*
    std::cout << 0 << "\t" << T0 << std::endl;
    for(int ii = 0; ii < NINT; ++ii) {
        std::cout << 0 + (ii+1)*DX << "\t" << T[ii] << std::endl;
    }
    std::cout << L << "\t" << TL << std::endl;
    */

    return 0;
}
