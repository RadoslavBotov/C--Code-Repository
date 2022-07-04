#include"iostream"
#include"EventManager.h"

EventManager::EventManager(size_t capacityParam)
{
	size = 0;
	capacity = capacityParam;

	events = new Event * [capacityParam];
}

EventManager::EventManager(const EventManager& source)
{
	size = source.size;
	capacity = source.capacity;

	for (size_t i = 0; i < size; i++)
		events[i] = source.events[i]->clone();
}

EventManager& EventManager::operator = (const EventManager& source)
{
	if (this != &source)
	{
		freeMemory();

		size = source.size;
		capacity = source.capacity;

		for (size_t i = 0; i < size; i++)
			events[i] = source.events[i]->clone();
	}
	return *this;
}

EventManager::~EventManager()
{
	freeMemory();
}

bool EventManager::addEvent(const Event* event)
{
	if (size == capacity)
	{
		std::cout << "> Collection is full!" << std::endl;
		return false;
	}

	events[size++] = event->clone();

	return true;
}

unsigned EventManager::occuredEvent(unsigned startHour, unsigned startMinutes, unsigned endHour, unsigned endMinutes)
{
	unsigned br = 0;
	for (size_t i = 0; i < size; i++)
		if (events[i]->inTimePeriod(startHour, startMinutes, endHour, endMinutes))
			br++;
	return br;
}

void EventManager::print() const
{
	for (size_t i = 0; i < size; i++)
		events[i]->print();
}

void EventManager::freeMemory()
{
	for (size_t i = 0; i < size; i++)
		delete events[i];
	delete[] events;

	capacity = 0;
	size = 0;
}
