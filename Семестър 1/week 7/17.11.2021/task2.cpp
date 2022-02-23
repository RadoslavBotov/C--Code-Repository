#include <iostream>

int GCD(int a, int b)
{
    if (a == b)
        return a;
    if (a == 0)
        return b;
    else
        return GCD(b % a, a);
}

int main()
{
    int a, b;

    std::cout << "> a, b: ";
    std::cin >> a >> b;

    std::cout << "< NOD: " << GCD(a, b) << std::endl;

    return 0;
}

// Да се напише функция, която извежда НОД на две числа.