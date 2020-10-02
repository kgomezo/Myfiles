#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdlib>

bool isprime(int x);

int main(void){
    std::cout << isprime(-2) << std::endl;
    std::cout << isprime(0) << std::endl;
    std::cout << isprime(2) << std::endl;
    std::cout << isprime(3) << std::endl;
    std::cout << isprime(4) << std::endl;
    std::cout << isprime(41) << std::endl;

    return 0;
}

bool isprime(int x){
    int ii=0;
    int k=2;
    for (int k=2; k < x; k++){
        if (x % k ==0){ return false;}
    }
    if (x < k){return false;}
    return true;
}

    /*
    while (k <= x){
        k++;
        if (x % k ==0){ std::cout<< "0 \n"; break; }
        else { std::cout <<" 1 \n "; break; }
    }

    return 0;
}*/

    

