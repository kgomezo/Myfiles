#include<iostream>
/*
int factorial (int m);

int main(int argc, char **argv){
  int n = std::atoi(argv[1]);
  std::cout<<factorial(n)<<"\n";

  return 0;
}

int factorial (int m){
  int mult = 1;
  for (int ii=2; ii <= m; ++ii){
    mult= mult*ii;
  }
  return mult;
}
*/
//Hay pasa un overflow. Numeros tan grandes que el cp no puede almacenar. Hay limties
//Un long soporta mas cosas:



long factorial (long m);
long factorial_recu(int m);

int main(int argc, char **argv){
  int n = std::atoi(argv[1]);
  std::cout<<factorial(n)<<"\n";
  std::cout<<factorial_recu(n)<<"\n";

  return 0;
}

long factorial (long m){
  long mult = 1;
  for (long ii=2; ii <= m; ++ii){
    mult= mult*ii;
  }
  return mult;
}
//Sigue teniendo fallas.
//Con una función recursiva:

long factorial_recu(int m){
  if (m <= 1) return 1; //Si son negativos, para, retorna 1
  return m*factorial(m-1);   //Hay que poner una condicion de finalizacion. Sino sigue disminuyendo m-1 hasta negativos
}

