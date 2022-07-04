#include<iostream>
using namespace std;

class Dog
{
private:
	char* name;
	char* gender;
	unsigned short age;

public:
	Dog() : name(new char[1]), gender(new char[1]), age(0)
	{
		strcpy_s(this->name, 1, "\0");
		strcpy_s(this->gender, 1, "\0");
	}

	Dog(const char* name) : name(new char[strlen(name) + 1]), gender(new char[1]), age(0)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->gender, 1, "\0");
	}

	Dog(const char* name, const char* gender, unsigned short age) : name(new char[strlen(name) + 1]), gender(new char[strlen(gender) + 1]), age(age)
	{
		strcpy_s(this->name, strlen(name) + 1, name);
		strcpy_s(this->gender, strlen(gender) + 1, gender);
	}

	~Dog()
	{
		delete[] name;
		delete[] gender;
	}

	char* getGender()
	{
		return gender;
	}

	bool getAge()
	{
		return age;
	}

	void grow()
	{
		if (this->age < 720)
		{
			cout << "> " << name << " grew by one month." << endl;
			this->age++;
		}
		else 
			cout << "> Dog is 720 months old." << endl;
	}

	void print()
	{
		cout << "> " << name << ":" << endl;
		cout << "Gender: " << gender << endl;
		cout << "Age: " << age << " month(s)" << endl;
	}
};

class Shelter
{
private:
	Dog** dogs;
	unsigned short maxSize;
	unsigned short curSize;

	void shift(int pos)
	{
		curSize--;
		for (int i = pos; i < curSize; ++i)
			dogs[i] = dogs[i + 1];
	}

public:
	Shelter(unsigned short maxSize) : maxSize(15)
	{
		dogs = new Dog * [maxSize];
		curSize = 0;
		this->maxSize = maxSize;
	}

	~Shelter()
	{
		for (int i = 0; i < curSize; i++)
			delete dogs[i];
		delete[] dogs;
	}

	void addDog(const char* name, const char* gender, int age)
	{
		if (curSize < maxSize)
		{
			dogs[curSize] = new Dog(name, gender, age);
			curSize++;
		}
		else
			cout << "> No place in shelter." << endl;
	}

	void letDogGo(unsigned short index)
	{
		if (index < curSize)
		{
			cout << "> Shelter is letting go of dog with index " << index << "." << endl;
			delete dogs[index];
			shift(index);
		}
		else
			cout << "> No dog in shelter with index " << index << "." << endl;
	}

	void listDogs()
	{
		if (curSize == 0)
			cout << "> Shelter is empty." << endl;
		else
		{
			cout << "> Shelter has " << curSize << " dog(s)." << endl;
			for (int i = 0; i < curSize; i++)
				dogs[i]->print();
		}
	}
};

int main()
{
	Dog dog1("Rex", "male", 1);
	Dog dog2("Bean", "female", 2);
	Dog dog3("Alvin");

	Shelter shelter1(15);


	shelter1.listDogs();
	
	cout << endl;

	shelter1.addDog("Rex", "male", 1);
	shelter1.addDog("Bean", "female", 2);
	shelter1.listDogs();

	cout << endl;

	shelter1.letDogGo(0);
	shelter1.listDogs();

	cout << endl;

	shelter1.letDogGo(3);
	shelter1.listDogs();

	return 0;
}