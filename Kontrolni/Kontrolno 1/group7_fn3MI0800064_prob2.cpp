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
    for (int i = 1; i < power; i++)
        number *= number;
    return number;
}

bool isAdjacent(int number)
{
    int current = number % 10;
    number /= 10;
    while (number > 0)
    {
        if (number % 10 == current)
            return false;
        current = number % 10;
        number /= 10;
    }
    return true;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void func(int a, int b)
{
    int tempArr[1024], j = 0;
    bool flag = false;
    for (int i = a; i < b; i++)
        if (isAdjacent(i))
        {
            tempArr[j] = i;
            j++;
            flag = true;
        }

    if (flag)
        std::cout << tempArr[j-1] - tempArr[0] << std::endl;
    else
        std::cout << "No adjacent numbers!" << std::endl;
}

int main()
{
    int a, b;

    std::cout << "> [a, b]: ";
    std::cin >> a >> b;

    func(a, b);

    return 0;
}

/*
group7_fn3MI0800064_prob2.cpp

Едно число ще наричаме „съседно“, ако всеки две негови съседни цифри са различни.
Пример: 2572 е съседно, но 3119 не е.

Да се напише програма, която намира разликата на най-голямото и най-малкото „съседно“ число в 
интервала [a; b], където a и b са въведени от клавиатурата естествени числа. Ако в интервала 
няма съседни числа, да се изведе подходящо съобщение. Позволено е използването на масиви и 
функции.
*/