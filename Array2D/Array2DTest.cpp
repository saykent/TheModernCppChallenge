#include "Array2D.h"

void printArray2D(const Array2D<int, 2, 3>& array2D)
{
    for (int i = 0; i < array2D.size(1); ++i)
        for (int j = 0; j < array2D.size(2); ++j)
            std::cout << array2D(i, j) << " ";

    std::cout << std::endl;
}

int main()
{
    Array2D<int, 2, 3> array2D{1, 2, 3, 4, 5, 6};
    printArray2D(array2D);

    for (int i = 0; i < array2D.size(1); ++i)
        for (int j = 0; j < array2D.size(2); ++j)
            array2D(i, j) *= 2;

    printArray2D(array2D);


    std::copy(std::begin(array2D), std::end(array2D),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    Array2D<int, 2, 3> b;
    b.fill(1);
    printArray2D(b);

    array2D.swap(b);
    printArray2D(array2D);

    Array2D<int, 2, 3> c(std::move(b));
    printArray2D(c);

    const int* data = c.data();
    std::cout << *data << std::endl;
}