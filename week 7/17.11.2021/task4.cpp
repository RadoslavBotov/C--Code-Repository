#include <iostream>

void Swap1(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void Swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;

    std::cout << "> a, b: ";
    std::cin >> a >> b;

    Swap1(a, b);
    std::cout << "< " << a << " " << b << std::endl;
    Swap2(&a, &b);
    std::cout << "< " << a << " " << b << std::endl;

    return 0;
}

// Да се напише функция, която разменя стойностите на две променливи.