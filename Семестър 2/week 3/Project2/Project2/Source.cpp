#include<iostream>
#include<cstring>
using namespace std;

enum Position
{
	INVALID = -1,

	ASSISTENT, 
	HEAD_ASSISTENT, 
	ASSOCIATE_PROFESSOR, 
	PROFESSOR
};

const char* titles[4] = { "ASSISTENT","HEAD ASSISTENT","ASSOCIATE PROFESSOR", "PROFESSOR" };

class Scientist
{
private:
	char* Name;
	Position Title;
	unsigned Salary;
	unsigned DailyMoneyEarned;

public:
	Scientist() : Name{ nullptr }, Title(INVALID), Salary{ 0 }, DailyMoneyEarned{ 0 }
	{ }
	/*
	Scientist(const char* name, Position title, unsigned salary, unsigned dailyMoneyEarned)
	{
		
	}
	*/
	~Scientist()
	{
		delete[] Name;
	}

	char* getName()
	{
		return Name;
	}

	Position getTitle()
	{
		return Title;
	}

	unsigned getSalary()
	{
		return Salary;
	}

	unsigned getDailyMoneyEarned()
	{
		return DailyMoneyEarned;
	}

	char* setName(const char* name)
	{
		strcpy_s(Name, strlen(name), name);
	}

	Position setTitle(Position title)
	{
		Title = title;
	}

	unsigned setSalary(unsigned salary)
	{
		Salary = salary;
	}

	unsigned setDailyMoneyEarned(unsigned dailyMoneyEarned)
	{
		DailyMoneyEarned = dailyMoneyEarned;
	}

	void raisePosition()
	{
		if (Title <= PROFESSOR)
		{
			Title = (Position)(Title + 1);
			Salary += 100;
		}
	}

	void print()
	{
		cout << "" << endl;
	}
};

class University
{
private:
	Scientist** scientists;
	int size;
	int capacity;

	void shift(int pos)
	{
		size--;
		for (int i = pos; i < size; ++i)
			scientists[i] = scientists[i + 1];
	}

public:
	University(int capacity)
	{
		scientists = new Scientist * [capacity];
		size = 0;
		this->capacity = capacity;
	}

	~University()
	{
		delete[] scientists;
	}

	void hire(const char* name, Position title, int salary, int dailyMoneyEarned)
	{
		if (size < capacity)
		{
			scientists[size] = new Scientist();
			//scientists[size] = new Scientist(name, title, salary, dailyMoneyEarned);
			size++;
		}
	}

	void fire(const char* name)
	{
		for (int i = 0; i < size; i++)
			if (strcmp(scientists[i]->getName(), name) == 0)
			{
				delete scientists[i];
				shift(i);
			}
	}

	void giveRaise(const char* name)
	{
		for (int i = 0; i < size; i++)
			if (strcmp(scientists[i]->getName(), name) == 0)
				scientists[i]->raisePosition();
	}

	void fireAll(Position title)
	{
		for (int i = 0; i < size; i++)
			if (scientists[i]->getTitle() == title)
			{
				delete scientists[i];
				shift(i);
			}
	}

	int getProfit()
	{
		int profit = 0;

		for (int i = 0; i < size; i++)
			profit += scientists[i]->getDailyMoneyEarned() * 30 - scientists[i]->getSalary();

		return profit;
	}

	void print()
	{
		cout << "Profit: " << getProfit() << endl;

		for (int i = 0; i < size; i++)
			scientists[i]->print();
	}
};

int main()
{


	return 0;
}