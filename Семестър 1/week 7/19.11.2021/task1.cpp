#include <iostream>

int Cin(int n)
{
    do
    {
        std::cout << "> N [2, 10]: ";
        std::cin >> n;
    } while (n < 2 || n > 10);
    return n;
}

void readArray(int arr[][10], int n)
{
    std::cout << "> Arr[" << n << "][" << n << "]:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> arr[i][j];
}

int multiplication(int arr1[][10], int arr2[][10], int n, int i, int j)
{
    int result = 0;
    for (int p = 0; p < n; p++)
        result += arr1[i][p] * arr2[p][j];
    return result;
}

void multiplication(int arr1[][10], int arr2[][10], int arr3[][10], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            arr3[i][j] = multiplication(arr1, arr2, n, i, j);
}

void printArray(int arr[][10], int n)
{
    std::cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            std::cout << arr[i][j] << " ";
        std::cout << "\n";
    }
}

int main()
{
    int arr1[10][10], arr2[10][10], arr3[10][10], n = Cin(n);

    readArray(arr1, n);
    readArray(arr2, n);

    multiplication(arr1, arr2, arr3, n);

    printArray(arr3, n);

    return 0;
}

// Write a program that reads a number N from STDIN (N between 2 and 10) and then reads
// two NxN matrices from STDIN. At the end of the program write on STDOUT the result of
// the multiplication of the two matrices.