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

void PopulateArray(int vector[], int length)
{
    std::cout << "> Vector[" << length << "]: ";
    for (int i = 0; i < length; i++)
        std::cin >> vector[i];
}

void EntrywiseProduct(int v1[], int v2[], int length)
{
    std::cout << "< ";
    for (int i = 0; i < length; i++)
        std::cout << v1[i] * v2[i] << " ";
}

int main()
{
    int length = Cin(length), v1[50], v2[50];

    PopulateArray(v1, length);
    PopulateArray(v2, length);

    EntrywiseProduct(v1, v2, length);

    return 0;
}

/*
Write a program that reads a number N from STDIN (N between 5 and 50) and then 
subsequently reads two vectors consisting of N numbers each from STDIN. 
At the end of the program write on STDOUT the entrywise product of the two vectors 
*/