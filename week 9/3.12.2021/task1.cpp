// Write a program that reads a string S from STDIN (0 < streln(S) < 1024). 
// At the end of the program write on STDOUT wheter S is a palindrome.
#include<iostream>
#include<cstring>

bool isPalindrome(char *str)
{
    int size = strlen(str);

    for (int i = 0; i < size / 2; i++)
        if (str[i] != str[size - i - 1])
            return false;

    return true;
}

int main()
{
    char str[1025];

    std::cout << "> ";
    std::cin.getline(str, 1025);

    std::cout << isPalindrome(str);

    return 0;
}