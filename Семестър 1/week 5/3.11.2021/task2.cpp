#include<iostream>

int main()
{
    int num;
    std::cin >> num;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num - i + 1; j++)
            std::cout << j << " ";
        std::cout << std::endl;
        
        for (int t = 0; t < i; t++)
            std::cout << "  ";
    }

    return 0;
}

/*
Да се изведе следната "фигура" на конзолата:

1 2 3 4 5 6 7
  1 2 3 4 5 6
    1 2 3 4 5
      1 2 3 4
        1 2 3
          1 2
            1
*/