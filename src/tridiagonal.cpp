#include"../inc/tridiagonal.h"
#include<cmath>

TridiagonalMatrix::TridiagonalMatrix(unsigned int size_) : size(size_) 
{ 
  if(size != 0){  
    diag = std::vector<double>(size,0);
    upper = lower = std::vector<double>(size-1,0);
  }
}

double& TridiagonalMatrix::operator()(unsigned int r, unsigned int c)
{ 
  if(r >= size || c >= size){ throw( "Index out of bounds." ); }
  int ival = r-c;
  
  switch(ival){ 
    case 0:
      return diag[c];
    break;
    
    case 1:
      return lower[c];  
    break;

    case -1:
      return upper[r];
    break;

    default:
      throw("Index out of bounds.");
  }
}

unsigned int TridiagonalMatrix::Columns() const 
{ 
  return size;
}

unsigned int TridiagonalMatrix::Rows() const 
{ 
  return size;
}

std::ostream& operator<<(std::ostream& out, TridiagonalMatrix& matrix)
{ 
  for(int i = 0; i!= matrix.Rows(); i++){ 
    for(int j = 0; j!= matrix.Columns(); j++){ 
      if(std::abs(i-j)<2){
	if(j != (matrix.Rows()-1)) { out<<matrix(i,j)<<" "; } else { out<<matrix(i,j)<<"\n"; }
      }else { 
	if(j!= (matrix.Rows()-1)) { out<<0<<" "; } else { out<<0<<"\n"; }
      }
    }
  }
  return out;
}
