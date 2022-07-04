#pragma once
#include<iostream>

class Event
{
public:
	Event(unsigned startingHourParamParam)
	{
		if (startingHourParamParam >= 0 && startingHourParamParam <= 23)
			startingHour = startingHourParamParam;
		else startingHour = 23;
	}

	virtual ~Event() = default;

	unsigned getHour() const
	{
		return startingHour;
	}

	virtual Event* clone() const = 0;

	virtual void print() const
	{
		std::cout << startingHour << " ";
	}
	// 10:00 - 12:12 10
	virtual bool inTimePeriod(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes) const
	{
		if (startMinutes != 0 && startingHour == startHour)
			return false;

		return (startingHour >= startHour && startingHour <= endHour);
	}

private:
	unsigned startingHour;
};