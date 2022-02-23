#include<iostream>

int Cin(int num)
{
    do
    {
        std::cout << "Num [1, 50]: ";
        std::cin >> num;
    } while (num < 0 || num > 51);
    return num;
}

void PopulateArray(long long arr[], int num)
{
    long long fibA = 0, fibB = 1;

    for (int i = 0; i < num; i++)
    {
        arr[i] = fibA;
        fibB = fibB + fibA;
        fibA = fibB - fibA;
    }
}

void PrintArray(long long arr[], int num)
{
    for (int i = 0; i < num; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int num = Cin(num);
    long long arr[50] = {0}, sum = 0;

    PopulateArray(arr, num);
    PrintArray(arr, num);

    for (int i = 0; i < num; i++)
        sum += arr[i];

    std::cout << "Sum = " << sum;

    return 0;
}

// Write a program that reads a number N from STDIN(N between 1 and 50) and writes on STDOUT the sum of all Fibonacci 
// numbers beteen 0 and N.