#include <iostream>
#include<cstdlib>

double average(double k, double y);
//argv son cadenas de texto. Si fuera double x = argv[1]
//seria ponerlos en double. los queremos pasar a numeros primero
//atof recibe una cadena char * y retorna un double

int main (int argc, char *argv[]){
  double x = std::atof(argv[1]); //coge el argumento y lo conv en double
  double y = std::atof(argv[2]);
  double z = 0;
  z = average (x,y);
  std::cout << z << std::endl;
  return 0;
}

double average(double k, double y){
  double result = 0;
  result = 0.5*(k + y);
  return result;
}
