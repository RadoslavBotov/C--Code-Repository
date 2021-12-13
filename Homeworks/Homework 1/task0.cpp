#include <iostream>
#include <cmath>

void inputTask0(double &x, double &y) // прочита дробни числа
{
    std::cout << "> X, Y: ";
    std::cin >> x >> y;
}

int whichArea(double x, double y)
{
    const double POINT = 2.828; // Approximation (2 * sqrt(2) = 2.82842712475) with precision of 3 digits after decimal point
                                // for values (x, y) for points B, C, D, E

    if (x * x + y * y < 16)
    {
        if ((x < 0 && x > -POINT) && (y > 0 && y < 4) && (-x < y)) // chech if inside red area
            return 1;

        if ((x > 0 && x < POINT) && (y > 0 && y < 4) && (x < y)) // chech if inside green area
            return 2;

        if ((x < 0 && x > -POINT) && (y < POINT && y > -POINT) && (-x > y && x < y)) // chech if inside pink area
            return 3;

        if ((x > 0 && x < POINT) && (y < POINT && y > -4) && (x > y)) // chech if inside yellow area
            return 4;

        if ((x < 0 && x > -POINT) && (y < 0 && y > -4) && (x > y)) // chech if inside blue area
            return 5;

        if (x > POINT) // chech if inside purple area
            return 6;
    }

    if ((x > -2 && x < 2) && (y < -6 && y > -7)) // chech if inside gray area
        return 7;

    return 8; // Point is outside all areas.
}

void printMessage(double x, double y, std::string s)
{
    std::cout << "Point (" << x << ", " << y << ") is inside the " << s << " area." << std::endl;
}

void isInsideAnyArea(double x, double y)
{
    switch (whichArea(x, y))
    {
    case 1:
        printMessage(x, y, "Red");
        break;

    case 2:
        printMessage(x, y, "Green");
        break;

    case 3:
        printMessage(x, y, "Pink");
        break;

    case 4:
        printMessage(x, y, "Yellow");
        break;

    case 5:
        printMessage(x, y, "Blue");
        break;

    case 6:
        printMessage(x, y, "Purple");
        break;

    case 7:
        printMessage(x, y, "Gray");
        break;

    default:
        std::cout << "Point (" << x << " , " << y << ") is NOT inside any area." << std::endl;
        break;
    }
}

int main()
{
    double x, y;

    inputTask0(x, y);

    isInsideAnyArea(x, y);

    return 0;
}
/*
Задача 0 (0,75 т.) Дадена е следната фигурата в декартова координатна система. Да се напише програма, която прочита от 
клавиатурата координатите на точка (дробни числа) и определя дали точката е в:

червената област, зелената област, розовата област, жълтата област, синята област, лилавата област, сивата област.

Ако точката лежи на границата между две или повече области, счита се, че не в нито една от тях. 
Програмата да извършва сравненията с точност три знака след десетичната запетая и да извежда подходящи съобщения.
*/