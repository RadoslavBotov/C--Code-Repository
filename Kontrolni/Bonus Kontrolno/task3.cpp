#include <iostream>
using namespace std;

int **allocateMemmory(int n, int m)
{
    int **matrix = new int *[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new int[m];

    return matrix;
}

void deleteMatrixMemmory(int **matrix, int n, int m)
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

bool isRowValid(int **matrix, int indexRow, int m)
{
    for (int j = 0; j < m; j++)
        if ((matrix[indexRow][j] % 2 != 0) || (matrix[indexRow][j] >= 6))
            return false;
    return true;
}

bool isColValid(int **matrix, int n, int indexCol)
{
    for (int i = 0; i < n; i++)
        if ((matrix[i][indexCol] % 2 != 0) || (matrix[i][indexCol] >= 6))
            return false;
    return true;
}

void sumOfRowAndCollum(int **matrix, int n, int m)
{
    int validRows = 0, p = 0;
    int *validRowIndex = new int[n];

    int validCols = 0, q = 0;
    int *validColIndex = new int[m];

    for (int i = 0; i < n; i++)
        if (isRowValid(matrix, i, m))
        {
            validRows++;
            validRowIndex[p] = i;
            p++;
        }

    for (int j = 0; j < m; j++)
        if (isColValid(matrix, n, j))
        {
            validCols++;
            validColIndex[q] = j;
            q++;
        }

    if (validRows == 0 || validCols == 0)
        cout << "There are no rows and/or collums that match the conditions.";
    else
    {
        int currentSum = 0;
        int maxSum = 0;

        for (int i = 0; i < p; i++)
        {
            for (int j = 0; j < q; j++)
            {
                for (int r = 0; r < n; r++)
                    currentSum += matrix[r][validColIndex[j]];

                for (int k = 0; k < m; k++)
                    currentSum += matrix[validRowIndex[i]][k];
                if (currentSum > maxSum)
                    maxSum = currentSum;

                currentSum = 0;
            }
        }

        cout << "Sum = " << maxSum;
    }

    delete[] validRowIndex;
    delete[] validColIndex;
}

int main()
{
    int n, m;
    cout << "> N, M: ";
    cin >> n >> m;

    int **matrix = allocateMemmory(n, m);

    inputMatrix(matrix, n, m);

    sumOfRowAndCollum(matrix, n, m);

    deleteMatrixMemmory(matrix, n, m);

    return 0;
}