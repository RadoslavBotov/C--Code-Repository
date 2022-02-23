#include <iostream>

int Cin(int length)
{
    std::cout << "> Length: ";
    std::cin >> length;
    return length;
}

void PopulateArray(int arr[], int &length)
{
    std::cout << "> arr[" << length << "]: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];
}

void PrintArray(int arr[], int length)
{
    std::cout << "< ";
    for (int i = 0; i < length; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n\n";
}

void Actions(int arr[], int length)
{
}

int main()
{
    //int arr[100], length = Cin(length);
    int money, cost, wrapers = 0, wraperCost, sum = 0;

    std::cout << "> Inputs: ";
    std::cin >> money >> cost >> wraperCost;

    wrapers = sum += money / cost;
    sum += (sum + wrapers / wraperCost) / wraperCost;

    std::cout << "< Chocolates: " << sum;

    return 0;
}

/*
Вход: Три цели числа n,c,m, където:

n е единиците(парите), с които Боби разполага
c е цената в (единици) за един шоколад
m е броят опаковки, които са нужни на Боби за да получи шоколад в замяна

Изход: Максималния брой шоколадчета, които Боби може да изяде по време на промоцията.
    6 2 2 -> 5
*/