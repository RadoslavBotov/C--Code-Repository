// Write a program that reads a string S from STDIN (0 < streln(S) < 1024).
// At the end of the program write on STDOUT all words in S in a reverse order.
#include <iostream>
#include <cstring>

void reverseString(char *str)
{
    std::cout << "!";
    std::cout << "!!";
}

int main()
{
    char str[1025];

    std::cout << "> ";
    std::cin.getline(str, 1025);

    reverseString(str);

    std::cout << str;

    return 0;
}