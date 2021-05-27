#include "Validator.h"


bool Validator::fileOpenCheck(ifstream& in)
{
    if (!in) {
        return false;
    }
    return true;
}

bool Validator::canMultiplyMatrix(int m1, int m2)
{
    if (m1 == m2) return true;
    return false;
}
