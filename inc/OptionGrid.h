#ifndef OPTIONGRID_H
#define OPTIONGRID_H

#include<iostream>
#include<vector>
#include"grid.h"

class OptionGrid : public grid_base<double> {  
  public:
    OptionGrid(const unsigned int, const unsigned int);
    ~OptionGrid();
    GridPoint<double>& operator()(unsigned int, unsigned int);

    OptionGrid& SpaceDomain(const double, const double);
    OptionGrid& Expiry(const double);
    
    double LowerBound() const {  return LowX; };
    double UpperBound() const {  return HighX; };
    double Expiry() const {  return Tau; };

    unsigned int Rows() const {  return M; };
    unsigned int Columns() const { return N; }

    void Reset();
    
    friend std::ostream& operator<<( std::ostream&, OptionGrid& );
         
  private:
    unsigned int N, M;
    double LowX, HighX, Tau, DeltaX, DeltaTau;
    std::vector<GridPoint<double> > Points;
};
#endif
