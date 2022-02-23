#include <iostream>

void PopulateArray(int arr[], int &length)
{
    std::cout << "> arr[" << length << "]: ";
    for (int i = 0; i < length; i++)
        std::cin >> arr[i];
}

int Cin(int length)
{
    std::cout << "> Length: ";
    std::cin >> length;
    return length;
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
    if (arr[0] != 1 && arr[0] != 2)
    {
        std::cout << "< INTCODE is incorrect.\n\n";
    }
    else
    {
        int i = 0;

        for (int j = 0; j < (length - 1) / 4; j++)
        {
            if (arr[i] == 99)
            {
                std::cout << "< Met 99 stop code.\n";
            }
                
            else
            {
                if (arr[i] == 1)
                    arr[arr[i + 3]] = arr[arr[i + 2]] + arr[arr[i + 1]];

                if (arr[i] == 2)
                    arr[arr[i + 3]] = arr[arr[i + 2]] * arr[arr[i + 1]];

                i += 4;
            }
        }

        PrintArray(arr, length);
    }
}

int main()
{
    int arr[1024], length = Cin(length);

    PopulateArray(arr, length);
    Actions(arr, length);

    return 0;
}

/*
Инткод програма ще наричаме поредица от цели числа от типа {1, 0, 0, 3, 99}, в която 
числата ще указват някакви операции и елементите, върху които ги извършваме. 
Опкод ще наричаме число, което указва операцията.

Ако опкодът е:

99: Програмата приключва.

1: Събираме две числа, прочетени от някакви позиции и записваме сбора на трета позиция. 
Трите числа след опкода обозначават тези позиции - първите две казват на кои позиции се 
намират събираемите, а третото - на коя позиция да запишем сбора.

2: Същото, но умножаваме вместо да събираме.

Примерен вход и изход:

1, 0, 0, 0, 99 става 2, 0, 0, 0, 99
2, 3, 0, 3, 99 става 2, 3, 0, 6, 99
2, 4, 4, 5, 99, 0 става 2, 4, 4, 5, 99, 9801
1, 1, 1, 4, 99, 5, 6, 0, 99 става 30, 1, 1, 4, 2, 5, 6, 0, 99.
*/