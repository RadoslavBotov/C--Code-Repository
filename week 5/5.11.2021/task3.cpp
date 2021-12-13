#include<iostream>

int Cin(int num)
{
    do
    {
        std::cout << "Num [5, 100]: ";
        std::cin >> num;
    } while (num < 5 || num > 100);
    return num;
}

void PopulateArray(int arr[], int num)
{
    std::cout << "Arr[" << num << "]: ";
    for (int i = 0; i < num; i++)
        std::cin >> arr[i];
}

void PrintArray(int arr[], int num)
{
    std::cout << "-> ";
    for (int i = 0; i < num; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void Swap(int arr[], int j)
{
    int temp = arr[j];
    arr[j] = arr[j + 1];
    arr[j + 1] = temp;
}

void BubbleSort(int arr[], int num)
{
    int i, j;
    for (i = 0; i < num - 1; i++)
        for (j = 0; j < num - i - 1; j++)
            if (arr[j] > arr[j + 1])
                Swap(arr, j);
}

void BinarySearch(int arr[], int numberSearched, int left, int right)
{
    while (left < right)
    {
        int middle = (left + right) / 2;
        if (numberSearched <= arr[middle])
            right = middle;
        else
            left = middle + 1;
    }

    if (arr[left] == numberSearched)
        std::cout << numberSearched << " found at index " << left << std::endl;
    else
        std::cout << numberSearched << " doesnt exist in array" << std::endl;
}

int main()
{
    int num = Cin(num), arr[100] = {0};

    PopulateArray(arr, num);
    PrintArray(arr, num);

    BubbleSort(arr, num);
    PrintArray(arr, num);

    BinarySearch(arr, 5, 0, num);
    BinarySearch(arr, 10, 0, num);
    BinarySearch(arr, 50, 0, num);

    return 0;
}

// Write a program that reads a number N from STDIN (N between 5 and 100) and then subsequently reads N numbers from STDIN.
// At the end of the program write on STDOUT whether the numbers include 5, 10 or 50 by applying Binary Search.