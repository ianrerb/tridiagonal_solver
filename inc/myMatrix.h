#ifndef MYMATRIX_H
#define MYMATRIX_H

class matrix_base 
{ 
  public:
    virtual double& operator()( unsigned int, unsigned int ) = 0;
    virtual unsigned int Columns() const = 0;
    virtual unsigned int Rows() const = 0;
};
#endif
