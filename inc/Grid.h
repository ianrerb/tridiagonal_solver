#ifndef GRID_H
#define GRID_H

#include<vector>
#include<iostream>
#include"Grid.h"

//interface for concrete grid classes
template<class T> class Grid { 
  public:
    Grid(unsigned const int rows=0, const unsigned int cols=0):_rows(rows), _columns(cols){ _values=std::vector<T>(rows*cols); };
    ~Grid(){  };

    T& operator()(const unsigned int i, const unsigned int j){  return _values[i*_columns +j]; };
    unsigned int Rows() const{  return _rows; };
    virtual unsigned int Columns() const{  return _columns; };

  friend std::ostream& operator<<( std::ostream& out, Grid<T>& myGrid ){  
    for(int i= 0; i!=myGrid.Rows(); i++){ 
      for(int j = 0; j!=myGrid.Columns(); j++){ 
	out<<myGrid(i,j)<<" ";
      }
      out<<"\n";
    }  
    return out;
  } 
  
  private:
    unsigned int _rows, _columns;
    std::vector<T> _values;
};

#endif
