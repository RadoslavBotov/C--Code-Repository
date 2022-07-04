#include<iostream>
#include"SingleEvent.h"

SingleEvent::SingleEvent(unsigned startingHourParam)
	: Event(startingHourParam) {}

Event* SingleEvent::clone() const
{
	return new SingleEvent(*this);
}

void SingleEvent::print() const
{
	Event::print();
	std::cout << std::endl;
}

bool SingleEvent::inTimePeriod(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes) const
{
	return Event::inTimePeriod(startHour, startMinutes, endHour, endMinutes);
}
