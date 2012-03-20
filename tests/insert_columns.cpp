#include"../inc/Grid.h"
#include<vector>
#include<iostream>

using namespace std;

int main(){  
  Grid<int> TheGrid(3,3);
  
  vector<int> c0(3,1);
  vector<int> c1(3,2);
  vector<int> c2(3,3);
 
  TheGrid.InsertColumn(c0,0);
  TheGrid.InsertColumn(c1,1);
  TheGrid.InsertColumn(c2,2);
  
  cout<<TheGrid<<endl;  
   
  return 0;  
}
