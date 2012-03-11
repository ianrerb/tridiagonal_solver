#ifndef GRIDPOINT_H
#define GRIDPOINT_H

template<class T> class GridPoint {  
  public:
    GridPoint(){  };
    GridPoint(const T data_):data(data_){  };
    T& Data() { return data; };
    GridPoint& Data(const T data_){ data = data_; return *this; }
  
  private:
    T data;
};



#endif
