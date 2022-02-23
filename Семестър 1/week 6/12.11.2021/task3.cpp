#include <iostream>

int Cin1(int n)
{
    do
    {
        std::cout << "> N [5, 50]: ";
        std::cin >> n;
    } while (n < 5 || n > 50);

    return n;
}

int Cin2(int k, int n)
{
    do
    {
        std::cout << "> K [4, " << n << "]: ";
        std::cin >> k;
    } while (k < 4 || k > n);

    return k;
}

void PopulateArray(int arr[], int length)
{
    std::cout << "> arr[" << length << "]: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];
}

bool IsEqual(int arrN[], int arrK[], int k, int i)
{
    for (int j = 0; j < k; j++)
        if (arrN[j + i] != arrK[j])
            return false;
    return true;
}

int Contains(int arrN[], int arrK[], int n, int k)
{
    int br = 0;
    for (int i = 0; i < n - k + 1; ++i)
        if (IsEqual(arrN, arrK, k, i))
            br++;
    
    return br;
}

int main()
{
    int n = Cin1(n), k = Cin2(k, n), arrN[50], arrK[50];

    PopulateArray(arrN, n);
    PopulateArray(arrK, k);

    std::cout << "< arrK is in arrN: " << Contains(arrN, arrK, n, k) << " times";

    return 0;
}

/*
Write a program that reads two numbers N & K from STDIN (N between 5 and 50, K between 4 and N) 
and then subsequently reads two sequences - first consisting of N numbers, second consisting of 
K numbers from STDIN. 
At the end of the program write on STDOUT the number of times that the second sequence appears 
in the first one.

1 2 3 4 -> 4
1 2 3 4 5 6 -> 6  6-4+1=3
1 2 3 4
  1 2 3 4
    1 2 3 4
*/