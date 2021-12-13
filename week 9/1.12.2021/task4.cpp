/*
Напишете фунцкия, която приема указател към масив и:

въвежда елементите в него
принтира елементите
премахва елемент с даден индекс от масива
премахва всички елементи с дадена стойност от масива. Преценете сами какви други променливи и от какъв тип трябва да подавате 
на всяка от фунцкиите.
*/
#include <iostream>

void input(int *size)
{
    std::cout << "> Size: ";
    std::cin >> *size;
    //return size;
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

void removeElementAt(int *arr, int &size, int index)
{
    size--;
    for (int i = index; i < size; i++)
        arr[i] = arr[i + 1];
}

void removeAllElemnts(int *arr, int &size, int number)
{
    for (int i = size; i > 0; i--)
        if(arr[i] == number)
            removeElementAt(arr, size, i);
}

int main()
{
    int arr[100], size;

    input(&size);

    inputArray(arr, size);
    printArray(arr, size);

    removeElementAt(arr, size, 2);
    printArray(arr, size);

    removeAllElemnts(arr, size, 2);
    printArray(arr, size);

    return 0;
}