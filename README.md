StaticMatrix
============

There is no convenient way to create a generic 2D array in the C++ standard library.  Though there are many ways to do so, this implementation has the best features of each going for it:

* Dynamically resizable
* All elements sit in the same array line (single vector implementation for a considerable CPU cache performance boost)
* Generic template, meaning any type can be held
* Friend helper class to emulate overloading the non-existent operator [][]

This container class is very easy to work with, and shares many implementation methods with std::vector to resize, clear, push and erase data.

Here is an example driver:

```cpp
#include <iostream>
#include "staticmatrix.h"

int main()
{
    Zero::StaticMatrix<double> matrix(4, 4);
    matrix[0][0] = 1.5f;
    matrix[3][3] = 1.4f;

    std::cout << matrix[0][0] << std::endl;
    std::cout << matrix[3][3] << std::endl;

    for (auto &element : matrix)
        std::cout << element << std::endl;

    return 0;
}

```
