#include <iostream>

int **allocateMatrixMemmory(int **matrix, int n)
{
    matrix = new int *[n];

    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    return matrix;
}

void deleteMatrixMemmory(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        delete[] matrix[i];

    delete[] matrix;
}

int inputN(int n)
{
    do
    {
        std::cout << "> N: ";
        std::cin >> n;
    } while (n < 1 || n > 30);

    return n;
}

void inputMatrix(int **matrix, int n)
{
    std::cout << "> Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            std::cin >> matrix[i][j];
}

int count(int number)
{
    int br = 0;
    while (number > 0)
    {
        br++;
        number /= 10;
    }
    return br;
}

bool checkForSameNumbers(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] == arr[j])
                return true;
    return false;
}

bool containsSameNumbers(int number)
{
    int size = count(number);
    if (size == 1)
        return false;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = number % 10;
        number /= 10;
    }

    bool flag = checkForSameNumbers(arr, size);
    delete[] arr;

    return flag;
}

int arrSize(int **matrix, int n)
{
    int size = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (containsSameNumbers(matrix[i][j]))
                size++;
    return size;
}

int *collect(int **matrix, int n)
{
    int t = 0;
    int size = arrSize(matrix, n);

    int *arr = new int[size];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (containsSameNumbers(matrix[i][j]))
            {
                arr[t] = matrix[i][j];
                t++;
            }

    return arr;
}

int main()
{
    int n = inputN(n);

    int **matrix = allocateMatrixMemmory(matrix, n);
    inputMatrix(matrix, n);

    int *arr = collect(matrix, n);

    int size = arrSize(matrix, n);
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";

    delete[] arr;
    deleteMatrixMemmory(matrix, n);

    return 0;
}
/*
1076 1356 1918
6252 6766 5525
5524 3176 1716
->
5524 6252 6766 1716 5525 1918
  20   10   11   22   12   02

       0  1  2
    0 00 01 02
    1 10 11 12
    2 20 21 22

Дадена е квадратна матрица matrix от цели числа с размерност n × n, за 1 ≤ n ≤ 30.
Да се реализира функция collect, която приема matrix и числото n връща едномерен масив, съдържащ онези елементи на матрицата,
в десетичния запис на които има повтарящи се цифри. Едномерният масив трябва да бъде динамично заделен, с точно толкова елемента,
колкото трябва да се съхраняват в него. Да се реализира програма, която въвежда от стандартния вход квадратна матрица, извиква
функцията collect по подходящ начин и извежда върнатия като резултат масив на стандартния изход.
Добавянето на елементите трябва да става спрямо техния ред при обхождането на матрицата по диагоналите успоредни на главния
диагонал, започвайки от долния ляв ъгъл, съгласно схемата по-долу:
*/