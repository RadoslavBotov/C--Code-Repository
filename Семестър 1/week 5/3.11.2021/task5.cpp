#include <iostream>
#include <math.h>

int Count(int num)
{
    int count = 0;
    while (num < 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

bool CheckIfOdd(int num)
{
    return !(num % 2 == 0);
}

int main()
{
    int num;

    do
    {
        std::cout << "Num < 0: ";
        std::cin >> num;
    } while (num > 0);

    int count = Count(num);

    for (int i = 0; i < count; i++)
    {
        if (CheckIfOdd(num % 10))
            num /= 10;
        else 
        {
            int temp = num % 10;
            num += (num % 10) * pow(10, count);
            num /= 10;
        }
    }

    std::cout << num;

    return 0;
}

/*
Да се напише програма, която изтрива нечетните цифри на дадено неотрицателно цяло число. (без масиви)
*/