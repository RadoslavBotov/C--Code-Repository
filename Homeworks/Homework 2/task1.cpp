#include <iostream>
using namespace std;

void inputMatrixSize(int &N1, int &M1, int &N2, int &M2)
{
    do
    {
        std::cout << "> N1: ";
        std::cin >> N1;
    } while (N1 <= 0);

    do
    {
        std::cout << "> M1: ";
        std::cin >> M1;
    } while (M1 <= 0);

    do
    {
        std::cout << "> N2: ";
        std::cin >> N2;
    } while (N2 <= 0);

    do
    {
        std::cout << "> M2: ";
        std::cin >> M2;
    } while (M2 <= 0);
}

int **allocateMatrixMemmory(int n, int m)
{
    int **matrix = new int *[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    return matrix;
}

void deleteMatrixMemmory(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;
}

void inputMatrix(int **matrix, int n, int m)
{
    cout << "> Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
}

void printMatrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}

void transformMatrix(int **matrixA, int **matrixB, int &N1, int &M1, int N2, int M2)
{
    if (N2 < N1)
        N1 = N2;

    if (M2 < M1)
        M1 = M2;

    for (int i = 0; i < N1; i++)
        for (int j = 0; j < M1; j++)
            if (matrixA[i][j] < matrixB[i][j])
                matrixA[i][j] = matrixB[i][j];
            else if (matrixA[i][j] > matrixB[i][j])
                matrixA[i][j] *= -1;

    std::cout << std::endl;
    printMatrix(matrixA, N1, M1);
}

int main()
{
    int N1, M1, N2, M2;
    inputMatrixSize(N1, M1, N2, M2);

    int **matrixA = allocateMatrixMemmory(N1, M1);
    int **matrixB = allocateMatrixMemmory(N2, M2);

    inputMatrix(matrixA, N1, M1);
    inputMatrix(matrixB, N2, M2);

    transformMatrix(matrixA, matrixB, N1, M1, N2, M2);

    deleteMatrixMemmory(matrixA, N1);
    deleteMatrixMemmory(matrixB, N2);

    return 0;
}