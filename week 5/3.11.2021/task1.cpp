#include<iostream>

int Count(int num)
{
    int count = 0;
    while(num > 0)
    {
        num /= 10;
        count++;
    }
    return count;
}

int main()
{
    int num;

    std::cin >> num;

    // for (int i = 0; i < Count(num) / 2; i++)
    // {
    //     /* code */
    // }

    std::cout << Count(num);

    return 0;
}

/*
Да се напише програма, която проверява дали дадено число е палиндом.

само с цикли
използвайки и масив
*/