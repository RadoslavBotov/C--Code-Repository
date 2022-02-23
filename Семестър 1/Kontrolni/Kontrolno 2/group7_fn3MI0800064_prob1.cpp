#include <iostream>
#include <cstring>

void *minWord(char *str)
{
    int size = strlen(str);
    int index = 0;
    int i = 0;
    char word[100];

    while (*str)
    {
        bool a = *str >= 'a' && *str <= 'z';
        bool b = *str >= 'A' && *str <= 'Z';
        bool c = *str >= '0' && *str <= '9';
        if (a || b || c)
        {
            word[i] = *str;
            i++;
        }
        else
        {
            word[i] = '\0';
            std::cout << word << " " << i << std::endl;

            word[0] = '\0';
            i = 0;
        }
        str++;
    }

    return str + 3;
}

int main()
{
    char buffer[1025];
    std::cin.getline(buffer, 1024, '\n');
    int length = strlen(buffer) + 1;

    char *str = new char[length];
    strcpy(str, buffer);

    // cout << str;
    std::cout << minWord(str);

    delete[] str;

    return 0;
}
/*
Me? Why always me?
This sentence is false.
- What is C++? - A 37-year old programming language.

Да се реализира функция minWord, която приема като параметър низ и връща указател към началото на лексикографски най-малка
непразна дума в него. Дума е непрекъсната последователност от малки и големи латински букви и цифри, всички останали символи
се считат за разделители.
*/