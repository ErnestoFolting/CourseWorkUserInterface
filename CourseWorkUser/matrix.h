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
	//*****Загальні*****//
	matrix(int n) :rows(n), columns(n), iterations(0), counterMultiplies(0) {} //конструктор для квадратних матриць
	matrix(int n, int m) :rows(n), columns(m), iterations(0), counterMultiplies(0) {} //конструктор для матриць довільної розмірності
	double** getMatr(); // доступ до основної матриці
	void setMatr(double** tempMatr); // встановлення основної матриці
	int getRows(); // доступ до к-сті рядків
	static double** multiplyMatrix(double** Matr1, int n1, int m1, double** Matr2, int n2, int m2); //перемноження матриць
	static void toNorm(double** Matr, int rows); //нормування матриці на свою довжину
	bool findRoots(); //пошук коренів характеристичного поліному
	std::vector<double> getAreaOfRoots(); // доступ до області, в якій знаходяться власні числа
	int getIterations(); // доступ до к-сті ітерацій під час обчислення
	int getMultiplies(); // доступ до к-сті перемножень матриці під час обчислення
	void findAreaOfRoots(); // пошук області, в якій знаходяться власні числа
	Root getRoot(); //доступ до коренів характеристичного поліному
	std::vector<double**> getVectorsX(); // доступ до власних векторів матриці
	//*****Метод Данилевського*****//
	bool Danilevsky(); //метод Данилевського
	std::vector<double> getP(); //доступ до матриці Фробеніуса 
	static double** crIdentityMatrix(int n); //створення одиничної матриці
	bool calculateMatrixB(int stage); // обчислення матриці B одного етапу
	static double** calculateMatrixBReverse(double** Matr, int n, int stage); // обчислення оберненоъ матриці B одного етапу
	bool calculateMatrixP(); //обчислення матриці форми Фробеніуса
	void createSelfVectors(); // пошук власних векторів
	//*****Метод Крилова*****//
	bool Krylov(); //метод Крилова
	void setY0(double** vecY0); // встановлення стартового вектора
	void findSystem(); // пошук системи рівнянь 
	bool Kramer(); // метод Крамера
	static double det(double** matr, int N); // пошук визначника матриці
	void findQ(); // пошук матриці Q
	void findVectorsX(); // пошук власних векторів
	matrix operator*(double x); //перегрузка оператора множення для множення матриці на число
	matrix operator+(matrix tempMatr); //перегрузка оператора додавання для додавання матриць 
	matrix operator-(matrix tempMatr);//перегрузка оператора віднімання для віднімання матриць
	friend class fileWriter; // дружній клас для виводу в файлу
	friend class Polinom; // дружній клас для характеристичного поліному матриці
};

