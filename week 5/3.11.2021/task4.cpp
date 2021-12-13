#include <iostream>

bool CheckIfPrime(int num)
{
    if (num <= 1)
        return false;

    for (int i = 2; i <= sqrt(num); i++)
        if (num % i == 0)
            return false;

    return true;
}

bool CheckIfOdd(int num)
{
    return !(num % 2 == 0);
}

int main()
{
    int m, n;

    std::cin >> m >> n;

    for (int i = m; i < n - 4; i++)
    {
        int j = i + 4;
        if (CheckIfPrime(i) && CheckIfPrime(j))
            if (CheckIfOdd(i) && CheckIfOdd(j))
                std::cout << i << " " << j << std::endl;
    }

    return 0;
}

/*
Две числа се наричат сдвоени прости числа, ако са прости и ако a + 4 = b. 
Напишете програма, която извежда на екрана всички двойки сдвоени нечени числа в даден интервал [m, n], 
където m и n се въвеждат от конзолата.
*/