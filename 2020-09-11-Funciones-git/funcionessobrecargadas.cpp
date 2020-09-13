#include <iostream>
#include<cstdlib>
/*
int getmax(int a, int b);
double getmax(double a, double b);
double getmax(double a, int b);

int main(int argc, char **argv){

  std::cout<<getmax(-1,-2 )<<std::endl;
  std::cout<<getmax(2.49,2.51)<<std::endl;
  std::cout<<getmax(2.78,2)<<std::endl;
  return 0;
}

int getmax(int a, int b){
  int result = a;
  if (b>a){
    result=b;
  }
  return result;
}

double getmax(double a, double b){
  double result = a;
  if (b > a){
    result = b;
  }
  return result;
}

double getmax(double a, int b){
  double result = a;
  if (b>a){
    result = b;
  }
  return result;
}
*/
//FUNCIONES PLANTILLA:

template <typename T, typename S> //Para tipos de datos mixtos
T getmax(T a, S b)
{
  T result = a;
  if (b>a){
    result = b;
  }
  return result;
}

int main(int argc, char **argv){
  std::cout<<getmax(-1,-2)<<std::endl; //Tambien se puede dentro de cada uno especificar si <int a, int b>
  std::cout<<getmax(2.49,2.52)<<std::endl;
  std::cout<<getmax(2.39,1)<<std::endl;
  return 0;
}
//Mismas funciones para diferentes tipos de datos. El compilador hace las funciones.
