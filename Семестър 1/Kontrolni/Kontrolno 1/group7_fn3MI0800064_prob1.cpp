#include <iostream>

int count(int number)
{
    int br = 0;
    while (number > 0)
    {
        br++;
        number /= 10;
    }
    return br;
}

int power(int number, int power)
{
    int temp = number;
    for (int i = 1; i < power; i++)
        number *= temp;
    return number;
}

bool func(int n, int k)
{
    int a = count(n);
    int b = count(k);

    if (((n % power(10, b)) == k) || ((n / power(10, a - b)) == k))
        return false;

    while (n > 0)
    {
        if ((n % power(10, b)) == k)
            return true;
        n /= 10;
    }
    return false;
}

int main()
{
    int n, k;

    std::cout << "> N, K: ";
    std::cin >> n >> k;

    int a = count(n);
    int b = count(k);

    std::cout << func(n, k) << std::endl;

    return 0;
}

/*
group7_fn3MI0800064_prob1.cpp

Конкатенация на две естествени числа A и B наричаме число A ∘ B, което се получава като към 
цифрите на A се долепят цифрите на B.
Пример:
123 ∘ 431 = 123431
123 ∘ 0 = 1230

Да се напише програма, която въвежда две естествени числа N и K и извежда дали съществуват 
естествени числа А и B, такива че N = A ∘ K ∘ B.
За реализацията на задача може да се използва и функция с два параметъра – N и К.
В решението на задачата не се допуска използването на масиви!
*/