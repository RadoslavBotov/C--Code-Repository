#include <iostream>
using namespace std;

void inputMatrixSize(int &N, int &M)
{
    do
    {
        std::cout << "> N1: ";
        std::cin >> N;
    } while (N < 2 || N > 20);

    do
    {
        std::cout << "> M1: ";
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

void inputMatrix(int **matrix, int n, int m, int placeholder[][6])
{
    // cout << "> Matrix:\n";
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < m; j++)
    //         cin >> matrix[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = placeholder[i][j];
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

bool isAritmetic(int *path, int count)
{
    int d = path[1] - path[0];
    for (int i = 0; i < count - 1; i++)
        if (d + path[i] != path[i + 1])
            return false;
    return true;
}

void findProgression(int **matrix, bool **visited, int *path, int N, int M, int x1, int y1, int x2, int y2, int count)
{
    if (x1 < 0 || x1 >= N || y1 < 0 || y1 >= M || visited[x1][y1] == true)
        return;

    if (x1 == x2 && y1 == y2)
    {
        path[count++] = matrix[x2][y2];

        if (isAritmetic(path, count))
            for (int i = 0; i < count; i++)
                std::cout << path[i] << " ";
        return;
    }

    path[count++] = matrix[x1][y1];
    visited[x1][y1] = true;

    x1 = x1 - 1;
    findProgression(matrix, visited, path, N, M, x1, y1, x2, y2, count);
    x1 = x1 + 1;

    x1 = x1 + 1;
    findProgression(matrix, visited, path, N, M, x1, y1, x2, y2, count);
    x1 = x1 - 1;

    y1 = y1 - 1;
    findProgression(matrix, visited, path, N, M, x1, y1, x2, y2, count);
    y1 = y1 + 1;

    y1 = y1 + 1;
    findProgression(matrix, visited, path, N, M, x1, y1, x2, y2, count);
    y1 = y1 - 1;

    visited[x1][y1] = false;
    count--;
}

int main()
{
    int N = 4, M = 6;
    int x1 = 0, y1 = 1, x2 = 2, y2 = 5;
    // input(x1, y1, x2, y2);
    // inputMatrixSize(N, M);

    int *path = new int[N * M];
    int **grid = allocateMatrixMemmory<int>(N, M);
    bool **visited = allocateMatrixMemmory<bool>(N, M);
    int placeholder[4][6] = {{12, 1, 19, 2, 10, 11},
                             {4, 3, 11, 8, 8, 19},
                             {9, 5, 7, 9, 11, 13},
                             {14, 16, 8, 10, 11, 19}};

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            visited[i][j] = false;

    inputMatrix(grid, N, M, placeholder);

    findProgression(grid, visited, path, N, M, x1, y1, x2, y2, 0);

    delete[] path;
    deleteMatrixMemmory<int>(grid, N);
    deleteMatrixMemmory<bool>(visited, N);

    return 0;
}
/*
Дадена е мрежа Gr от 𝑚 × 𝑛 (𝑚,𝑛 ∈ [2;20]) квадратчета. Във всяко квадратче на мрежата е записано естествено число.
Дадени са също две произволни квадратчета k1 и k2 в мрежата. Ацикличен път между две квадратчета е всяка редица от различни
съседни във вертикано или хоризонтално направление квадратчета, започваща от началното и завършваща в крайното квадратче.
Да се дефинира рекурсивна функция, която проверява, дали съществува ацикличен път от K1 до K2 в Gr, който представлява
аритметична прогресия с разлика d.

Пример. Ако Gr има вида:
12 1.  19  2  10  11
4  3.  11  8  8   19
9  5.  7.  9. 11. 13.
14 16  8   10 11  19
k1 = Gr[0][1], k2 = Gr[2][5], съществува ацикличен път, който е аритметична прогресия с разлика 2.

*/