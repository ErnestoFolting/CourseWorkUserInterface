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
    static complex FPol(Polinom& p, complex& x); // підрахунок значення функції для заданого аргумента
    bool FindAllRoot( Root& r); // функція пошуку всіх коренів
    Polinom(double** Matr, int n); // конструктор для поліному з матриці Фробеніуса
    Polinom(std::vector<double>); // конструктор для поліному з вектору коефіцієнтів
    Polinom() :n(0) {}; // конструктор за замовчуванням
    int getIterations(); // доступ до к-сті ітерація для відділення коренів

};

