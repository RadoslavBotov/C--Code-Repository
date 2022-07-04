#pragma once
#include<iostream>
#include<cstring>

class Room
{
public:
	Room(const char* nameParam, bool isFreeParam, unsigned capacityParam)
		: isFree(isFreeParam), capacity(capacityParam)
	{
		copy(roomName, nameParam);
	}

	Room(const Room& source)
	{
		roomName = new char[strlen(source.roomName) + 1];
		strcpy_s(roomName, strlen(source.roomName) + 1, source.roomName);

		isFree = source.isFree;
		capacity = source.capacity;
	}

	Room& operator = (const Room& source)
	{
		if (this != &source)
		{
			delete[] roomName;

			roomName = new char[strlen(source.roomName) + 1];
			strcpy_s(roomName, strlen(source.roomName) + 1, source.roomName);

			isFree = source.isFree;
			capacity = source.capacity;
		}
		return *this;
	}

	virtual ~Room()
	{
		delete[] roomName;
	}

	virtual Room* clone() = 0;

	virtual void print() const
	{
		std::cout << roomName << " " << isFree << " " << capacity << " ";
	}

	virtual void print(std::ostream& os) const
	{
		os << roomName << " " << isFree << " " << capacity;
	}

	unsigned getCapacity() const
	{
		return capacity;
	}

	void setIsFree(bool isFreeParam)
	{
		isFree = isFreeParam;
	}

private:
	char* roomName;
	bool isFree;
	unsigned capacity;

	void copy(char*& destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
};