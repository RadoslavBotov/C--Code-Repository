// Да се напише рекурсивна функция, която проверява дали един низ е палиндром.
#include <iostream>
#include <cstring>
using namespace std;

bool isPalindromeWrapper(char *str, int index, int size)
{
    if (index >= size)
        return false;

    if (str[index] != str[size-1])
        return false;

    isPalindromeWrapper(str, index + 1, size - 1);

    return true;
}

bool isPalindrome(char *str)
{
    return isPalindromeWrapper(str, 0, strlen(str));
}

int main()
{
    char str[100];

    cout << "> String: ";
    cin.getline(str, 100);

    cout << isPalindrome(str);

    return 0;
}