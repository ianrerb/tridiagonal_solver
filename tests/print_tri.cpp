#include"../inc/tridiagonal.h"
#include<iostream>

using namespace std;

int main()
{ 
  TridiagonalMatrix matrix(10);
  for(int i =0; i!=10; i++){ 
    matrix(i,i) = 10;  
  } 
  cout<<matrix<<endl;
  return 0;  
}
