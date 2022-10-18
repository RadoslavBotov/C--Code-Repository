#include <iostream>
#include "TwoWayLinkedStack.h"
using namespace std;

int main()
{
	TWLStack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	//cout << s.pop();
	//cout << s.pop();
	//cout << s.pop();

	s.print1();
	s.print2();

	return 0;
}