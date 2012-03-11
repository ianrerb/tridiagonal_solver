#include"../inc/OptionGrid.h"
#include<iostream>

using namespace std;

int main(){ 
  OptionGrid testgrid(1,1);
  testgrid.SpaceDomain(3,4).Expiry(5);
  cout<<testgrid.LowerBound()<<" "<<testgrid.UpperBound()<<" "<<testgrid.Expiry()<<endl;
  
  
  return 0;
}
