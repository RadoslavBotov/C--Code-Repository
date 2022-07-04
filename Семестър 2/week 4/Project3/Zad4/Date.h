#pragma once

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