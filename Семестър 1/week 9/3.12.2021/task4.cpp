// Write a program that reads a string S from STDIN (0 < streln(S) < 1024).
// At the end of the program write on STDOUT S with all non-alphabetical characters removed.
#include <iostream>
#include <cstring>

void removeElementAt(char *arr, int &size, int index)
{
    size--;
    for (int i = index; i <= size; i++)
        arr[i] = arr[i + 1];
}

void convertLettersInString(char *str)
{
    int size = strlen(str);
    for (int i = size; i > 0; i--)
        if (!((str[i] >= 'A' && str[i] <= 'z') || (str[i] >= 'a' && str[i] <= 'z')))
            removeElementAt(str, size, i);
    str[size + 1] = '\0';
}

int main()
{
    char str[1025];

    std::cout << "> ";
    std::cin.getline(str, 1025);

    convertLettersInString(str);

    std::cout << "< ";
    std::cout << str;

    return 0;
}