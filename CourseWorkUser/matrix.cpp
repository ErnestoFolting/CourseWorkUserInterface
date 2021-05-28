#include "matrix.h"
#include "Validator.h"
#include "fileWriter.h"
#include <complex>
#include <vector>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
typedef std::complex<double> complex;
double** matrix::multiplyMatrix(double** Matr1, int n1, int m1, double** Matr2, int n2, int m2)
{
	if (Validator::canMultiplyMatrix(m1, n2)) {
		double** Matr = new double* [n1];
		for (int i = 0; i < n1; i++) {
			Matr[i] = new double[m2];
		}
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < m2; j++) {
				Matr[i][j] = 0;
				for (int k = 0; k < n2; k++) {
					Matr[i][j] += Matr1[i][k] * Matr2[k][j];
				}
				Matr[i][j] = round(Matr[i][j] * 1000) / 1000;
			}
		}
		return Matr;
	}
}

double** matrix::crIdentityMatrix(int n)
{
	double** Matr = new double* [n];
	for (int i = 0; i < n; i++) {
		Matr[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Matr[i][j] = 1;
			}
			else {
				Matr[i][j] = 0;
			}
		}
	}
	return Matr;
}

bool matrix::calculateMatrixB(int stage)
{
	MatrB = crIdentityMatrix(rows);
	for (int j = 0; j < rows; j++) {
		if (abs((Matr[rows - stage][rows - stage - 1] - 0)) < 1e-10) {
			MessageBox::Show("При обчисленні виникає ділення на 0\nСпробуйте іншу матрицю.", "Помилка");
			return 0;
		}
		if (j == rows - stage-1) {
			MatrB[rows - stage - 1][rows - stage - 1] = 1 / (Matr[rows-stage][rows - stage - 1]);
		}
		else {
			MatrB[rows - stage - 1][j] = -1 * (Matr[rows-stage][j] / Matr[rows-stage][rows - stage - 1]);
		}
	}
	if (stage == 1) {
		MatrBN = MatrB;
	}
	else {
		MatrBN = multiplyMatrix(MatrBN, rows, rows, MatrB, rows, rows);
	}
	return 1;
}

double** matrix::calculateMatrixBReverse(double** Matr, int n,int stage)
{
	double** MatrReverse = crIdentityMatrix(n);
	for (int i = 0; i < n; i++) {
		MatrReverse[n-stage -1 ][i] = Matr[n - stage][i];
	}
	return MatrReverse;
}
bool matrix::calculateMatrixP() {
	double** MatrD = Matr;
	vector<double> p;
	int k = 0;
	for (int i = 1; i < rows; i++) {
		if (calculateMatrixB(i)) {
			double** MatrBReverse = calculateMatrixBReverse(Matr, rows, i);
			MatrD = matrix::multiplyMatrix(matrix::multiplyMatrix(MatrBReverse, rows, rows, Matr, rows, rows), rows, rows, MatrB, rows, rows);
			Matr = MatrD;
			double currentD;
			if (rows - 3 - k >= 0) {
				currentD = MatrD[rows - i - 1][rows - 3 - k];
			}
			k++;
		}
		else {
			return 0;
		}
		
	}
	for (int i = 0; i < rows; i++) p.push_back(MatrD[0][i]);
	this->p = p;
	return 1;
}
bool matrix::Danilevsky() {
	fileWriter::outputMatr(*this);
	findAreaOfRoots();
	if (calculateMatrixP()) {
		if (findRoots()) {
			createSelfVectors();
			fileWriter::outputSelf(*this);
			fileWriter::outputStatistic(*this);
			return 1;
		}
		else {
			fileWriter::outputError();
			return 0;
		}
	}
	else {
		fileWriter::outputError();
		return 0;
	}
}

int matrix::getIterations()
{
	return iterations;
}

void matrix::findAreaOfRoots()
{
	vector<double> area;
	for (int i = 0; i < rows; i++) {
		double sum = 0;
		for (int j = 0; j < rows; j++) {
			if (i != j)sum += abs(Matr[i][j]);
		}
		area.push_back(Matr[i][i] - sum);
		area.push_back(Matr[i][i] + sum);
	}
	this->areaOfRoots = area;
}

