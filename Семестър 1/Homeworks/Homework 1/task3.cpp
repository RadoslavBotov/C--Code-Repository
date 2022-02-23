#include <iostream>

void inputTask3(int &a, int &b) // цели числа a и b
{
    std::cout << "> A, B: ";
    std::cin >> a >> b;
}

int isEven(int number)
{
    return number % 2 == 0;
}

bool isNumberInterestin(int number) // 123 е интересно, но числото 235 не е.
{
    if (number < 0)
        number *= -1;

    int current = number % 10;
    number /= 10;

    while (number > 0)
    {
        if (!(isEven(number % 10) ^ isEven(current)))
            return false;
        current = number % 10;
        number /= 10;
    }

    return true;
}

void sumOfInterestingNumbers(int a, int b)
{
    long long sum = 0;

    std::cout << "The interesting numbers in the interval [" << a << ", " << b << "] are: ";

    for (int i = a; i <= b; i++)
        if (isNumberInterestin(i))
        {
            std::cout << i << " ";
            sum += i;
        }

    std::cout << "\nTheir sum is " << sum;
}

int main()
{
    int a, b;

    inputTask3(a, b);

    sumOfInterestingNumbers(a, b);

    return 0;
}
/*
Интересно число е такова число, при което няма две съседни цифри с еднаква четност. 
Например числото 123 е интересно, но числото 235 не е.

Да се напише програма, която по подадени две цели числа a и b намира сумата на числата в интервала [a, b], които са интересни числа.
*/