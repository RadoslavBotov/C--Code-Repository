#pragma once
#include"Room.h"
#include<cstring>

class OfficeRoom : public Room
{
public:
	OfficeRoom(const char* officeNameParam, bool isFreeParam, const char* ownerNameParam)
		: Room(officeNameParam, isFreeParam, 1)
	{
		copy(ownerName, ownerNameParam);
	}

	OfficeRoom(const OfficeRoom& source)
		: Room(source)
	{
		copy(ownerName, source.ownerName);
	}

	OfficeRoom& operator = (const OfficeRoom& source)
	{
		if (this != &source)
		{
			Room::operator = (source);

			delete[] ownerName;

			copy(ownerName, source.ownerName);
		}
		return *this;
	}

	~OfficeRoom()
	{
		delete[] ownerName;
	}

	virtual Room* clone() override
	{
		return new OfficeRoom(*this);
	}

	void print() const override
	{
		Room::print();
		std::cout << ownerName << std::endl;
	}

	void print(std::ostream& os) const override
	{
		Room::print(os);
		os << " " << ownerName << std::endl;
	}

private:
	char* ownerName;

	void copy(char*& destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
};