#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int rec(int a)
{
    if (a == 1)
        return 1;
    return a * rec(a - 1);
}

int main()
{
    long start, end, result;
    long n = 5;

    start = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    result = rec(n);
    end = duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count();
    cout << n << "th factoriel = " << result << " (took " << end - start << "ns)" << endl;

    return 0;
}