// Напишете функция, която по въведено изречение, запазва думите от него в двумерен масив.
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

void initializeMatrix(char **matrix, int size)
{
    matrix = new char *[size];
    for (int i = 0; i < size; ++i)
        matrix[i] = new char[size];
}

void printMatrix(char **matrix, int n, int m)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << setw(3) << matrix[i][j];
        cout << endl;
    }
}

void deleteMatrix(char **matrix, int n)
{
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];

    delete[] matrix;
}

int findStartIndex(char *str, int index)
{
    int i = index;
    while (!(str[i] > 'a' && str[i] < 'z') || !(str[i] > 'A' && str[i] > 'Z'))
        i++;
    return i;
}

int findEndIndex(char *str, int index)
{
    int i = index;
    while ((str[i] > 'a' && str[i] < 'z') || (str[i] > 'A' && str[i] > 'Z'))
        i++;
    return i;
}

void subString()
{

}

void wordsInString(char *str, char **matrix, int sizeMatrix)
{
    int sizeStr = strlen(str);
    int start = 0;
    int end = 0;

    while (end < sizeStr)
    {
        start = findStartIndex(str, end);
        end = findEndIndex(str, start);

        if ((start > sizeStr) || (end > sizeStr))
            break;

        // sub string
    }
}

int main()
{
    char str[1024];
    cin.getline(str, '\n');
    int strSize = strlen(str);

    char **matrix;

    // initializeMatrix(matrix, 3);

    wordsInString(str, matrix, strSize);

    deleteMatrix(matrix, strSize);

    return 0;
}