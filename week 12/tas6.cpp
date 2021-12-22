// Напишете функция, която обръща масив рекурсивно.
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void turnArrayWrapper(int *arr, int index, int size)
{
    if (index >= size)
        return;

    swap(arr[index], arr[size]);

    turnArrayWrapper(arr, index + 1, size - 1);
}

void turnArray(int *arr, int size)
{
    turnArrayWrapper(arr, 0, size - 1);
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void inputArray(int *arr, int size)
{
    cout << "> Array: ";
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

int main()
{
    int arr[100];
    int size;

    cout << "> Size of array: ";
    cin >> size;

    inputArray(arr, size);

    printArray(arr, size);
    turnArray(arr, size);
    printArray(arr, size);

    return 0;
}