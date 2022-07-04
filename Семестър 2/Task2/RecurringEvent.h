#pragma once
#include"Event.h"

class RecurringEvent : public Event
{
public:
	RecurringEvent(unsigned startingHourParam, unsigned repeatPeriodParam, unsigned short numberOfRepeatsParam);

	virtual Event* clone() const override;

	virtual void print() const override;

	virtual bool inTimePeriod(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes) const override;

private:
	unsigned repeatPeriod; // 3 minutes to 3 hours
	unsigned short numberOfRepeats; // <= 5
};