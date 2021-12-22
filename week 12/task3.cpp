// Да се напише функция, която пресмята 1 + 1/4 + 1/9 + ... + 1/n^2.
#include <iostream>
using namespace std;

double sumOfExpresion(double n)
{
    if (n == 1)
        return 1;
    return 1 / (n * n) + sumOfExpresion(n - 1);
}

int main()
{
    double n;

    cout << "> N: ";
    cin >> n;

    cout << sumOfExpresion(n);

    return 0;
}