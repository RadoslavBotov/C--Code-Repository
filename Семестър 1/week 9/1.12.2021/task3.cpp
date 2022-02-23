/*
Напишете две функции void changeValue(int* a) и void changeValue(int& a), които добавят 5 към стойността на a. 
Защо това ни е позволено? 
По какъв начин работи всяка от фунцкиите? 
Защо void changeValue(int a) няма да ни свърши работа?
*/
#include <iostream>

void changeValue(int *a)
{
    *a += 5;
}

void changeValue(int &a)
{
    a += 10;
}

int main()
{
    int a = 0;

    changeValue(&a);
    changeValue(a);

    std::cout << a;

    return 0;
}