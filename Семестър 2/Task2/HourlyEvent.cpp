#include<iostream>
#include"HourlyEvent.h"

HourlyEvent::HourlyEvent(unsigned startingHourParam, unsigned short numberOfRepeatsParam)
	: Event(startingHourParam)
{
	if (numberOfRepeatsParam <= 5)
		numberOfRepeats = numberOfRepeatsParam;
	else
		numberOfRepeats = 5;
}

Event* HourlyEvent::clone() const
{
	return new HourlyEvent(*this);
}

void HourlyEvent::print() const
{
	Event::print();
	std::cout << numberOfRepeats << std::endl;
}

bool HourlyEvent::inTimePeriod(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes) const
{
	bool a = Event::inTimePeriod(startHour, startMinutes, endHour, endMinutes);
	bool b = (Event::getHour() + numberOfRepeats) <= endHour;
	return a && b;
}
