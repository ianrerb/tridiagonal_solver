#ifndef GRID_H
#define GRID_H
#include<vector>
#include<iostream>

// Grid(row index, col index)
// Rows()
// Columns()
// Column(index)
// InsertColumn(vector,index)
// << operator

template<class T> class Grid { 
  public:
    Grid(unsigned const int rows=0, const unsigned int cols=0):_rows(rows), _columns(cols){ _values=std::vector<T>(rows*cols); };
    ~Grid(){  };

    T& operator()(const unsigned int i, const unsigned int j){  return _values[i*_columns +j]; };
    unsigned int Rows() const{  return _rows; };
    virtual unsigned int Columns() const{  return _columns; };
    std::vector<T> Column(size_t index){ 
      if(index >=_columns){ throw("Index out of Range."); }
      std::vector<T> temp;
      for(size_t i = 0; i!= _rows; ++i)
	temp.push_back((*this)(i,index));
	return temp;  
    }
    
    Grid& InsertColumn(std::vector<T> &c,size_t index){ 
      if(c.size()!=_rows|| (index >= _columns)){ throw("Invalid Grid Operation."); }
      for(size_t i = 0; i!= c.size(); ++i)
	(*this)(i,index) = c[i];
      return *this;
    };

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
