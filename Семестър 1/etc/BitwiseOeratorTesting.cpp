#include <iostream>

void decimalToBinary(int number)
{
    int arr[100], i;

    for (i = 0; number > 0; i++)
    {
        arr[i] = number % 2;
        number = number / 2;
    }

    for (i = i - 1; i >= 0; i--)
        std::cout << arr[i];
    std::cout << "\n";
}

int main()
{
    int a = 10, b = 122;

    std::cout << (~a) << std::endl;

    return 0;
}