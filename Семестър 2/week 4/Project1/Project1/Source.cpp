//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<iostream>
#include "doctest.h"
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    if (a == b)
        return a;
    
	if (a > b)
		return gcd(a - b, b);
	return gcd(a, b - a);
}
/*
int main()
{
	return 0;
}
*/ 

TEST_CASE("GCD Function")
{
    CHECK(gcd(0, 0) == 0);
    CHECK(gcd(0, 10) == 10);
    CHECK(gcd(10, 0) == 10);
    CHECK(gcd(0, -10) == -10);
    CHECK(gcd(-10, 0) == -10);
    CHECK(gcd(1, 1) == 1);
    CHECK(gcd(-1, -1) == -1);
    //CHECK(gcd(1, -1) == 1);
    //CHECK(gcd(-1, 1) == 1);
}