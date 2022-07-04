#pragma once
#include<iostream>
#include"Printer.h"

class BwLaser : virtual public Printer
{
public:
	BwLaser(HelperString modelParam, bool hasWarantyParam, unsigned pagesAMinuteParam, double priceParam, Brand typeParam = BW_LASER)
		: Printer(modelParam, pagesAMinuteParam, priceParam, typeParam)
	{
		hasWaranty = hasWarantyParam;
	}

	bool getHasWaranty() const
	{
		return hasWaranty;

	}

	virtual void print() const override
	{
		Printer::print();
		std::cout << " " << hasWaranty << std::endl;
	}

	virtual Printer* clone() const override
	{
		return new BwLaser(*this);
	}

private:
	bool hasWaranty;
};