#include<iostream>
#include"HourlyEvent.h"
#include"RecurringEvent.h"
#include"SingleEvent.h"
#include"EventManager.h"
using namespace std;

int main()
{
	EventManager e1;

	SingleEvent a(1);
	HourlyEvent b(2, 2);
	RecurringEvent c(3, 3, 3);

	e1.addEvent(&a);
	e1.addEvent(&b);
	e1.addEvent(&c);

	e1.print();

	return 0;
}