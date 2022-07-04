#include<iostream>
#include"RecurringEvent.h"

RecurringEvent::RecurringEvent(unsigned startingHourParam, unsigned repeatPeriodParam, unsigned short numberOfRepeatsParam)
	: Event(startingHourParam)
{
	repeatPeriod = repeatPeriodParam; // ! validate later !

	if (numberOfRepeatsParam <= 5)
		numberOfRepeats = numberOfRepeatsParam;
	else
		numberOfRepeats = 5;
}

Event* RecurringEvent::clone() const
{
	return new RecurringEvent(*this);
}

void RecurringEvent::print() const
{
	Event::print();
	std::cout << repeatPeriod << " " << numberOfRepeats << std::endl;
}

bool RecurringEvent::inTimePeriod(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes) const
{
	bool a = Event::inTimePeriod(startHour, startMinutes, endHour, endMinutes);
	bool b = (Event::getHour() + repeatPeriod * numberOfRepeats) <= endHour;
	return a && b;
}
