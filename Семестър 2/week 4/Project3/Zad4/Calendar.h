#pragma once

class Calendar
{
private:
	Event* events;
	unsigned short current;
	unsigned short capacity;

	void swap(Event* e1, Event* e2)
	{
		Event temp = *e1;
		*e1 = *e2;
		*e2 = temp;
	}

public:
	Calendar(unsigned short capacityVal) : events(nullptr), current(0), capacity(100)
	{
		if (capacityVal < 100)
			capacity = capacityVal;
		else
			cout << "> Number (" << capacityVal << ") exceedes maximum capacity. Capacity set to maximum (100)." << endl;

		events = new Event[capacity];
	}

	~Calendar()
	{
		delete[] events;
	}

	void addEvent(Event& event)
	{
		double hours = 0;

		for (int i = 0; i < current; i++)
			if (events[i].getDate() == event.getDate())
				hours += events[i].getDuration();

		hours += event.getDuration();

		if (hours <= 8.)
		{
			if (current < capacity)
			{
				cout << "> Event added to calendar." << endl;
				events[current] = event;
				current++;
			}
			else
				cout << "> No room for more events in calendar (capacity: " << capacity << ")." << endl;
		}
		else
			cout << "> No time for more events at this date." << endl;
	}

	void changeDate(const char* descriptionCon, Date newDate)
	{
		for (int i = 0; i < current; i++)
			if (events[i].sameDescription(descriptionCon))
				events[i].changeDate(newDate);
	}

	void changeDuration(const char* descriptionCon, double durationVal)
	{
		for (int i = 0; i < current; i++)
			if (events[i].sameDescription(descriptionCon))
				events[i].changeDuration(durationVal);
	}

	void sortByDate()
	{
		for (int i = 0; i < current - 1; i++)
			for (int j = 0; j < current - i - 1; j++)
				if (events[j].getDate() > events[j + 1].getDate())
					swap(&events[j], &events[j + 1]);
	}

	void print()
	{
		cout << "\n>> Calendar:" << endl;
		for (int i = 0; i < current; i++)
			events[i].print();
	}
};