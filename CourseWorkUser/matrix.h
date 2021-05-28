#pragma once
#include "Root.h"
#include "Polinom.h"
#include <vector>

class matrix
{
	int columns;
	double** system;
	std::vector<double> p;
	double** q;
	Root r;
	std::vector<double**> vectorsY;
	std::vector<double**> vectorsX;
	double** MatrP;
	double** MatrBN;
	int iterations;
	double** MatrB;
	int rows;
	double** Matr;
	std::vector<double> areaOfRoots;
public:
	void setY0(double** vecY0);
	double** getMatr();
	std::vector<double> getP();
	void setMatr(double** tempMatr);
	int getRows();
	matrix(int n):rows(n),columns(n){}
	matrix(int n, int m):rows(n),columns(m){}
	static double** multiplyMatrix(double** Matr1, int n1, int m1, double** Matr2, int n2, int m2);
	static double** crIdentityMatrix(int n);
	bool calculateMatrixB (int stage);
	static double** calculateMatrixBReverse(double** Matr, int n,int stage);
	bool calculateMatrixP();
	void createSelfVectors();
	static void toNorm(double** Matr, int rows);
	bool findRoots();
	void findSystem();
	void Kramer();
	static double det(double** matr, int N);
	std::vector<double> getAreaOfRoots();
	void findQ();
	void findVectorsX();
	bool Danilevsky();
	int getIterations();
	void findAreaOfRoots();
	bool Krylov();
	Root getRoot();
	std::vector<double**> getVectorsX();
 	matrix operator*(double x);
	matrix operator+(matrix tempMatr);
	matrix operator-(matrix tempMatr);
	friend class fileWriter;
	friend class Polinom;
};

