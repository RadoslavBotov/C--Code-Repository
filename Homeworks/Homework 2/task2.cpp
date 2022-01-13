#include <iostream>
#include <cstring>

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

int main()
{
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

    return 0;
}

/*
RRRD
   D
   D
   R
*/