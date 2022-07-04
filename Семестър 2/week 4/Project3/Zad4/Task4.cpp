#include<iostream>
using namespace std;

class Date
{
private:
	unsigned short day;
	unsigned short month;
	unsigned short year;

public:
	Date() : day{ 0 }, month{ 0 }, year{ 0 } {}

	Date(unsigned short dayVal, unsigned short monthVal, unsigned short yearVal) : day{ 0 }, month{ 0 }, year{ 0 }
	{
		day = dayVal;
		month = monthVal;
		year = yearVal;
	}

	bool operator == (const Date obj)
	{
		return (day == obj.day) && (month == obj.month) && (year == obj.year);
	}

	bool operator > (const Date obj)
	{
		return (day > obj.day) || (month > obj.month) || (year > obj.year);
	}

	void prettyPrint() const
	{
		if (day < 10)
			cout << '0' << day << " ";
		else cout << day << " ";

		if (month < 10)
			cout << '0' << month << " ";
		else cout << month << " ";

		if (year < 1000)
		{
			unsigned short br = 0;
			if (year < 10) br++;
			if (year < 100) br++;
			if (year < 1000) br++;

			for (int i = 0; i < br; i++)
				cout << '0';
		}
		cout << year << endl;
	}

	void changeDay(const unsigned short dayVal)
	{
		day = dayVal;
	}

	void chageMonth(const unsigned short monthVal)
	{
		month = monthVal;
	}

	void changeYear(const unsigned short yearVal)
	{
		year = yearVal;
	}

	void changeDate(const unsigned short dayVal, const unsigned short monthVal, const unsigned short yearVal)
	{
		day = dayVal;
		month = monthVal;
		year = yearVal;
	}
};

class Event
{
private:
	Date date;
	double duration;   // <= 6 hours
	char* description; // <= 256 symbols

public:
	Event() : date(Date()), duration(0), description(new char[1])
	{
		description[0] = '\0';
	}

	Event(Date dateObj, double durationVal, const char* descriptionVal)
	{
		date = dateObj; // Date has no dynamic memory.

		duration <= 6. ? duration = durationVal : duration = 0;

		unsigned length = strlen(descriptionVal);

		if (length < 256)
		{
			description = new char[length + 1];
			strcpy_s(description, length + 1, descriptionVal);
		}
		else
		{
			cout << "> Description too long." << endl;
			description = new char[1];
			description[0] = '\0';
		}
	}

	Event(const Event& obj)
	{
		date = obj.date;
		duration = obj.duration;

		description = new char[strlen(obj.description) + 1];
		strcpy_s(description, strlen(obj.description) + 1, obj.description);
	}

	Event& operator = (const Event& obj)
	{
		if (this == &obj) return *this;

		date = obj.date;
		duration = obj.duration;

		delete[] description;
		description = new char[strlen(obj.description) + 1];
		strcpy_s(description, strlen(obj.description) + 1, obj.description);

		return *this;
	}

	~Event()
	{
		delete[] description;
	}

	Date getDate()
	{
		return date;
	}

	double getDuration()
	{
		return duration;
	}

	void print() const
	{
		cout << "> Event:" << endl;
		cout << "Date: ";
		date.prettyPrint();
		cout << "Duration: " << duration << " hour(s)" << endl;
		cout << "Description: " << description << endl << endl;
	}

	void changeDate(Date dateV)
	{
		date = dateV;
	}

	void changeDuration(double durationVal)
	{
		duration = durationVal;
	}

	bool sameDescription(const char* descriptionCon)
	{
		return strcmp(description, descriptionCon) == 0;
	}
};

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

int main()
{
	Date date1, date2(22, 3, 2022), date3(21, 3, 2022), date4(20, 3, 2022);

	Event event1(date1, 1, "Placeholder description 1");
	Event event2(date2, 2, "Placeholder description 2");
	Event event3(date3, 3, "Placeholder description 3");
	Event event4(date4, 4, "Placeholder description 4");
	Event event5(date4, 2, "Placeholder description 5");

	Calendar calendar(4);

	calendar.addEvent(event1);
	calendar.addEvent(event2);
	calendar.addEvent(event3);
	calendar.addEvent(event4);
	calendar.addEvent(event5);

	calendar.print();

	calendar.sortByDate();

	calendar.print();

	return 0;
}