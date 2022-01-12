#include<iostream>

//-----------------------------------------------------------Task0----------------------------------------------------------

void Task0()
{
    std::cout << "\n\nTask 0:\n";
}

//-----------------------------------------------------------Task1----------------------------------------------------------

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
    std::cout << "> Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
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

void Task1()
{
    std::cout << "\n\nTask 1:\n";

    int N1, M1, N2, M2;
    inputMatrixSize(N1, M1, N2, M2);

    int **matrixA = allocateMatrixMemmory(N1, M1);
    int **matrixB = allocateMatrixMemmory(N2, M2);

    inputMatrix(matrixA, N1, M1);
    inputMatrix(matrixB, N2, M2);

    transformMatrix(matrixA, matrixB, N1, M1, N2, M2);

    deleteMatrixMemmory(matrixA, N1);
    deleteMatrixMemmory(matrixB, N2);
}

//-----------------------------------------------------------Task2----------------------------------------------------------

void inputMatrixSize(int &N, int &M)
{
    do
    {
        std::cout << "> N: ";
        std::cin >> N;
    } while (N < 2 || N > 20);

    do
    {
        std::cout << "> M: ";
        std::cin >> M;
    } while (M < 2 || M > 20);
}

template <typename T>
T **allocateMatrixMemmory(int n, int m)
{
    T **matrix = new T *[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new T[m];

    return matrix;
}

template <typename T>
void deleteMatrixMemmory(T **matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;
}

void inputMatrix(char **matrix, int n, int m)
{
    std::cout << "> Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
}

void printMatrix(char **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << matrix[i][j] << " ";

        std::cout << std::endl;
    }
}

bool isAritmetic(int *path, int count)
{
    int d = path[1] - path[0];
    for (int i = 0; i < count - 1; i++)
        if (d + path[i] != path[i + 1])
            return false;
    return true;
}

bool endCondition(int x, int y, int N, int M)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return false;
    return true;
}

void findStartCell(char **matrix, bool **visited, char *path, int pathIndex, int N, int M)
{
    int maxLength = 0;
    int curLength = 0;
    int x = 0;
    int y = 0;
    int finalX = 0;
    int finalY = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            x = i;
            y = j;

            while (endCondition(x, y, N, M) && visited[x][y] != true)
            {
                visited[x][y] = true;

                switch (matrix[x][y])
                {
                case 'L':
                    y--;
                    break;
                case 'R':
                    y++;
                    break;
                case 'D':
                    x++;
                    break;
                case 'U':
                    x--;
                    break;
                }

                curLength++;
            }

            for (int i = 0; i < N; i++)
                for (int j = 0; j < M; j++)
                    visited[i][j] = false;

            if (curLength > maxLength)
            {
                maxLength = curLength;
                finalX = i;
                finalY = j;
            }

            curLength = 0;
        }
    }

    std::cout << "Starting coordinates: " << finalX << " " << finalY << std::endl;
}

void Task2()
{
    std::cout << "\n\nTask 2:\n";

    int N = 4, M = 4;
    inputMatrixSize(N, M);

    char *path = new char[N * M];

    int **grid = allocateMatrixMemmory<int>(N, M);

    bool **visited = allocateMatrixMemmory<bool>(N, M);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = false;

    char **board = allocateMatrixMemmory<char>(N, M);
    inputMatrix(board, N, M);

    findStartCell(board, visited, path, 0, N, M);

    delete[] path;
    deleteMatrixMemmory(board, N);
    deleteMatrixMemmory(visited, N);
}

//--------------------------------------------------------------------------------------------------------------------------

int main()
{

    // Task0();

    // Task1();

    // Task2();

    return 0;
}