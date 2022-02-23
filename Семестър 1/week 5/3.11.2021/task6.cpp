#include <iostream>

int SumOfDividers(int num)
{
    int sum = 0;
    for (int i = 1; i < num / 2 + 1; i++)
        if(num % i == 0)
            sum += i;
    return sum;
}

bool PerfectNumber(int num)
{
    return num == SumOfDividers(num);
}

int main()
{
    int num;

    std::cin >> num;

    for (int i = 2; i <= num; i++)
        if (PerfectNumber(i))
            std::cout << i << std::endl;

    return 0;
}
/*
Едно положително цяло число се нарича съвършено, ако е равно на сумата от своите делители (без самото число). 
Например 6 е съвършено (6 = 1 + 2 + 3), а 1 НЕ е съвършено. 
Да се напише програма, която намира всички съвършени числа ненадминаващи дадено положително цяло число n.
*/