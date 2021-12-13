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

void UniqueNumbers(int arr[], int length)
{
    int nums[50];
    nums[0] = arr[0];

    for (int i = 1; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            /* code */
        }
        
    }
    
}

int main()
{
    int length = Cin(length), arr[50];

    PopulateArray(arr, length);

    UniqueNumbers(arr, length);

    return 0;
}

/*
Write a program that reads a number N STDIN (N between 5 and 50) and then subsequently 
reads N numbers from STDIN. 
At the end of the program write on STDOUT the unique numbers amongst the once read from STDIN.
*/