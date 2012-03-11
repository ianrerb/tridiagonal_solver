#ifndef OPTION_H
#define OPTION_H

class Option {  
  public:
    Option(const double K):strike(K),premium(0){  };
    
    virtual double Payoff(const double) const = 0;
    double Premium() const { return premium; };
    double Strike() const { return strike; };
    
    Option& Strike(const double k){  strike=k; return *this; };
    Option& Premium(const double x){ premium=x; return *this; };

  protected:
    double strike, premium;
};

class EuropeanPut : public Option {  
  public:
    EuropeanPut(const double K):Option(K){  };
    ~EuropeanPut(){  };
    
    double Payoff(const double spot) const;
};
#endif
