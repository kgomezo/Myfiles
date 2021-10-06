#include <iostream>
#include<cstdlib>
// escriba acá la declaración e  implementación de la template
template <typename T, typename S, typename P>
auto maximum(T a, S b, P c)
{
  double c1;
  c1 = a > b ? a : b ;
  double c2;
  c2 = a > c ? a : c ;
  double mayor;
  mayor = c1 > c2 ? c1: c2 ;
  return mayor;
}

int main(void)
{
    std::cout << maximum(1, 3, 2.4)         << std::endl; // int
    std::cout << maximum(-3.7 , 1,   2.4)   << std::endl; // double
    std::cout << maximum(-3.1f, 1.7f, -2.4) << std::endl; // float

  return 0;
}
