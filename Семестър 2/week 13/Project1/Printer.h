#pragma once
#include<iostream>
#include"HelperString.h"

enum Brand
{
	BW_LASER = 0,
	COLOR_LASER,
	COLOR_INKJET
};

class Printer
{
public:
	Printer(HelperString modelParam, unsigned pagesAMinuteParam, double priceParam, Brand typeParam)
	{
		type = typeParam;
		model = modelParam;
		pagesAMinute = pagesAMinuteParam;
		price = priceParam;
	}

	virtual ~Printer() = default;

	virtual void print() const
	{
		std::cout << type << " " << model << " " << pagesAMinute << " " << price;
	}

	virtual Printer* clone() const = 0;

	friend bool operator > (const Printer& lhs, const Printer& rhs)
	{
		return (lhs.type > rhs.type);
	}

private:
	Brand type;
	HelperString model;
	unsigned pagesAMinute;
	double price;
};