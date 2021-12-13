#include<iostream>

bool CheckIfOdd(int num)
{
    return num % 2 == 0;
}

int main()
{
    int num = 100;
    for (int i = 1; i < num / 2 + 1; i++)
    {
        std::cout << num << " % " << i << ": " << num % i << std::endl;
    }
    
}