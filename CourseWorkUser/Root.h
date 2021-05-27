#pragma once
#define NMAX 20
#include <complex>
typedef std::complex<double> complexD;
class Root
{
    complexD mas[NMAX];
    int num;
public:
    int getNum();
    complexD* getMas();
    void setNum(int n);
};
