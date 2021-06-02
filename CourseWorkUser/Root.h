#pragma once
#define NMAX 20
#include <complex>
typedef std::complex<double> complexD;
class Root
{
    complexD mas[NMAX];
    int num;
public:
    int getNum(); // доступ до кількості коренів 
    complexD* getMas(); // доступ до масиву коренів 
    void setNum(int n); // встановлення к-сті коренів 
};
