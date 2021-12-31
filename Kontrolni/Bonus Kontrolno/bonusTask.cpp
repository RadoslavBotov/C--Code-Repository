/*
    Да се напише рекурсивна функция, която намира числото xy, по въведени сбор x+y от цифрите x и y и разликата между числата yx - xy.
    Пример:
    Вход:
    Сбор x + y = 12;        4 + 8 = 12
    Разлика yx - xy = 36.   84 - 48 = 36 -> xy = yx - div
    Изход: 48
*/
#include <iostream>
using namespace std;

int findNumber(int sum, int div)
{
}

int main()
{
    int x, y;
    int sum;
    int div;

    cout << "> x + y = ";
    cin >> sum;

    cout << "> yx - xy = ";
    cin >> div;

    cout << sum << " " << div;

    return 0;
}