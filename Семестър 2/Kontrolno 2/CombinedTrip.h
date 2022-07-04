#pragma once
#include"TrainTravel.h"
#include"CarTravel.h"
#include<iostream>
 
class CombinedTrip : public TrainTravel, public CarTravel
{
public:
	CombinedTrip(const char* trainLineParam, double priceParam1,
		const unsigned regNumbParam[5], double distanceParam, double priceParam2,
		const char** destinationsParam, size_t sizeParam, double cashParam)
		: TrainTravel(trainLineParam, priceParam1), CarTravel(regNumbParam, distanceParam, priceParam2)
	{
		size = sizeParam;
		cash = cashParam;

		destinations = new char* [size];
		for (size_t i = 0; i < size; i++)
			copy(destinations[i], destinationsParam[i]);
	}

	CombinedTrip(const CombinedTrip& source)
		: TrainTravel(source), CarTravel(source)
	{
		size = source.size;
		cash = source.cash;

		destinations = new char* [size];
		for (size_t i = 0; i < size; i++)
			copy(destinations[i], source.destinations[i]);
	}

	CombinedTrip& operator = (const CombinedTrip& source)
	{
		if (this != &source)
		{
			freeMemory();

			TrainTravel::operator=(source);
			CarTravel::operator=(source);

			size = source.size;
			cash = source.cash;

			destinations = new char* [size];
			for (size_t i = 0; i < size; i++)
				copy(destinations[i], source.destinations[i]);
		}
		return *this;
	}

	~CombinedTrip()
	{
		freeMemory();
	}

	double getPrice() const
	{
		return (TrainTravel::getPrice() + CarTravel::getPrice() + cash * (size - 1));
	}

	virtual void print() const override
	{
		TrainTravel::print();
		CarTravel::print();

		for (size_t i = 0; i < size; i++)
			std::cout << *destinations << std::endl;
		std::cout << size << " " << cash << std::endl;
	}

private:
	char** destinations;
	size_t size;
	double cash;

	void copy(char*& destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}

	void freeMemory()
	{
		for (size_t i = 0; i < size; i++)
			delete[] destinations[i];
		delete[] destinations;

		size = 0;
		cash = 0;
	}
};