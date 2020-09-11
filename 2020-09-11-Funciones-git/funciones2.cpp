#include<iostream>
#include<vector> //{1,2,3,4,-9}
#include<algorithm> //copy, sort, transform
#include<cmath>
/*
int main(int argc, char **argv)
{
  std::vector<int> data={3, 4,-1,-10,0};
  std::sort(data.begin(), data.end()); //me organiza de menor a mayor
  for(int ii = 0; ii <5; ++ii){
    std::cout<<"data["<< ii <<"]: "<< data[ii]<<"\n";
  }
  return 0;
}
//Si quiero que no tenga en cuenta el signo, solo el valor absoluto--Uso lambda function
*/
/*
int main(int argc, char **argv)
{
  std::vector<int> data={3,4,-1,-10,0};

  auto comp = [](int a, int b){return a > b;}; //funcion lambda. El orden queda al reves por a>b
  
  std::sort(data.begin(), data.end(), comp); //la fl se puede poner aqui directamente en el lugar de comp
  for(int ii=0; ii<5;++ii){
    std::cout<<"data["<< ii <<"]: "<<data[ii]<<"\n";
  }
  return 0;
}
*/
//Para usar absoluto:
/*
int main(int argc, char **argv)
{
  std::vector<int> data={3,4,-1,-10,0};

  auto comp = [](int a, int b){return std::abs(a) < std::abs(b);}; //funcion lambda. El orden queda al reves por a>b
  
  std::sort(data.begin(), data.end(), comp); //la fl se puede poner aqui directamente en el lugar de comp
  for(int ii=0; ii<5;++ii){
    std::cout<<"data["<< ii <<"]: "<<data[ii]<<"\n";
  }
  return 0;
}
*/
//
int main()
{
  std::vector<int> c={1,2,3,4,5,6,8};

  std::cout<<"c:";
  std::for_each(c.begin(),c.end(),[](int i){std::cout<< i+1 <<" ";}); 
  std::cout<<"\n";

  return 0;
}
