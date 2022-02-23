#include <iostream>
#include <cstring>

bool validStr(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (!(str[i] >= 'a' && str[i] <= 'z'))
            if ((str[i] != '.') && (str[i] != '+'))
                return false;
    return true;
}

int inputN(int n)
{
    do
    {
        std::cout << "> N: ";
        std::cin >> n;
    } while (n < 1 || n > 1024);

    return n;
}

int getValue(int n, char *letters, int *values, char letter)
{
    int value = 0;
    for (int i = 0; i < n; i++)
        if (letters[i] == letter)
            value = values[i];
    return value;
}

int calculate(char *str, int n, char *letters, int *values)
{
    int sum = 0;
    int multiplication = getValue(n, letters, values, str[0]);
    for (int i = 1; i < strlen(str); i++) // a.b+b.c+d+a.c
    {
        if (str[i] == '.')
            multiplication *= getValue(n, letters, values, str[i + 1]);
        else if (str[i] == '+')
        {
            sum += multiplication;
            multiplication = str[i + 1] - '0';
        }
    }

    return sum;
}

int main()
{
    char buffer[1025];

    std::cout << "> Str: ";
    std::cin.getline(buffer, 1024, '\n');
    if (validStr(buffer))
    {
        int length = strlen(buffer) + 1;

        char *str = new char[length];
        strcpy(str, buffer);

        int n = inputN(n);

        char *letters = new char[n];
        for (int i = 0; i < n; i++)
            std::cin >> letters[i];

        int *values = new int[n];
        for (int i = 0; i < n; i++)
            std::cin >> values[i];

        std::cout << "< Answer: " << calculate(str, n, letters, values);

        delete[] str;
        delete[] letters;
        delete[] values;
    }
    else
        std::cout << "Not a valid input string.";

    return 0;
}
/*
Алгебричен израз е зададен с низ, състоящ се от малки латински букви, разделени с единичен знак '.' (умножение) или '+' (събиране).
Всяка буква означава цяло число, като съответствието е зададено с два масива от n букви letters и n числа values, като на
буквата letters[i] съответства числото values[i]. Да се реализира функция calculate, която приема коректно зададен израз, число
n и масиви letters и values и връща пресметнатата стойността на израза, спазвайки приоритета на операциите. Ако в израза се среща
латинска буква, за която не е зададена стойност, тя да се приеме за 0.

Упътване: Можете да използвате една променлива, която натрупва текущото произведение и една променлива, която натрупва общата сума.

Примери:
*/