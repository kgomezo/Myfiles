#include<iostream>
#include<cstdlib>

int next_collatz_term(int n);
int maximum_collatz(int n0);

int main (int argc, char**argv){
  int N = std::atoi(argv[1]);
  int maxval= -1, n0max= 1;
  for(int ii=1; ii <= N; ++ii){
    if(maximum_collatz(ii)>maximum_collatz(n0max){
      maxval = maximum_collatz(ii);
      n0max= ii;
    }
  }
  std::cout<< n0max << "->" << maxval << "\n";
}

int next_collatz_term(int n){
  if (n==1) return 1;
  if (n%2==0) return n/2;
  else return 3*n + 1;
}

int maximum_collatz(int n0){
  int k=0;
  while (n0>1){
    n0=next_collatz_term(n0);
    if(n0>=k){
      k=n0;}
  }
  return k; }
  
