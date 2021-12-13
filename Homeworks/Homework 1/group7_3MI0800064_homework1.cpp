#include <iostream>
#include <cmath>
//#include <stdlib.h>
//#include <time.h>

//------------------------------------------------------------ Task 0 ------------------------------------------------------------

void inputTask0(double &x, double &y) // прочита дробни числа
{
    std::cout << "> X, Y: ";
    std::cin >> x >> y;
}

int whichArea(double x, double y)
{
    const double POINT = 2.828; // Approximation (2 * sqrt(2) = 2.82842712475) with precision of 3 digits after decimal point
                                // for values (x, y) for points B, C, D, E

    if (x * x + y * y < 16)
    {
        if ((x < 0 && x > -POINT) && (y > 0 && y < 4) && (-x < y)) // chech if inside red area
            return 1;

        if ((x > 0 && x < POINT) && (y > 0 && y < 4) && (x < y)) // chech if inside green area
            return 2;

        if ((x < 0 && x > -POINT) && (y < POINT && y > -POINT) && (-x > y && x < y)) // chech if inside pink area
            return 3;

        if ((x > 0 && x < POINT) && (y < POINT && y > -4) && (x > y)) // chech if inside yellow area
            return 4;

        if ((x < 0 && x > -POINT) && (y < 0 && y > -4) && (x > y)) // chech if inside blue area
            return 5;

        if (x > POINT) // chech if inside purple area
            return 6;
    }

    if ((x > -2 && x < 2) && (y < -6 && y > -7)) // chech if inside gray area
        return 7;

    return 8; // Point is outside all areas.
}

void printMessage(double x, double y, std::string s)
{
    std::cout << "Point (" << x << ", " << y << ") is inside the " << s << " area." << std::endl;
}

void isInsideAnyArea(double x, double y)
{
    switch (whichArea(x, y))
    {
    case 1:
        printMessage(x, y, "Red");
        break;

    case 2:
        printMessage(x, y, "Green");
        break;

    case 3:
        printMessage(x, y, "Pink");
        break;

    case 4:
        printMessage(x, y, "Yellow");
        break;

    case 5:
        printMessage(x, y, "Blue");
        break;

    case 6:
        printMessage(x, y, "Purple");
        break;

    case 7:
        printMessage(x, y, "Gray");
        break;

    default:
        std::cout << "Point (" << x << " , " << y << ") is NOT inside any area." << std::endl;
        break;
    }
}

void task0()
{
    std::cout << "\nTask 0:\n";

    double x, y;

    inputTask0(x, y);

    isInsideAnyArea(x, y);
}

//------------------------------------------------------------ Task 1 ------------------------------------------------------------

int cinTask1(int x)
{
    std::cout << "> X: ";
    std::cin >> x;

    return x;
}

void calculateFunction(int x, int k)
{
    int current = x, next;

    for (int i = 0; i < k; i++)
    {
        if (current % 2 == 0)
            next = current / 2;
        else
            next = 3 * current + 1;

        current = next;
    }

    std::cout << "Function f(" << x << ") on step 35 = " << next;
}

void task1()
{
    std::cout << "\nTask 1:\n";

    int x = cinTask1(x);

    calculateFunction(x, 35);
}

//------------------------------------------------------------ Task 2 ------------------------------------------------------------

int cinTask2(int number) // input for the number of digits the input will have (1 barcode = 8 digits)
{
    do
    {
        std::cout << "Must have at least 8 digits: ";
        std::cin >> number;

    } while (number < 8);

    return number;
}

void inputBarcodeDigit(int &digit) // input for barcode digits
{
    do
    {
        std::cin >> digit;

        if (digit < 0)
            std::cout << " ! Digit must be bigger than 0 !\n";

    } while (digit < 0);
}

void barcodeIdentifier(int numberOfDigits)
{
    int jamBlueberries = 0, jamPeaches = 0, jamRoseHip = 0;
    int digit, number = 0;
    int digitBr = 1, numberBr = 0;

    std::cout << "> Barcode digits:\n";

    if (numberOfDigits < 8)
        std::cout << "Invalid barcode! Barcode has less than 8 digits." << std::endl;
    else
    {
        while (numberOfDigits > 0)
        {
            inputBarcodeDigit(digit);

            if (digitBr == 4)
            {
                numberBr++;
                number = number * 10 + digit;
            }
            else
                digitBr++;

            if (numberBr == 4)
            {
                if (number % 7 == 0)
                    jamBlueberries++;
                else if (number % 13 == 0)
                    jamPeaches++;
                else if (number % 17 == 0)
                    jamRoseHip++;

                number = 0;
                numberBr = 0;
                digitBr = 0;
            }

            numberOfDigits--;
        }

        std::cout << "Number of blueberrie jam: " << jamBlueberries << std::endl; // Мармалад от боровинки
        std::cout << "Number of peach jam : " << jamPeaches << std::endl;         // Мармалад от праскови
        std::cout << "Number of rose hip jam : " << jamRoseHip << std::endl;      // Шипков мармалад
    }
}

void task2()
{
    std::cout << "\n\nTask 2:\n";

    int numberOfDigits = cinTask2(numberOfDigits);

    barcodeIdentifier(numberOfDigits);
}

//------------------------------------------------------------ Task 3 ------------------------------------------------------------

void inputTask3(int &a, int &b) // цели числа a и b
{
    std::cout << "> A, B: ";
    std::cin >> a >> b;
}

int isEven(int number)
{
    return number % 2 == 0;
}

bool isNumberInterestin(int number) // number = 123 is interesting
{
    if (number < 0)
        number *= -1;

    int current = number % 10;
    number /= 10;
    while (number > 0)
    {
        if (!(isEven(number % 10) ^ isEven(current))) // checks if two adjacent digits in the number have the same parity
            return false;                             // if they do, number is not interesting and returns false
        current = number % 10;
        number /= 10;
    }
    return true; // if all parity checks are false => number is interesting and returns true
}

void sumOfInterestingNumbers(int a, int b)
{
    long long sum = 0;

    std::cout << "The interesting numbers in the interval [" << a << ", " << b << "] are: ";

    for (int i = a; i <= b; i++)
        if (isNumberInterestin(i))
        {
            std::cout << i << " ";
            sum += i;
        }

    std::cout << "\nTheir sum is " << sum;
}

void task3()
{
    std::cout << "\nTask 3:\n";

    int a, b;

    inputTask3(a, b);

    sumOfInterestingNumbers(a, b);
}

//------------------------------------------------------------ Task 4 ------------------------------------------------------------

int countDigits(int number) // counts the digits of a number
{
    int br = 0;
    while (number > 0)
    {
        br++;
        number /= 10;
    }
    return br;
}

bool isNumberValid(int number) // checks if number contains a 0
{
    while (number > 0)
    {
        if (number % 10 == 0)
            return false;

        number /= 10;
    }
    return true;
}

bool hasDuplicateDigits(int number) // checks if number has duplicate digits
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

void task4()
{
    std::cout << "\n\nTask 4:\n";

    int lives = 10;
    int secretNumber = secretNumberGenerator(secretNumber);
    //int secretNumber = 4271;

    std::cout << "Secret number: " << secretNumber << std::endl;
    gamePlay(lives, secretNumber);
}

//------------------------------------------------------------  Main  ------------------------------------------------------------

int main()
{
    //task0();

    //task1();

    //task2();

    //task3();

    //task4();

    return 0;
}