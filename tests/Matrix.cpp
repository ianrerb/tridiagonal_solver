#include"../inc/TriSolver.h"
#include<vector>
#include<iostream>

using namespace std;

int main(){  
  const size_t size = 10;
  vector<double> d(size);
  vector<double> u(size-1);
  for(int i = 0; i!= d.size(); i++){ 
    d[i] = i+1;
    if(i<u.size()){ u[i]=(i+1)*(i+1); }
  }
  vector<double> l = u;

  TriMatrix TheMatrix(size);

  TheMatrix.Initialize(d,u,l);
  cout<<TheMatrix;  
  vector<double> b = d;

  vector<double> x = Solve(TheMatrix,b);
  for(int i =0; i!=x.size(); i++){ 
    cout<<x[i]<<"\n";  
  }
  return 0;
  }
