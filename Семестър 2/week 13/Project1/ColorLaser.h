#pragma once
#include"Printer.h"

class ColorLaser : virtual public Printer
{
public:
	ColorLaser(HelperString modelParam, unsigned numberOfColorsParam, unsigned pagesAMinuteParam, double priceParam, Brand typeParam = COLOR_LASER)
		: Printer(modelParam, pagesAMinuteParam, priceParam, typeParam)
	{
		numberOfColors = numberOfColorsParam;
	}

	unsigned getNumberOfColors() const
	{
		return numberOfColors;
	}

	virtual void print() const override
	{
		Printer::print();
		std::cout << " " << numberOfColors << std::endl;
	}

	virtual Printer* clone() const override
	{
		return new ColorLaser(*this);
	}

private:
	unsigned numberOfColors;
};