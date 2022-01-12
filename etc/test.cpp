#include <iostream>
#include <cstring>

int main()
{
    char str[] = "12345";

    strncpy(str + 1, "  ", 2);

    std::cout << str;

    return 0;
}