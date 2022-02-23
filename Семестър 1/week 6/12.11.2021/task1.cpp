#include <iostream>

int Cin(int length)
{
    do
    {
        std::cout << "> Length [5, 50]: ";
        std::cin >> length;
    } while (length < 5 || length > 50);

    return length;
}

void PopulateArray(int arr[], int length)
{
    std::cout << "> arr[" << length << "]: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];
}

bool SymmetricalSequence(int arr[], int length)
{
    for (int i = 0; i < length / 2; i++)
        if (arr[i] != arr[length - i - 1])
            return false;
    
    return true;
}

int main()
{
    int length = Cin(length), arr[50];

    PopulateArray(arr, length);

    std::cout << SymmetricalSequence(arr, length);

    return 0;
}

/*
Write a program that reads a number N from STDIN (N between 5 and 50) and then subsequently reads N numbers from STDIN. 
At the end of the program write on STDOUT whether the numbers form a symmetrical sequence - sequence is the same when read left to right 
or right to left (see: example).
*/