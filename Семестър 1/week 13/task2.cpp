// Дадена e матрица от char-ове с размер 10х10, начална точка start с координати x1, y1 и крайна точка end с координати x2, y2.
// Намерете има ли път от точка start до точка end.
#include <iostream>
using namespace std;

bool path(int matrix[][10], int startX, int startY, int endX, int endY)
{
    if (startX == endX && startY == endY)
        return true;

    //if ()
}

int main()
{
    int matrix[10][10] = {
        {'1', '1', '0', '0', '0', '1', '1', '1', '0', '0'},
        {'S', '1', '0', '0', '1', '0', '0', '0', '0', 'E'}, // S <- E
        {'0', '1', '1', '0', '0', '0', '1', '0', '0', '1'},
        {'0', '0', '1', '0', '0', '1', '1', '1', '0', '1'},
        {'0', '0', '0', '0', '1', '1', '0', '1', '0', '0'},
        {'0', '1', '0', '0', '0', '1', '1', '1', '0', '1'},
        {'0', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '0', '1', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '0', '0', '0', '1', '1', '1', '1', '1'},
        {'1', '1', '1', '0', '0', '0', '1', '0', '0', '0'}};

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << path(matrix, x1, y1, x2, y2);

    return 0;
}