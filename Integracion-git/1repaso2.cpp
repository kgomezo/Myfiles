#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdlib>

double final(double p, double i, double n);

int main(void){
    double P=0;
    double I=0;
    double N=0;
    std::cout << "Introduzca la cantidad de dinero: \n";
    std::cin >> P;
    std::cout <<"Introduzca el interes compuesto i: \n";
    std::cin >> I;
    std::cout <<"Introduzca el numero de periodos n: \n";
    std::cin >> N;
    std::cout <<"La cantidad final es: "<<final(P, I, N) <<"\n";

    return 0;
}

double final(double p, double i, double n){
    double f= p* std::pow((1+i),n) ;
    return f ;
}

    
