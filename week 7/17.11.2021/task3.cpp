#include<iostream>

void FibonacciSequence(int n)
{
    int a = 1, b = 1, next;
    std::cout << "< 1 1 ";
    for (int i = 0; i < n - 2; i++)
    {
        next = a + b;
        std::cout << a + b << " ";
        a = b;
        b = next;
    }
}

int main()
{
    int n;
    std::cin >> n;

    FibonacciSequence(n);

    return 0;
}

// Да се напише функция, която извежда редицата на Фибоначи до n-тия елемент.