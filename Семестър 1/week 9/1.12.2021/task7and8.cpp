// Напишете фунцкия, която проверява дали два символни низа са с еднаква дължина.
// Напишете фунцкия, която проверява дали два символни низа са еднакви.
#include <iostream>

int strlen(char *string)
{
    int br = 0;

    while (string[br] != '\0')
        br++;

    return br;
}

bool sameLength(char *arr1, char *arr2)
{
    return strlen(arr1) == strlen(arr2);
}

bool sameArrays(char *arr1, char *arr2)
{
    if (strlen(arr1) - strlen(arr2) != 0)
        return false;

    for (int i = 0; i < strlen(arr1); i++)
        if (arr1[i] != arr2[i])
            return false;

    return true;
}

int main()
{
    char arr1[100], arr2[100];

    std::cout << "> Array 1 : ";
    std::cin >> arr1;
    std::cout << "> Array 2 : ";
    std::cin >> arr2;

    std::cout << "Same length: " << sameLength(arr1, arr2) << std::endl;
    std::cout << "Same arrays: " << sameArrays(arr1, arr2) << std::endl;

    return 0;
}