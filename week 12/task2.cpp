// Напишете програма която пресмята израза sum = ( ...(((x + 2)x + 3)x + 4)x +... + (y-1))x + y; ,
// където x и y са въведени от конзолата.
#include <iostream>
using namespace std;

int sumOfExpresion(int x, int y)
{
    if (y == 2)
        return x + 2;

    return sumOfExpresion(x, y - 1) * x + y;
}

int main()
{
    int x, y;

    cout << "> X, Y: ";
    cin >> x >> y;

    cout << sumOfExpresion(x, y);

    return 0;
}