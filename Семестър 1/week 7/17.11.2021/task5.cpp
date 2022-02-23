#include <iostream>

int Cin(int n)
{
    do
    {
        std::cout << "> N: ";
        std::cin >> n;
    } while (n < 0 || n > 100);
    return n;
}

void PopulateArrayFor(int arr[], int n)
{
    std::cout << "> For: Arr[" << n << "]: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

// Въвежда в масив n на брой елемента отзад напред (без for);
void PopulateArrayWhile(int arr[], int n)
{
    int i = 0;
    std::cout << "> While: Arr[" << n << "]: ";
    while (i < n)
    {
        std::cin >> arr[n - i - 1];
        i++;
    }
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    int n = Cin(n), arr[100];

    PopulateArrayFor(arr, n);
    PrintArray(arr, n);
    PopulateArrayWhile(arr, n);
    PrintArray(arr, n);

    return 0;
}

/*
Да се напишат следните 3 функции:

Въвежда число n, което ще е дължина на масив;
Въвежда в масив n на брой елемента;
Въвежда в масив n на брой елемента отзад напред (без for);
Принтира масива;
*/