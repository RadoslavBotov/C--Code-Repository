#include<iostream>
using namespace std;

class Vehicle
{
public:
	Vehicle(const char* registrationNumberParam, int yearOfProductionParam, const char* brandAndModelParam, const char* nameOfOwnerParam)
	{
		//if (strlen(registrationNumberParam) > 15)
		//	throw exception("Registration number has more than 15 symbols");

		allocateMemory(registrationNumber, registrationNumberParam);
		yearOfProduction = yearOfProductionParam;
		allocateMemory(brandAndModel, brandAndModelParam);
		allocateMemory(nameOfOwner, nameOfOwnerParam);
	}

	Vehicle(const Vehicle& source)
	{
		allocateMemory(registrationNumber, source.registrationNumber);
		yearOfProduction = source.yearOfProduction;
		allocateMemory(brandAndModel, source.brandAndModel);
		allocateMemory(nameOfOwner, source.nameOfOwner);
	}

	Vehicle& operator = (const Vehicle& source)
	{
		if (this == &source) return *this;

		deleteMemory();

		allocateMemory(registrationNumber, source.registrationNumber);
		yearOfProduction = source.yearOfProduction;
		allocateMemory(brandAndModel, source.brandAndModel);
		allocateMemory(nameOfOwner, source.nameOfOwner);

		return *this;
	}
	
	bool operator > (const Vehicle& source)
	{
		return (yearOfProduction > source.yearOfProduction);
	}

	~Vehicle()
	{
		deleteMemory();
	}

	char* getRegistrationNumber() const
	{
		return registrationNumber;
	}

	int getYearOfProduction() const
	{
		return yearOfProduction;
	}

	char* getBrandAndModel() const
	{
		return brandAndModel;
	}

	char* getNameOfOwner() const
	{
		return nameOfOwner;
	}

private:
	char* registrationNumber;
	int yearOfProduction;
	char* brandAndModel;
	char* nameOfOwner;

	void allocateMemory(char*& target, const char* source)
	{
		unsigned int size = strlen(source) + 1;

		target = new char[size];
		strcpy_s(target, size, source);
	}

	void deleteMemory()
	{
		delete[] registrationNumber;
		delete[] brandAndModel;
		delete[] nameOfOwner;
	}
};

int main()
{
	Vehicle v1("1234512345123456", 1998, "Honda", "Pesho");
	Vehicle v2("456", 2002, "Reno", "Ivan");

	cout << v1.getRegistrationNumber() << " " << v1.getYearOfProduction() << " " << v1.getBrandAndModel() << " " << v1.getNameOfOwner() << endl;
	cout << v2.getRegistrationNumber() << " " << v2.getYearOfProduction() << " " << v2.getBrandAndModel() << " " << v2.getNameOfOwner() << endl;

	cout << (v1 > v2) << endl;
	cout << (v2 > v1) << endl;

	return 0;
}