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
    std::cout << "> Arr[" << n << "]: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSortAscending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (arr[i] > arr[j])
                Swap(&arr[i], &arr[j]);
}

void BubbleSortDescending(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (arr[i] < arr[j])
                Swap(&arr[i], &arr[j]);
}

int main()
{
    int n = Cin(n), arr[100];

    PopulateArrayFor(arr, n);
    PrintArray(arr, n);

    BubbleSortAscending(arr, n);
    PrintArray(arr, n);

    BubbleSortDescending(arr, n);
    PrintArray(arr, n);

    return 0;
}

// Да се напишат функции, които сортират масив по двата познати ни досега начина.