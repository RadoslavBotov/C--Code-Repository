#pragma once
#include"Event.h"
#include"SingleEvent.h"

class EventManager
{
public:
	EventManager(size_t capacityParam = 10);
	EventManager(const EventManager& source);
	EventManager& operator = (const EventManager& source);
	~EventManager();

	bool addEvent(const Event* event);
	unsigned occuredEvent(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes);
	void print() const;

private:
	Event** events;
	size_t capacity;
	size_t size;

	void freeMemory();
};