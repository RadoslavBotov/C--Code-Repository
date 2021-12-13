#include <iostream>

int strlen(char *string) // Returns the length of string s1.
{
    int br = 0;

    while (string[br] != '\0')
        br++;

    return br;
}

void strcpy(char *string1, char *string2) // Copies string s2 into string s1.
{
    for (int i = 0; i <= strlen(string2); i++)
        string1[i] = string2[i];
}

void strcat(char *string1, char *string2) // Concatenates string s2 onto the end of string s1.
{
    for (int i = 0, len1 = strlen(string1); i <= strlen(string2); i++)
        string1[i + len1] = string2[i];
}

int strcmp(char *string1, char *string2) // Returns 0 if s1 and s2 are the same; less than 0 if s1 < s2; greater than 0 if s1 > s2.
{
    int size;

    if (strlen(string1) - strlen(string2) > 0)
        size = strlen(string1);
    else
        size = strlen(string2);

    for (int i = 0; i < size; i++)
        if (string1[i] != string2[i])
            return string1[i] - string2[i];

    return 0;
}

char *strchr(char *string, char character) // Returns a pointer to the first occurrence of character ch in string s1.
{
    for (int i = 0; i < strlen(string); i++)
        if (string[i] == character)
            return &string[i];

    return 0;
}

bool subStringMatch(char firstArr[], char secondArr[], int size2, int i)
{
    for (int t = i, p = 0; t < size2 + i; t++)
    {
        if (firstArr[t] != secondArr[p])
            return false;
        p++;
    }
    return true;
}

char *strstr(char *string1, char *string2) // Returns a pointer to the first occurrence of string s2 in string s1.
{
    for (int i = 0; i < strlen(string1) - strlen(string2) + 1; i++)
        if (subStringMatch(string1, string2, strlen(string2), i))
            return &string1[i];
    return 0;
}

int main()
{
    char str1[1025], str2[1025];

    std::cout << "> String1 and String2: ";
    std::cin >> str1 >> str2;

    std::cout << str1 << std::endl;
    std::cout << str2 << "\n\n";

    // strcpy(str1, str2);
    // std::cout << str1 << std::endl;

    // strcat(str1, str2);
    // std::cout << str1 << std::endl;

    // std::cout << strcmp(str1, str2);

    // *strchr(str1, 'a') = '!';
    // std::cout << str1 << std::endl;

    // *strstr(str1, str2) = '!';
    // std::cout << str1 << std::endl;

    return 0;
}