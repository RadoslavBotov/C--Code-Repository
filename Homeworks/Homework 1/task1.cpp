#include <iostream>

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

int main()
{
    int x = cinTask1(x);

    calculateFunction(x, 35);

    return 0;
}

/*
Нека е дадено, че f1(x) = x и за всяко k > 1 е изпълнено, че:

fk+1(x) = fk(x) / 2    if fk(x) is even
          fk(x) * 3 +1 if fk(x) is odd

Да се напише програма, която въвежда цяло число от клавиатурата x и пресмята f35(x).
*/