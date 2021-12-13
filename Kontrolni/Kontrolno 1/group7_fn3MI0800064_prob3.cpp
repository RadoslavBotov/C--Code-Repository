#include <iostream>

int cin_(std::string s, int number, int leftLimit, int rightLimit)
{
    do
    {
        std::cout << "> " + s + ": ";
        std::cin >> number;
    } while (number < leftLimit || number > rightLimit);
    return number;
}

void populateArray(std::string s, char arr[], char size)
{
    std::cout << "> " + s + ": ";
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
}

void rotateArray(char arr[], int size)
{
    int temp = arr[size - 1];
    for (int i = size - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = temp;
}

void printArray(char arr[], int size)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
}

bool subArrayMatch(char firstArr[], char secondArr[], int size2, int i)
{
    int p = 0;
    for (int t = i; t < size2 + i; t++)
    {
        if (firstArr[t] != secondArr[p])
            return false;
        p++;
    }
    return true;
}

void findRotation(char firstArr[], char secondArr[], int size1, int size2)
{
    bool flag = true;
    for (int j = 0; j < size2; j++)
    {
        for (int i = 0; i < size1 - size2 + 1; i++)
        {
            if (subArrayMatch(firstArr, secondArr, size2, i))
            {
                std::cout << "Rotation: ( ";
                printArray(secondArr, size2);
                std::cout << ") after deleting "
                          << i
                          << " characters from the start and "
                          << size1 - size2 - i
                          << " characters from the end.\n";
                flag = false;
            }
        }
        rotateArray(secondArr, size2);
    }
    
    if (flag)
        std::cout << "No rotation found.";
}
/*
Rotation "llo" found after deleting 2 characters from the start and 0 characters from the end
*/
int main()
{
    int size1, size2;
    char firstArr[1024], secondArr[1024];

    size1 = cin_("Size1", size1, 0, 1024);
    size2 = cin_("Size2", size2, 0, size1);

    populateArray("FirstArr", firstArr, size1);
    populateArray("SecondArr", secondArr, size2);

    findRotation(firstArr, secondArr, size1, size2);

    return 0;
}

/*
group7_fn3MI0800064_prob3.cpp

“Подредица” на дадена редица наричаме редица, която се получава след евентуалното изтриване на нула или повече елементи в 
началото и края на първоначалната редица.
Пример: редиците abc, cd, de са три подредици на редицата abcde.

“Ротация” на дадена редица се нарича такава подредба на елементите на редицата, която се получава като няколко елементи от края 
на редицата се преместят в същия ред в началото на редицата.
Пример: всички възможни ротации на редицата abcde са eabcd, deabc, cdeab и bcdea.

Да се напише програма, която въвежда от стандартния вход две положителни цели числа size1 и size2 и две редици от латински букви
 firstArr и secondArr, съответно с дължини size1 и size2. Програмата да определи дали някоя ротация на secondArr е подредица на 
 firstArr, и ако това е така да изведе ротацията и да изведе колко символа от началото и края на firstArr трябва да се изтрият, 
 за да се получи подредицата secondArr. Ако такава ротация няма, да се изведе подходящо съобщение.
*/