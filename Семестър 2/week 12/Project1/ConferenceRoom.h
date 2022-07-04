#pragma once
#include"Room.h"
#include<cstring>

class ConferenceRoom : public Room
{
public:
	ConferenceRoom(const char* nameParam, bool isFreeParam, bool hasProjectorParam, unsigned capacityParam) 
		: Room(nameParam, isFreeParam, capacityParam), hasProjector(hasProjectorParam)
	{}

	ConferenceRoom(const ConferenceRoom& source)
		: Room(source), hasProjector(source.hasProjector)
	{}

	ConferenceRoom& operator = (const ConferenceRoom& source)
	{
		if (this != &source)
		{
			Room::operator = (source);

			hasProjector = source.hasProjector;
		}
		return *this;
	}

	virtual Room* clone() override
	{
		return new ConferenceRoom(*this);
	}

	void print() const override
	{
		Room::print();
		std::cout << hasProjector << std::endl;
	}

	void print(std::ostream& os) const override
	{
		Room::print(os);
		os << " " << hasProjector << std::endl;
	}

private:
	bool hasProjector;
};