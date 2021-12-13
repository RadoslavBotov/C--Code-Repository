/*
Създайте променлива a и указател ptr към нея. Изведете в конзолата адреса на променливата a и стойността на p, променете 
съдържанието в a и изведете в конзолата стойността на *ptr.
*/
#include <iostream>

int main()
{
    int a;
    int *ptr = &a;

    std::cout << "Pointer: " << ptr << std::endl;

    int num;
    std::cout << "> Number: ";
    std::cin >> num;

    *ptr = num;

    std::cout << "Pointer value: " << *ptr << std::endl;

    return 0;
}