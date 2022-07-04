#pragma once
#include"Event.h"

class SingleEvent : public Event
{
public:
	SingleEvent(unsigned startingHourParam);

	virtual Event* clone() const override;

	virtual void print() const override;

	virtual bool inTimePeriod(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes) const override;

private:
	// no additional fields
};