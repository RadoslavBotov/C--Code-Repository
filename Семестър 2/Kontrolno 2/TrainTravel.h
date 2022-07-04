#pragma once
#include<cstring>
#include<iostream>

class TrainTravel
{
public:
	TrainTravel(const char* trainLineParam, double prieParam)
	{
		copy(trainLine, trainLineParam);
		price = prieParam;
	}

	TrainTravel(const TrainTravel& source)
	{
		copy(trainLine, source.trainLine);
		price = source.price;
	}

	TrainTravel& operator = (const TrainTravel& source)
	{
		if (this != &source)
		{
			delete[] trainLine;

			copy(trainLine, source.trainLine);
			price = source.price;
		}
		return *this;
	}

	virtual ~TrainTravel()
	{
		delete[] trainLine;
	}

	virtual double getPrice() const
	{
		return price;
	}

	virtual void print() const
	{
		std::cout << trainLine << " " << price << std::endl;
	}

private:
	char* trainLine;
	double price;

	void copy(char*& destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
};