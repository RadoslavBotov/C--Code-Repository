#include <iostream>
//#include <stdlib.h>
//#include <time.h>

int countDigits(int number)
{
    int br = 0;
    while (number > 0)
    {
        br++;
        number /= 10;
    }
    return br;
}

bool isNumberValid(int number)
{
    while (number > 0)
    {
        if (number % 10 == 0)
            return false;

        number /= 10;
    }
    return true;
}

bool hasDuplicateDigits(int number)
{
    int arr[4];
    for (int i = 3; i >= 0; i--)
    {
        arr[i] = number % 10;
        number /= 10;
    }

    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            if (arr[i] == arr[j])
                return false;

    return true;
}

int secretNumberGenerator(int secretNumber)
{
    srand(time(0));

    do
    {
        secretNumber = rand() % 9999 + 1000;

        if (countDigits(secretNumber) == 4)                                      // secret number has 4 digits
            if (isNumberValid(secretNumber) && hasDuplicateDigits(secretNumber)) // secret number has no 0 and no duplicate digits
                return secretNumber;

    } while (true);
}

int inputTask4(int guess)
{
    do
    {
        std::cin >> guess;

        if (countDigits(guess) == 4)                               // guess has 4 digits
            if (isNumberValid(guess) && hasDuplicateDigits(guess)) // guess has no 0 and no duplicate digits
                return guess;
            else
                std::cout << "Invalid guess! Input again: ";
        else
            std::cout << "Invalid guess! Input again: ";

    } while (true);
}

void bullsAndCows(int secretNumberCopy, int guessCopy)
{
    int bulls = 0, cows = 0;
    int arrGuess[4], arrSecterNumber[4];

    for (int i = 3; i >= 0; i--)
    {
        arrGuess[i] = guessCopy % 10;
        guessCopy /= 10;
    }

    for (int i = 3; i >= 0; i--)
    {
        arrSecterNumber[i] = secretNumberCopy % 10;
        secretNumberCopy /= 10;
    }

    for (int i = 0; i < 4; i++)
        if (arrGuess[i] == arrSecterNumber[i])
            bulls++;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (i != j)
                if (arrGuess[i] == arrSecterNumber[j])
                    cows++;

    std::cout << bulls << " bulls and " << cows << " cows\n\n";
}

void gamePlay(int lives, int secretNumber)
{
    bool winCondition = false;

    while (lives > 0)
    {
        std::cout << " > Lives: " << lives << " <" << std::endl;
        std::cout << "> Guess secret number: ";
        int guess = inputTask4(guess);

        if (guess == secretNumber)
        {
            winCondition = true;
            break;
        }
        else
            bullsAndCows(secretNumber, guess);

        lives--;
    }

    if (winCondition)
        std::cout << "You win! The secret number is indeed: " << secretNumber;
    else
        std::cout << "You lose! The secret number was: " << secretNumber;
}

int main()
{
    int lives = 10;
    int secretNumber = secretNumberGenerator(secretNumber);
    //int secretNumber = 4271;

    std::cout << secretNumber << std::endl;
    gamePlay(lives, secretNumber);

    return 0;
}
/*
Бикове и крави е логическа игра за отгатване на цифри. Играе се от двама противника, като всеки се стреми да отгатне тайното число, 
намислено от другия. След всеки ход, противникът дава броя на съвпаденията.
Играта протича по следния начин. На лист хартия всеки участник написва своето тайно число. Тайните числа са четирицифрени, като 
цифрите не трябва да се повтарят. След това, последователно един след друг, играчите задават въпрос с предположение за числото на 
противника. Противникът отговаря, като посочва броя на съвпаденията – ако дадена цифра от предположението се съдържа в тайното 
число и се намира на точното място, тя е „бик“, ако е на различно място, е „крава“.

Пример:
Тайно число:   4271
Предположение: 1234
Отговор: „1 бик и 2 крави“. (Бикът е „2“, а кравите са „4“ и „1“.)
Първият играч, който открие тайното число на противника, е победител.

Дадена е следната модификация на играта:
Тайното число се състои от 4 различни цифри от 1 до 9 (т.е. не се използва цифрата 0).
Само „първият“ играч намисля число, а „вторият“ се опитва да го познае за определен брой ходове.
В исканата реализация програмата „намисля“ тайно число, а потребителя се опитва
да го отгатне. Ако потребителят успее да познае тайното число с не повече от N хода, то той печели играта и вижда подходящо 
съобщение на екрана. В противен случай компютърът печели играта. N е предварително зададена константа.

Упътване:
За измислянето на числото може използвате функцията rand, с подходяща валидация, или друг подходящ алгоритъм. 

*/