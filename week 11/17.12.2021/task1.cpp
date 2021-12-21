/*
Write a program that reads a number N from STDIN (1 < N < 11) and subsequently reads from STDIN the numbers comprising a NxN matrix A.
At the end of the program write on STDOUT the product of all even numbers that are greater than 0 and are above the main diagonal of A.
*/
#include <iostream>
using namespace std;

void initMatrix(int **matrix, int size)
{
    matrix = new int *[size];

    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

void deleteMatrix(int **matrix, int size)
{
    for (int i = 0; i < size; ++i)
        delete[] matrix[i];

    delete[] matrix;
}

void inputMatrix(int **matrix, int size)
{
    cout << "> Input matrix:\n";

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            cin >> matrix[i][j];
}

int func(int **matrix, int size)
{
    int product = 0;

    for (int i = 0; i < size; ++i)
        for (int j = i; j < size; ++j)
            if (matrix[i][j] % 2 == 0)
                product *= matrix[i][j];

    return product;
}

int main()
{
    int n;
    int **matrix;

    cout << "> N: ";
    cin >> n;

    initMatrix(matrix, n);
    inputMatrix(matrix, n);

    cout << "< Product = " << func(matrix, n);

    deleteMatrix(matrix, n);

    return 0;
}