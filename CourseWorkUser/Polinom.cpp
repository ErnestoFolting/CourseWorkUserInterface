#include "Polinom.h"
#include <fstream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
complex Polinom::FPol(Polinom& p, complex& x)
{
    int i;
    complex tmp = complex(0, 0);

    for (i = 0; i <= p.n; i++)
        tmp = tmp + pow(x, i) * p.mas[i];

    return tmp;
}

bool Polinom::FindAllRoot(Root& r)
{
    int i, j;
    complex x1, x0;
    Polinom defp;
    r.setNum(n);
    int counter = 0;
    for (i = 0; i < r.getNum(); i++)
    {
        defp.n = n - 1;

        for (j = 0; j < n; j++)
            defp.mas[j] = mas[j + 1] * complex(j + 1);

        x1 = complex(1, 1);
        
        do
        {
            x0 = x1;
            counter++;
            x1 = x0 - Polinom::FPol(*this, x0) / Polinom::FPol(defp, x0);
        } while (abs(Polinom::FPol(*this, x1)) > 1e-12);
       
        if (isnan(real(x1))) {
            MessageBox::Show("Не вдалось знайти власні числа.\n Можливо Ви не ввели всі коефіцієнти\nСпробуйте іншу матрицю.", "Помилка");
            return 0;
        }
        if (imag(x1) > 1e-10) {
            MessageBox::Show("При обчисленні виникають комплексні корені.\nСпробуйте іншу матрицю.", "Помилка");
            return 0;
        }
        r.getMas()[i] = x1;
        

        for (j = n - 1; j >= 0; j--) mas[j] = mas[j] + mas[j + 1] * x1;
        for (j = 0; j < n; j++) mas[j] = mas[j + 1];
        n--;
    }
    this->iterations = counter;
    return 1;
}
Polinom::Polinom(double** Matr, int columns) {
    n = columns;
    int k = 0;
    for (int i = columns-1; i >= 0; i--) {
        mas[k] = (-1)*Matr[0][i];
        k++;
    }
    mas[columns] = 1;
}

Polinom::Polinom(std::vector<double> p)
{
    n = p.size();
    int k = 0;
    for (int i = p.size() - 1; i >= 0; i--) {
        mas[k] = (-1) * p[i];
        k++;
    }
    mas[p.size()] = 1;
}

int Polinom::getIterations()
{
    return iterations;
}
