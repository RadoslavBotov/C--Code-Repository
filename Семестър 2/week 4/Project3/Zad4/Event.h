#pragma once

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