#include<iostream>

void funcion(int *q);

int main(int argc, char **argv){
  int c = 90;
  auto flambda = [&c](auto a, auto b){
    std::cout<<"c: "<< c << std::endl;
    c=100;
    std::cout<<"tada:"<< c <<std::endl;
    return a<b;
  };
  bool flag=flambda(3.53, 3.14);{
    std::cout<<flag<<std::endl;
};

  int a; 
  int *p;
 
  a = 150; 
  p = &a; 
  // Llamamos a funcion con un puntero 
  funcion(p); // (1)
  std::cout << "Variable a: " << a <<std::endl; 
  std::cout << "Variable *p: " << *p << std::endl;
   // Llamada a funcion con la dirección de "a" (constante) 
  funcion(&a);  // (2)
  std::cout << "Variable a: " << a <<std::endl; 
  std::cout << "Variable *p: " << *p <<std::endl; 
   
  return 0; 
}
 
void funcion(int *q) { 
   // Cambiamos el valor de la variable apuntada por 
   // el puntero 
  *q += 50; 
   q++; 
}
