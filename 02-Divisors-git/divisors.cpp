#include<iostream>
#include<cstdlib>

int number_of_divisors(int n);
int main(int argc, char**argv){
  const int NDMAX = std::atoi(argv[1]);
  int sum=0, k=0;
  for (int ii=1; ;++ii){
    sum = ii*(ii+1)/2;
    k=number_of_divisors(sum);
    if (k>NDMAX){std::cout<< sum << "->" << k; break;
    }
  }
  
  return 0;
}
int number_of_divisors(int n){
  int b=n, k=0;
  for(int i=1; i<=b; ++i){
    if(n%i==0){ k++; }
  }
  return k++;
}

  
