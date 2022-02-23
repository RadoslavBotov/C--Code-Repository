#include <iostream>
using namespace std;

bool fibonachi(int a, int b, int number)
{
    if (number == a || number == b)
        return true;

    if (number < a + b)
        return false;

    return fibonachi(b, a + b, number);
}

int main()
{
    int n;
    cin >> n;

    cout << fibonachi(0, 1, n);

    return 0;
}