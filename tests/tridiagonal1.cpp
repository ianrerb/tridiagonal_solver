#include<iostream>
#include"../inc/tridiagonal.h"
using namespace std;

int main()
{ 
  TridiagonalMatrix matrix;
  cout<<matrix.Columns()<<endl;
  cout<<matrix.Rows()<<endl;
  
  matrix = TridiagonalMatrix(10);
  cout<<matrix.Columns()<<endl;
  cout<<matrix.Rows()<<endl;
  
  matrix(5,5) = 25;
  cout<<matrix(5,5)<<endl; 
   
  return 0;
}
