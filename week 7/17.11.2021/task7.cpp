#include <iostream>

int Cin(std::string s, int n)
{
    do
    {
        std::cout << "> " << s << ": ";
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

void ShiftElementsRightFromIndex(int arr[], int &n, int index)
{
    n++;
    for (int i = n; index < i; i--)
        arr[i] = arr[i - 1];
}

void InsertElementAtIndex(int arr[], int index)
{
    int temp;
    std::cout << "> Element: ";
    std::cin >> temp;

    arr[index] = temp;
}

void RemoveElementAtIndex(int arr[], int &n, int index)
{
    for (int i = index; i < n; i++)
        arr[i] = arr[i + 1];
    n--;
}

int main()
{
    int n = Cin("N", n), arr[100], index = Cin("Index", index);

    PopulateArrayFor(arr, n);

    ShiftElementsRightFromIndex(arr, n, index);
    PrintArray(arr, n);

    InsertElementAtIndex(arr, index);
    PrintArray(arr, n);

    RemoveElementAtIndex(arr, n, index);
    PrintArray(arr, n);

    return 0;
}

/*
Да се напишат следните функции по даден масив и индекс :

Измества всички елементи от този индекс нататък с една позиция надясно(към края на масива)
        !!! > Обърнете внимание, че така се променят броя елементи в масива < !!!
Добавя елемент на позиция с този индекс в масива;
Премахва елемент от позицията с този индекс в масива;
*/