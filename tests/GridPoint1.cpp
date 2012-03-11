#include"../inc/GridPoint.h"

#include<iostream>
using namespace std;

int main(){ 
  GridPoint<double> point1;
  point1.Data()=2.5;
  cout<<point1.Data()<<endl; //2.5

  GridPoint<double> point2(3.5);  
  cout<<point1.Data()<<endl; // 3.5

  GridPoint<double> point3 = point2.Data(4.5);

  cout<<point3.Data()<<endl; //4.5
  cout<<point2.Data()<<endl;

  /* output file:
  0
  2.5
  3.5
  4.5
  4.5 
  */

  return 0;
}
