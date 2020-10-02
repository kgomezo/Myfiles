#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdlib>

void printsum(int nmax);
int main(int argc, char *argv[]){
    std::cout.precision(15); std::cout.setf(std::ios::scientific);
    
    int NMAX=500;
   // const int NMAX = std::atoi(argv[1]);
    printsum(NMAX);

    return 0;
}

void printsum(int nmax){
    int ii=1;
    double k=0;
    double n=1;
    float sum=0.0, inv =0;
    
    while (ii < nmax){
        k= n*ii;
        k= k*ii;
        inv=(1/k);
        sum=sum+inv;
        ii++;
        std::cout << ii <<"\t" <<sum <<"\n";
    }
    std::cout<<"The sum of the inverse al cuadrado de" <<nmax <<" es " <<sum<<"\n";
}

