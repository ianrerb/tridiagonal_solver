#ifndef OPTION_H
#define OPTION_H

class Option {  
  public:
    Option(const double K,const double T):strike(K),expiry(T),premium(0){  };
    virtual ~Option(){  };
     
    virtual double Payoff(const double) const = 0;
    double Premium() const { return premium; };
    double Strike() const { return strike; };
    double Expiry() const {  return expiry;  };

    Option& Strike(const double k){  strike=k; return *this; };
    Option& Premium(const double x){ premium=x; return *this; };
    Option& Expiry(const double t){  expiry=t; return *this; };
  
  protected:
    double strike, premium, expiry;
};

class EuropeanPut : public Option {  
  public:
    EuropeanPut(const double K, const double T):Option(K,T){  };  
    ~EuropeanPut(){  };
    double Payoff(const double spot) const;
};

class EuropeanCall : public Option {  
  public:
    EuropeanCall(const double K, const double T):Option(K,T){  };
    ~EuropeanCall(){  }
    double Payoff(const double spot) const;  
};

#endif
