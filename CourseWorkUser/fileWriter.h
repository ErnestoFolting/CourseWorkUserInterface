#pragma once
#include "matrix.h"
#include <fstream>
#include <iomanip>
using namespace std;
class fileWriter
{
public:
	static void outputSelf(matrix tempMatr); //вивід в файл власних чисел, векторів та коефіцієнтів
	static void outputMatr(matrix tempMatr); //вивід в файл початкової матриці
	static void outputStatistic(matrix tempMatr); //вивід в файл статистики складності
	static void outputError(); //вивід в файл повідомлення про помилку
};

