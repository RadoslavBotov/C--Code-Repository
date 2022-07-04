#include <iostream>
using namespace std;

class Point2D
{
private:
    int x = 0;
    int y = 0;

public:
    void print()
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
};

int main()
{
    cout << (1000000000000000100 == 1000000000000000) << endl;

    return 0;
}