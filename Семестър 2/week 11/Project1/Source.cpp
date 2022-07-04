#include<iostream>
using namespace std;

class Ticket
{
public:
	Ticket()
	{
		copy(name, "\0");
		price = 20;
	}

	Ticket(const char* nameParam, double priceParam)
	{
		copy(name, nameParam);
		if (priceParam < 0)
		{
			cout << "!Price is negative!" << endl;
			price = 0;
		}
		else
			price = priceParam;
	}
	
	Ticket(const Ticket& source)
	{
		copy(name, source.name);
		price = source.price;
	}

	Ticket& operator = (const Ticket& source)
	{
		if (this != &source)
		{
			deleteMemory();

			copy(name, source.name);
			price = source.price;
		}
		return *this;
	}

	~Ticket()
	{
		deleteMemory();
	}

	void virtual print() const
	{
		cout << "> Ticket:" << endl;
		cout << "Name: " << name << endl;
		cout << "Price: " << price << endl;
	}

	double virtual getPrice() const
	{
		return price;
	}

	unsigned int virtual getNumberOfPeople() const
	{
		return 0;
	}

private:
	char* name;
	double price;

	void deleteMemory()
	{
		delete[] name;
	}

protected:
	void copy(char*& destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
};

class Ticket_Preferential : public Ticket
{
public:
	Ticket_Preferential(const char* nameOfPersonParam, const char* nameParam, double priceParam) 
	: Ticket(nameParam, priceParam * 0.5)
	{
		Ticket::copy(nameOfPerson, nameOfPersonParam);
	}

	Ticket_Preferential(const Ticket_Preferential& source)
		: Ticket(source)
	{
		Ticket::copy(nameOfPerson, source.nameOfPerson);
	}

	Ticket_Preferential& operator = (const Ticket_Preferential& source)
	{
		if (this != &source)
		{
			deleteMemory();

			Ticket::operator = (source);
			Ticket::copy(nameOfPerson, source.nameOfPerson);
		}
		return *this;
	}

	~Ticket_Preferential()
	{
		deleteMemory();
	}

	void print() const override
	{
		Ticket::print();
		cout << "Person: " << nameOfPerson << endl;
	}

	double getPrice() const override
	{
		return Ticket::getPrice();
	}

private:
	char* nameOfPerson;

	void deleteMemory()
	{
		delete[] nameOfPerson;
	}
};

class Ticket_Group : public Ticket
{
public:
	Ticket_Group(unsigned int numberOfPeopleParam, const char* nameParam, double priceParam)
		: Ticket(nameParam, priceParam - (2 * (double)numberOfPeopleParam))
	{
		numberOfPeople = numberOfPeopleParam;
	}

	Ticket_Group(const Ticket_Group& source)
		: Ticket(source)
	{
		numberOfPeople = source.numberOfPeople;
	}

	Ticket_Group& operator = (const Ticket_Group& source)
	{
		if (this != &source)
		{
			Ticket::operator = (source);
			numberOfPeople = source.numberOfPeople;
		}
		return *this;
	}

	void print() const override
	{
		Ticket::print();
		cout << "Number of people:: " << numberOfPeople << endl;
	}

	double getPrice() const override
	{
		return Ticket::getPrice();
	}

	unsigned int getNumberOfPeople() const override
	{
		return numberOfPeople;
	}

private:
	unsigned int numberOfPeople;
};



int main()
{
	Ticket t1("Ticket 1", 100);
	Ticket_Preferential t2("Radoslav", "Ticket 2", 60);
	Ticket_Group t3(20, "Ticket 3", 50);

	Ticket** arr = new Ticket*[3];

	arr[0] = &t1;
	arr[1] = &t2;
	arr[2] = &t3;

	double sum = 0;
	int watchers = 0;

	for (size_t i = 0; i < 3; i++)
	{
		if (typeid(*arr[i]) == typeid(Ticket_Group))
		{
			watchers += arr[i]->getNumberOfPeople();
		}
		else
			watchers++;
		sum += arr[i]->getPrice();
	}

	cout << watchers << " " << sum << endl;

	delete[] arr;

	return 0;
}