#pragma once
#include"Room.h"
#include<cstring>

class RestRoom : public Room
{
public:
	RestRoom(const char* nameParam, bool isFreeParam, unsigned capacityParam, bool hasProjectorParam, const char* teamNameParam)
		: Room(nameParam, isFreeParam, capacityParam), hasProjector(hasProjectorParam)
	{
		copy(teamName, teamNameParam);
	}

	RestRoom(const RestRoom& source)
		: Room(source), hasProjector(source.hasProjector)
	{
		copy(teamName, source.teamName);
	}

	RestRoom& operator = (const RestRoom& source)
	{
		if (this != &source)
		{
			Room::operator = (source);

			delete[] teamName;

			hasProjector = source.hasProjector;
			copy(teamName, source.teamName);
		}
		return *this;
	}

	~RestRoom()
	{
		delete[] teamName;
	}

	virtual Room* clone() override
	{
		return new RestRoom(*this);
	}

	void print() const override
	{
		Room::print();
		std::cout << hasProjector << " " << teamName << std::endl;
	}

	void print(std::ostream& os) const override
	{
		Room::print(os);
		os << " " << hasProjector << " " << teamName << std::endl;
	}

private:
	bool hasProjector;
	char* teamName;

	void copy(char*& destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
};