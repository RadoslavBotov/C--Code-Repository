// Напишете фунцкия, която разменя елементите на два масива. Нямате право да използвате помощен масив.
#include <iostream>

void input(int *size)
{
    std::cout << "> Size: ";
    std::cin >> *size;
}

void inputArray(int *arr, int size)
{
    std::cout << "> Array: ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapArrays(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; i++)
        swap(&arr1[i], &arr2[i]);
}

int main()
{
    int arr1[100], arr2[100];
    int size;

    input(&size);

    inputArray(arr1, size);
    inputArray(arr2, size);

    std::cout << "\nArray 1 : ";
    printArray(arr1, size);
    std::cout << "Array 2 : ";
    printArray(arr2, size);

    swapArrays(arr1, arr2, size);

    std::cout << "\nArray 1 : ";
    printArray(arr1, size);
    std::cout << "Array 2 : ";
    printArray(arr2, size);

    return 0;
}