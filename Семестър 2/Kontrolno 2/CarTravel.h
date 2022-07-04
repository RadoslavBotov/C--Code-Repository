#pragma once
#include<iostream>

class CarTravel
{
public:
	CarTravel(const unsigned regNumbParam[5], double distanceParam, double priceParam)
	{
		for (size_t i = 0; i < 5; i++)
			regNumb[i] = regNumbParam[i];

		distance = distanceParam;
		price = priceParam;
	}

	CarTravel(const CarTravel& source)
	{
		for (size_t i = 0; i < 5; i++)
			regNumb[i] = source.regNumb[i];

		distance = source.distance;
		price = source.price;
	}

	CarTravel& operator = (const CarTravel& source)
	{
		if (this != &source)
		{
			for (size_t i = 0; i < 5; i++)
				regNumb[i] = source.regNumb[i];

			distance = source.distance;
			price = source.price;
		}
		return *this;
	}

	virtual ~CarTravel() = default;

	virtual double getPrice() const
	{
		return price;
	}

	virtual void print() const
	{
		for (size_t i = 0; i < 5; i++)
			std::cout << regNumb[i] << " ";
		std::cout << distance << ", " << price << std::endl;
	}

private:
	unsigned regNumb[5];
	double distance;
	double price;
};