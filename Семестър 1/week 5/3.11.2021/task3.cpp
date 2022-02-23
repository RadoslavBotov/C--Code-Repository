#include<iostream>

int main()
{
    int num;
    
    std::cin >> num;

    for (int i = 0; i < num; i++)
    {
         for (int t = 1; t < num - i; t++)
             std::cout << " ";

        for (int j = 0; j <= i; j++)
            std::cout << "#";
        std::cout << std::endl;
    }

    return 0;
}

/*
Да се изведе следната "фигура" на конзолата, по въведено n:

   #
  ##
 ###
####
*/