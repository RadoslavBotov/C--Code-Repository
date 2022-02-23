#include <iostream>
#include <cstring>
using namespace std;

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void readStr(char *str, int size)
{
    int numbers[100] = {0};
    int t = 0;

    bool isNegative;

    int i = 0;
    while (i < size)
    {
        if (str[i] == '-')
            isNegative = true;

        if (str[i] >= '0' && str[i] <= '9')
        {
            numbers[t] *= 10;
            if (isNegative)
                numbers[t] -= str[i] - '0';
            else
                numbers[t] += str[i] - '0';

            if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
            {
                t++;
                isNegative = false;
            }
        }

        i++;
    }

    for (int j = 0; j < t; j++)
        cout << numbers[j] << " ";
}

int main()
{
    char *str = new char[100];

    cout << "> String: ";
    cin.getline(str, 100);

    readStr(str, strlen(str));

    delete[] str;

    return 0;
}