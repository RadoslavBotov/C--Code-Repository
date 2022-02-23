#include <iostream>

int Cin(int n)
{
    do
    {
        std::cout << "> N [5, 100]: ";
        std::cin >> n;
    } while (n < 5 || n > 100);
    return n;
}

void readArray(int arr[], int n)
{
    std::cout << "> Arr[" << n << "]: ";
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
}

void printArray(int arr[], int n)
{
    std::cout << "\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void merge(int arr[], int left, int mid, int right)
{
    int subArrOne = mid - left + 1;
    int subArrTwo = right - mid;

    int leftArray[100], rightArray[100];

    for (int i = 0; i < subArrOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOne = 0, indexTwo = 0;
    int indexMerged = left;

    while (indexOne < subArrOne && indexTwo < subArrTwo)
    {
        if (leftArray[indexOne] <= rightArray[indexTwo])
        {
            arr[indexMerged] = leftArray[indexOne];
            indexOne++;
        }
        else
        {
            arr[indexMerged] = rightArray[indexTwo];
            indexTwo++;
        }
        indexMerged++;
    }

    while (indexOne < subArrOne)
    {
        arr[indexMerged] = leftArray[indexOne];
        indexOne++;
        indexMerged++;
    }

    while (indexTwo < subArrTwo)
    {
        arr[indexMerged] = rightArray[indexTwo];
        indexTwo++;
        indexMerged++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int arr[100], n = Cin(n);

    readArray(arr, n);

    mergeSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}

// Write a program that reads a number N from STDIN (N between 5 and 100) and then subsequently
// reads N numbers from STDIN. At the end of the program write on STDOUT the numbers in
// sorted order using merge sort.