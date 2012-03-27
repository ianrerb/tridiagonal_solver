#include "../inc/Option.h"

double EuropeanCall::Payoff(const double spot) const {  return (spot > strike ? spot - strike : 0); }
