// Напишете функция, която събира две числа и запазва сбора им в първото.
#include <iostream>

void addition(int *a, int *b)
{
    *a = *a + *b;
}

int main()
{
    int a, b;

    std::cout << "> A, B: ";
    std::cin >> a >> b;

    addition(&a, &b);

    std::cout << "A = " << a << std::endl;
    std::cout << "B = " << b << std::endl;

    return 0;
}