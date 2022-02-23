// Да се напише рекурсивна функция, която пресмята факториел от числотo n.
#include <iostream>
using namespace std;

int factoriel(int number)
{
    if (number == 1)
        return 1;

    return number * factoriel(number - 1);
}

int main()
{
    int n;

    cin >> n;

    cout << factoriel(n);

    return 0;
}