#include"../inc/OptionGrid.h"

//ctor & dtor
OptionGrid::OptionGrid(unsigned int M_, unsigned int N_):N(N_), M(M_),LowX(0),HighX(0),Tau(0) { Reset(); }
OptionGrid::~OptionGrid(){  };

//accessor grid(row,col)
GridPoint<double>& OptionGrid::operator()(unsigned int row, unsigned int col){ return Points[row*N+col]; }

//sets range of X values
OptionGrid& OptionGrid::SpaceDomain(const double min, const double max){ 
  if(max < min) { throw("Invalid space domain."); }
  LowX = min;
  HighX = max;
  Reset();
  return *this;  
}

OptionGrid& OptionGrid::Expiry(const double T){ 
  Tau = T; 
  Reset(); 
  return *this; 
}

void OptionGrid::Reset(){ 
  GridPoint<double> temp(0);
  Points = std::vector<GridPoint<double> >(N*M,temp); 
  DeltaX = ( HighX - LowX )/static_cast<double>(N);
  DeltaTau = Tau/static_cast<double>(M);    
}

std::ostream& operator<<( std::ostream& out, OptionGrid& myGrid ){ 
  for(int j= 0; j!=myGrid.M; j++){ 
    for(int i = 0; i!=myGrid.N; i++){ 
      out<<myGrid.Points[j*myGrid.N+i].Data()<<" ";
      }
    out<<"\n";
    }  
  return out;
}
