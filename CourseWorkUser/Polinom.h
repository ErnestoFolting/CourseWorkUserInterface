#pragma once
#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include "Root.h"
typedef std::complex<double> complex;
#define NMAX 20
class Polinom
{
    int iterations;
    complex  mas[NMAX];
    int n;
public:
    static complex FPol(Polinom& p, complex& x);
    bool FindAllRoot( Root& r);
    Polinom(double** Matr, int n);
    Polinom(std::vector<double>);
    Polinom() :n(0) {};
    int getIterations();

};

