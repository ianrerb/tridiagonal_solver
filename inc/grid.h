#ifndef GRID_H
#define GRID_H

#include"GridPoint.h"

//interface for concrete grid classes
template<class T> class grid_base { 
  public:
    virtual GridPoint<T>& operator()(unsigned int, unsigned int) = 0;
    virtual unsigned int Rows() const = 0;
    virtual unsigned int Columns() const = 0;
};

#endif
