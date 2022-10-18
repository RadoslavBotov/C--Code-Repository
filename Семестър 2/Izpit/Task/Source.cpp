#include<iostream>
#include"SimplePair.h"
#include"InterpolationPair.h"
#include"TagPair.h"
using namespace std;

int main()
{
	InterpolationPair p("aabc_a", "My name is %{username} and I am %{years} years old.");
	p.printValue();

	//TagPair t("qwe_html","\"1234\"");

	return 0;
}