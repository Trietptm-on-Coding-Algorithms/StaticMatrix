StaticMatrix
============

There are many ways of creating a generic 2D array container in C++, but none conveniently from the standard library.  This implementation has a number of features going for it:

* Dynamically resizable
* All elements sit in the same array line (for a considerable CPU cache performance boost)
* Generic template, meaning any type can be held
* Friend helper class to emulate overloading the non-existent operator [][]

This class is very easy to work with, and shares many implementation methods with std::vector.

Here is an example driver:

```cpp
#include <iostream>
#include "staticmatrix.h"

int main()
{
    Zero::StaticMatrix<double> matrix(10, 10);
    matrix[0][0] = 1.5f;
    matrix[9][9] = 1.4f;

    std::cout << matrix[0][0] << std::endl;
    std::cout << matrix[9][9] << std::endl;

    return 0;
}
```
