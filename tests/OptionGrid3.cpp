#include"../inc/OptionGrid.h"

using namespace std;

int main(){ 
  OptionGrid grid(10,20);
  for(int i = 0; i!= grid.Rows(); i++){ 
    for(int j = 0; j!=grid.Columns(); j++){ 
      grid(i,j).Data( static_cast<double>(i)/static_cast<double>(j+1) );  
    }
  }
  cout<<grid<<endl;
  return 0;  
}
