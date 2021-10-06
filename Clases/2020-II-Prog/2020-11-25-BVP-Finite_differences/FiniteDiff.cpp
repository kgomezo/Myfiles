#include <iostream>
#include <eigen3/Eigen/Dense> // virtual machine

const double L = 10; // m
const double H = 0.01; // m^-2
const double TA = 20; // C
const double T0 = 40;
const double TL = 200;
const int NINT = 4;
const int N = NINT + 2;
const double DX = L/(N-1);
const double ALPHA = 2 + H*DX*DX;
const double BETA = H*DX*DX*TA;

// T0             TL
// +--+--+--+--+--+

int main(int argc, char **argv)
{
    Eigen::MatrixXd M(NINT, NINT);
    Eigen::VectorXd b(NINT);
    M.setZero();
    b.setZero();

    // Matrix index = Temp index - 1
    M(0, 0) = ALPHA; M(0, 1) = -1;
    M(1, 0) = -1; M(1, 1) = ALPHA; M(1, 2) = -1;
    M(2, 1) = -1; M(2, 2) = ALPHA; M(2, 3) = -1;
    M(3, 2) = -1; M(3, 3) = ALPHA;

    b(0) = BETA + T0;
    b(1) = BETA;
    b(2) = BETA;
    b(3) = BETA + TL;

    std::cout << M << std::endl;
    std::cout << b << std::endl;

    Eigen::VectorXd T = M.colPivHouseholderQr().solve(b);

    std::cout << T0 << std::endl;
    std::cout << T << std::endl;
    std::cout << TL << std::endl;

    return 0;
}
