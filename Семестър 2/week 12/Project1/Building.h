#pragma once
#include"Room.h"

class Building
{
public:
	Building(size_t capacityParam = 2)
		: rooms(new Room* [capacityParam]), capacity(capacityParam), size(0)
	{
		for (size_t i = 0; i < capacity; i++)
			rooms[i] = nullptr;
	}

	Building(const Building& source)
	{
		capacity = source.capacity;
		size = source.size;

		rooms = new Room * [capacity];
		for (size_t i = 0; i < capacity; i++)
			rooms[i] = nullptr;

		for (size_t i = 0; i < size; i++)
			rooms[i] = source.rooms[i]->clone();
	}

	Building& operator = (const Building& source)
	{
		if (this != &source)
		{
			for (size_t i = 0; i < capacity; i++)
				delete rooms[i];
			delete[] rooms;

			rooms = nullptr;

			capacity = source.capacity;
			size = source.size;

			rooms = new Room * [capacity];
			for (size_t i = 0; i < capacity; i++)
				rooms[i] = nullptr;

			for (size_t i = 0; i < size; i++)
				rooms[i] = source.rooms[i]->clone();
		}
		return *this;
	}

	~Building()
	{
		delete[] rooms;
	}

	void print() const
	{
		for (size_t i = 0; i < size; i++)
			rooms[i]->print();
	}

	void print(std::ostream& os) const
	{
		for (size_t i = 0; i < size; i++)
			rooms[i]->print(os);
	}

	void addRoom(Room* source)
	{
		if (size == capacity)
			resize();

		rooms[size++] = source->clone();
	}

	void addRoom(ConferenceRoom* source)
	{
		if (size == capacity)
			resize();

		rooms[size++] = source->clone();
	}

	void setIsFree(size_t index, bool isFreeParam)
	{
		rooms[index]->setIsFree(isFreeParam);
	}

	void sort()
	{
		for (size_t i = 0; i < size - 1; i++)
			for (size_t j = 0; j < size - i - 1; j++)
				if (rooms[j]->getCapacity() < rooms[j + 1]->getCapacity())
				{
					Room* temp = rooms[j];
					rooms[j] = rooms[j + 1];
					rooms[j + 1] = temp;
				}
	}

private:
	Room** rooms;
	size_t capacity;
	size_t size;

	void resize()
	{
		Room** newRooms = new Room * [capacity *= 2];

		for (size_t i = 0; i < size; i++)
			newRooms[i] = rooms[i];

		for (size_t i = size; i < capacity; i++)
			newRooms[i] = nullptr;

		delete[] rooms;
		rooms = newRooms;
	}
};