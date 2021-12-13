// Write a program that reads a string S from STDIN (0 < streln(S) < 1024).
// At the end of the program write on STDOUT S with all lowercase letters converted to uppercase & vice versa.
#include <iostream>
#include <cstring>

void convertLettersInString(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] - 'A' + 'a';
        else if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 'a' + 'A';
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