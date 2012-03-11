#ifndef TRIDIAGONAL_H
#define TRIDIAGONAL_H

#include"myMatrix.h"
#include<vector>
#include<iostream>

class TridiagonalMatrix : public matrix_base
{  
  public:
    TridiagonalMatrix( unsigned int size_ = 0 );

    double& operator()( unsigned int, unsigned int );
    unsigned int Columns() const;
    unsigned int Rows() const;  
    
    friend std::ostream& operator<<( std::ostream&, TridiagonalMatrix& ); 
  
  private:
    unsigned int size;
    std::vector<double> diag, upper, lower;
};

#endif
