#include <iostream>

int mostCommonElmt(int *arr, int length)
{
    int count = 1;
    int position;
    for (int i = 0; i < length; i++)
    {
        if (count > 1)
            if (arr[i] == arr[position])
                continue;

        for (int l = i + 1; l < length - 1; l++)
            if (arr[i] == arr[l])
            {
                count++;
                position = i;
            }
    }

    return count;
}

int main()
{
    int arr[] = {0, 1, 0, 4, 4, 4, 1, 4, 1};

    std::cout << mostCommonElmt(arr, 9);
    
    return 0;
}