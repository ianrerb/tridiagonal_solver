#ifndef TRISOLVER_H
#define TRISOLVER_H

#include<vector>
#include<iostream>
/*
 Solves equations of the form A*x = b for x, where A is a tridiagonal matrix:
    _		         _ 
   |d0 u0	          |
   |l0 d1 u1              |
A= |   l1 d2 u2           |
   |	  l2  . .         |
   |	      . . .       |
   |            . .  un-1 |
   |_           ln-1 dn  _|	      
 */
class TriMatrix {  
  friend std::vector<double> Solve(TriMatrix,std::vector<double>); //lets function access TriMatrix Structure
  
  public:
    TriMatrix(const std::size_t N_):N(N_),d(std::vector<double>(N_)), u(std::vector<double>(N_-1)), l(std::vector<double>(N_-1)){  };
    ~TriMatrix(){  };
    
    TriMatrix& Initialize(std::vector<double> d_, std::vector<double> u_, std::vector<double> l_){ 
    SetDiagonal(d_);
    SetUpper(u_);
    SetLower(l_);
    };
     
    TriMatrix& SetDiagonal(std::vector<double> vec){  
      if(vec.size() != N){ throw("Invalid Dimension for Diagonal Vector."); }
	d = vec;
	return *this;
      };
 
    TriMatrix& SetLower(std::vector<double> vec){  
      if(vec.size() != (N-1)){ throw("Invalid Dimension for Lower Vector."); }
	l = vec;
	return *this;
      };
    
    TriMatrix& SetUpper(std::vector<double> vec){  
      if(vec.size() != (N-1)){ throw("Invalid Dimension for Upper Vector."); }
	u = vec;
	return *this;
      };
    
    friend std::ostream& operator<<(std::ostream& out, TriMatrix& myMatrix){ 
      for(int i = 0; i!= myMatrix.N; ++i){  
	for(int j = 0; j!= myMatrix.N; ++j){
	  switch(i-j){  
	    case 0:
	      out<<myMatrix.d[i]<<" ";
	    break;

	    case 1:
	      out<<myMatrix.l[j]<<" ";
	    break;

	    case -1:
	      out<<myMatrix.u[i]<<" ";
	    break;

	    default:
	      out<<0<<" ";
	  }
	}
	out<<"\n";
      }
      out<<"\n";
      return out;
    };  
  
  private:
    std::vector<double> d, u, l;
    std::size_t N;
};
      

//tridiagonal solver
std::vector<double> inline Solve( TriMatrix TheMatrix, std::vector<double> b ){  
      if(TheMatrix.N != b.size()){ throw("Error: vector and matrix dimension do not match!"); }

      for(std::size_t i = 1; i!= TheMatrix.N; ++i){  
	  double temp = (TheMatrix.l[i-1]/TheMatrix.d[i-1]);
	  TheMatrix.d[i] -= TheMatrix.u[i-1]*temp;
	  b[i] -= b[i-1]*temp;
	  TheMatrix.l[i-1] = 0;
	}

      b.back() /= TheMatrix.d.back();
      if(TheMatrix.N == 1){ return b; }
      
      for(int i = (TheMatrix.N-2); i!=-1; --i){ 
	b[i] = (b[i] - TheMatrix.u[i]*b[i+1])/TheMatrix.d[i];
      }
      return b;  
    };

#endif

