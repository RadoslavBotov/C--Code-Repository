// Напишете функция, която по въведени N и M, въвежда N*M цели числа и ги попълва в динамично заделен двумерен масив.
// Напишете и функция, която го принтира.
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
    cout << "> Input matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];
}

void printMatrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << matrix[i][j] << " ";
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
    int n, m;
    int **matrix;

    cin >> n >> m;

    initializeMatrix(matrix, n, m);

    inputMatrix(matrix, n, m);
    printMatrix(matrix, n, m);

    deleteMatrix(matrix, n);

    return 0;
}