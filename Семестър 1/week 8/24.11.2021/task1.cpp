#include <iostream>
#include <cmath>

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

int main()
{
    int a = 321;
    std::cout << a * pow(10, count(a));
    return 0;
}