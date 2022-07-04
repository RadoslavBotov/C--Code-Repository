#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<doctest.h>
#include<iostream>
using namespace std;

#include"MyString.h"

TEST_CASE("Empty")
{
	MyString str("123");
	CHECK(str.empty() == 0);
}

TEST_CASE("Empty")
{
	MyString str("123");
	CHECK(str.empty() != 1);

	str.push_back('!');
}