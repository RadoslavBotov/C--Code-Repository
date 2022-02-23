// Напишете функция, която извежда всяка дума от даден символен низ.
#include <iostream>
#include <cstring>
using namespace std;

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

void printSubString(char *str, int start, int end)
{
    for (int i = start; i < end; i++)
        cout << str[i];
    cout << endl;
}

void wordsInString(char *str)
{
    int size = strlen(str);
    int start = 0;
    int end = 0;

    while (end < size)
    {
        start = findStartIndex(str, end);
        end = findEndIndex(str, start);

        if ((start > size) || (end > size))
            break;

        printSubString(str, start, end);
    }
}

int main()
{
    char str[100];

    cout << "> Input: ";
    cin.getline(str, 100);

    wordsInString(str);

    return 0;
}