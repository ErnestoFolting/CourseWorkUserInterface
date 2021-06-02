#pragma once
#include <fstream>
#include <iostream>
using namespace std;
class Validator
{
public:
	static bool fileOpenCheck(ifstream& in); // перевірка чи був відкритий файл
	static bool canMultiplyMatrix(int m1, int m2); // перевірка чи можна перемножати матриці
};

