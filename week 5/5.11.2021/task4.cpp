#include <iostream>

int Cin(int num)
{
    std::cout << "\n";
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
    std::cout << "\n-> ";
    for (int i = 0; i < num; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

void LongestSubsequence(int arr[], int subArr[], int num)
{
    int longestSubArr = 0, endIndex;
    int j = 0;
    for (int i = 0; i < num - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            j++;
        }
        else 
        {
            j++;

            if (longestSubArr < j)
            {
                endIndex = i;
                longestSubArr = j;
                j = 0;
            }
        }
    }

    j = 0;
    for (int t = endIndex - longestSubArr + 1; t <= longestSubArr; t++)
    {
        subArr[j] = arr[t];
        j++;
    }

    PrintArray(subArr, longestSubArr);
}

int main()
{
    int num = Cin(num), subArr[100] = {0}, mainArr[100] = {0};

    PopulateArray(mainArr, num);
    PrintArray(mainArr, num);

    LongestSubsequence(mainArr, subArr, num);

    return 0;
}
// Write a program that reads a number N from STDIN (N between 5 and 100) and then subsequently reads N numbers from STDIN.
// At the end of the program write on STDOUT the longest subsequence of the original for which it is true that for i < j -> a[i] < a[j].