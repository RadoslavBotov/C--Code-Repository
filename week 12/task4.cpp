// Да се напише рекурсивна функция, която намира сумата на цифрите в дадено число.
#include <iostream>
using namespace std;

int sumOfDigits(int number)
{
    if (number == 0)
        return 0;

    return number % 10 + sumOfDigits(number / 10);
}

int main()
{
    int number;

    cin >> number;

    cout << sumOfDigits(number);

    return 0;
}