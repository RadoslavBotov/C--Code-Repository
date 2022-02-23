// Напишете функция, която по даден двумерен масив, връща едномерен масив от елементите му в нарастващ ред.
#include <iostream>
using namespace std;

void initializeMatrix(int **matrix, int n, int m)
{
    matrix = new int *[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m];
}

void inputMatrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matrix[i][j] = i * m + j + 1;
}

void transferMatrix(int **matrix, int *arr, int n, int m)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            arr[i * m + j] = matrix[i][j];
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
}

void deleteMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];

    delete[] matrix;
}

int main()
{
    int n = 4, m = 4;
    int *arr = new int[n * m];
    int **matrix;

    initializeMatrix(matrix, n, m);

    inputMatrix(matrix, n, m);
    transferMatrix(matrix, arr, n, m);
    printArray(arr, n * m);

    deleteMatrix(matrix, n);
    delete[] arr;

    return 0;
}