#ifndef DERIVATIVE_APPROXIMATER_H
#define DERIVATIVE_APPROXIMATER_H

void printTable(double* ApproxResult, double* abs);

void makeCSV(double* approxResult, double* absErr);

// ordinarily it's not a good idea to return an
// array for data security however in this case it is fine.
//
// This function returns 30 derivates that act as the aproximation
// of f(x) starting at 2^-1 
void fPrime(double* approxResult);

#endif 
