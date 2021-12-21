// Напишете функция, която по даден едномерен масив с 16 елемента, въвежда елементите му в динамично заделена матрица 4 Х 4
// по стълбове.
#include <iostream>
#include <iomanip>
using namespace std;

void initializeMatrix(int **matrix, int n, int m)
{
    matrix = new int *[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[m];
}

void inputArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
}

void transferMatrix(int **matrix, int *arr, int n, int m)
{
    cout << "> Input matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            matrix[j][i] = arr[i * m + j];
}

void printMatrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << setw(3) << matrix[i][j];
        cout << endl;
    }
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

    inputArray(arr, n * m);
    transferMatrix(matrix, arr, n, m);
    printMatrix(matrix, n, m);

    deleteMatrix(matrix, n);
    delete[] arr;

    return 0;
}