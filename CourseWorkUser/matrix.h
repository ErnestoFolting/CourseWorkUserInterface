#pragma once
#include "Root.h"
#include "Polinom.h"
#include <vector>

class matrix
{
	int columns;
	int rows;
	int iterations;
	int counterMultiplies;
	Root r;
	std::vector<double> p;
	std::vector<double> areaOfRoots;
	std::vector<double**> vectorsY;
	std::vector<double**> vectorsX;
	double** system;
	double** q;
	double** MatrP;
	double** MatrBN;
	double** MatrB;
	double** Matr;
public:
	//*****�������*****//
	matrix(int n) :rows(n), columns(n), iterations(0), counterMultiplies(0) {} //����������� ��� ���������� �������
	matrix(int n, int m) :rows(n), columns(m), iterations(0), counterMultiplies(0) {} //����������� ��� ������� ������� ���������
	double** getMatr(); // ������ �� ������� �������
	void setMatr(double** tempMatr); // ������������ ������� �������
	int getRows(); // ������ �� �-�� �����
	static double** multiplyMatrix(double** Matr1, int n1, int m1, double** Matr2, int n2, int m2); //������������ �������
	static void toNorm(double** Matr, int rows); //���������� ������� �� ���� �������
	bool findRoots(); //����� ������ ����������������� �������
	std::vector<double> getAreaOfRoots(); // ������ �� ������, � ��� ����������� ����� �����
	int getIterations(); // ������ �� �-�� �������� �� ��� ����������
	int getMultiplies(); // ������ �� �-�� ����������� ������� �� ��� ����������
	void findAreaOfRoots(); // ����� ������, � ��� ����������� ����� �����
	Root getRoot(); //������ �� ������ ����������������� �������
	std::vector<double**> getVectorsX(); // ������ �� ������� ������� �������
	//*****����� �������������*****//
	bool Danilevsky(); //����� �������������
	std::vector<double> getP(); //������ �� ������� ��������� 
	static double** crIdentityMatrix(int n); //��������� �������� �������
	bool calculateMatrixB(int stage); // ���������� ������� B ������ �����
	static double** calculateMatrixBReverse(double** Matr, int n, int stage); // ���������� ��������� ������� B ������ �����
	bool calculateMatrixP(); //���������� ������� ����� ���������
	void createSelfVectors(); // ����� ������� �������
	//*****����� �������*****//
	bool Krylov(); //����� �������
	void setY0(double** vecY0); // ������������ ���������� �������
	void findSystem(); // ����� ������� ������ 
	bool Kramer(); // ����� �������
	static double det(double** matr, int N); // ����� ���������� �������
	void findQ(); // ����� ������� Q
	void findVectorsX(); // ����� ������� �������
	matrix operator*(double x); //���������� ��������� �������� ��� �������� ������� �� �����
	matrix operator+(matrix tempMatr); //���������� ��������� ��������� ��� ��������� ������� 
	matrix operator-(matrix tempMatr);//���������� ��������� �������� ��� �������� �������
	friend class fileWriter; // ������ ���� ��� ������ � �����
	friend class Polinom; // ������ ���� ��� ����������������� ������� �������
};

