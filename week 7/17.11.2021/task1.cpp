#include <iostream>

int FindBigger(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int a, b;

    std::cout << "> a, b: ";
    std::cin >> a >> b;

    std::cout << "< Bigger number: " << FindBigger(a, b) << std::endl;

    return 0;
}

// Да се напише функция, която извежда по-голямото от две цели числа.