bool matrix::Krylov() {
	fileWriter::outputMatr(*this);
	findAreaOfRoots();
	findSystem();
	Kramer();
	if (findRoots()) {
		findQ();
		findVectorsX();
		fileWriter::outputSelf(*this);
		fileWriter::outputStatistic(*this);
		return 1;
	}
	fileWriter::outputError();
	return 0;
}
Root matrix::getRoot()
{
	return r;
}
std::vector<double**> matrix::getVectorsX()
{
	return vectorsX;
}
void matrix::createSelfVectors() {
	for (int i = 0; i < rows; i++) {
		double** tempMatr = new double*[rows];
		for (int j = 0; j < rows; j++) {
			tempMatr[j] = new double[1];
		}
		for (int k = 0; k < rows; k++) {
			double temp = real(r.getMas()[i]);
			tempMatr[k][0] = round(pow(temp, rows - k - 1)*1000)/1000;
		}
		double** tempMatr2 = matrix::multiplyMatrix(MatrBN, rows, rows, tempMatr, rows, 1);
		matrix::toNorm(tempMatr2, rows);
		vectorsX.push_back(tempMatr2);
	}
}
void matrix::setY0(double** vecY0)
{
	this->vectorsY.push_back(vecY0);
}
double** matrix::getMatr()
{
	return Matr;
}
void matrix::setMatr(double** tempMatr)
{
	Matr = tempMatr;
}
int matrix::getRows() {
	return rows;
}
void matrix::toNorm(double** Matr, int rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += pow(Matr[i][0], 2);
	}
	sum = sqrt(sum);
	for (int i = 0; i < rows; i++) {
		Matr[i][0] = round(Matr[i][0] / sum*1000)/1000;
	}
}
void matrix::findSystem() {
	double** startVector2 = new double* [rows];
	double** system = new double* [rows];
	for (int i = 0; i < rows; i++) {
		startVector2[i] = new double[1];
		system[i] = new double[rows + 1];
	}
	for (int i = 0; i < rows; i++) {
		startVector2[i][0] = vectorsY[0][i][0];
	}
	for (int i = 0; i < rows; i++) {
		system[i][rows - 1] = startVector2[i][0];
	}
	for (int i = 0; i < rows; i++) {
		startVector2 = matrix::multiplyMatrix(Matr, rows, rows, startVector2, rows, 1);
		vectorsY.push_back(startVector2);
		for (int j = 0; j < rows; j++) {
			system[j][(rows - 2) - i] = startVector2[j][0];
		}
	}
	for (int i = 0; i < rows; i++) {
		system[i][rows] = startVector2[i][0];
	}
	this->system = system;
}
void matrix::Kramer() {
	double** roots = new double* [rows];
	double** main = new double* [rows];
	for (int i = 0; i < rows; i++) {
		roots[i] = new double[1];
		roots[i][0] = system[i][rows];
		main[i] = new double[rows];
		for (int j = 0; j < rows; j++) {
			main[i][j] = system[i][j];
		}
	}
	double mainDet = det(main, rows);
	for (int l = 0; l < rows; l++) {
		double** tempMatr = new double* [rows];
		for (int k = 0; k < rows; k++)tempMatr[k] = new double[rows];
		for (int j = 0; j < rows; j++) {
			for (int i = 0; i < rows; i++) {
				if (j != l) {
					tempMatr[i][j] = main[i][j];
				}
				else {
					tempMatr[i][j] = roots[i][0];
				}
			}
		}
		double tempDet = det(tempMatr, rows);
		double root = round(tempDet / mainDet*1000)/1000;
		this->p.push_back(root);
	}
}
std::vector<double> matrix::getP() {
	return p;
}
double matrix::det(double** Matr, int N)
{
	double determ;
	int sub, s;
	double** Matr2;
	if (N < 1) return nan("1");
	if (N == 1)
		return Matr[0][0];
	if (N == 2)
		return Matr[0][0] * Matr[1][1] - Matr[0][1] * Matr[1][0];
	else {

		Matr2 = new double* [N - 1];
		determ = 0;
		s = 1;
		for (int i = 0; i < N; i++)
		{
			sub = 0;
			for (int j = 0; j < N; j++)
				if (i != j)
					Matr2[sub++] = Matr[j] + 1;

			determ = determ + s * Matr[i][0] * det(Matr2, N - 1);
			s = -s;
		};
		delete[] Matr2;
		return determ;
	}
}
std::vector<double> matrix::getAreaOfRoots()
{
	return areaOfRoots;
}
void matrix::findQ() {
	double** q = new double* [rows];
	for (int i = 0; i < rows; i++) {
		q[i] = new double[rows];
	}
	for (int j = 0; j < rows; j++) {
		for (int i = 0; i < rows; i++) {
			if (i == 0) {
				q[i][j] = 1;
			}
			else {
				q[i][j] = real(r.getMas()[j]) * q[i - 1][j] - p[i-1];
			}
		}
	}
	this->q = q;
}

void matrix::findVectorsX() {
	ofstream outFile("result.txt", ios::app);
	outFile << "Y0: " << endl;
	for (int i = 0; i < rows; i++) {
		outFile << this->vectorsY[0][i][0] << endl;
	}
	outFile.close();
	for (int i = 0; i < rows; i++) {
		matrix tempRes(rows,1);
		for (int k = 0; k < rows; k++) {
			matrix tempY(rows,1);
			tempY.Matr = vectorsY[rows - 1 - k];
			if (k == 0) {
				tempRes = tempY * q[k][i];
			}
			else {
				tempRes = tempRes + tempY * q[k][i];
			}
		}
		toNorm(tempRes.Matr, rows);
		vectorsX.push_back(tempRes.Matr);
	}
}

matrix matrix::operator*(double x)
{
	matrix newMatr(rows, columns);
	newMatr.Matr = new double*[rows];
	for (int i = 0; i < rows; i++){
		newMatr.Matr[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			newMatr.Matr[i][j] = this->Matr[i][j] * x;
		}
	}
	return newMatr;
}

matrix matrix::operator+(matrix tempMatr)
{
	matrix newMatr(rows, columns);
	newMatr.Matr = new double* [rows];
	for (int i = 0; i < rows; i++) {
		newMatr.Matr[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			newMatr.Matr[i][j] = Matr[i][j] + tempMatr.Matr[i][j];
		}
	}
	return newMatr;
}

matrix matrix::operator-(matrix tempMatr)
{
	matrix newMatr(rows, columns);
	newMatr.Matr = new double* [rows];
	for (int i = 0; i < rows; i++) {
		newMatr.Matr[i] = new double[columns];
		for (int j = 0; j < columns; j++) {
			newMatr.Matr[i][j] = Matr[i][j] - tempMatr.Matr[i][j];
		}
	}
	return newMatr;
}
bool matrix::findRoots() {
	Polinom polinom(this->p);
	Root r;
	if (polinom.FindAllRoot(r)) {
		this->r = r;
		this->iterations = polinom.getIterations();
		return 1;
	}
	else {
		return 0;
	}

}