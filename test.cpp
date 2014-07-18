#include <iostream>
#include "staticmatrix.h"

int main()
{
    Zero::StaticMatrix<double> mat(10, 10);
    mat[0][0] = 1.5f;
    mat[9][9] = 1.4f;

    std::cout << mat[0][0] << std::endl;
    std::cout << mat[9][9] << std::endl;

    return 0;
}

