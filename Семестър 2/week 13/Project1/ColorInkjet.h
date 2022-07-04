#pragma once
#include<iostream>
#include"BwLaser.h"
#include"ColorLaser.h"
//#include"HelperString.h"

class ColorInkjet : public BwLaser, public ColorLaser
{
public:
	ColorInkjet(HelperString modelParam, unsigned numberOfColorsParam, bool hasWarantyParam, 
			    unsigned pagesAMinuteParam, double priceParam, Brand typeParam = COLOR_INKJET)
		: Printer(modelParam, pagesAMinuteParam, priceParam, typeParam),
		  BwLaser(modelParam, hasWarantyParam, pagesAMinuteParam, priceParam, typeParam),
		  ColorLaser(modelParam, numberOfColorsParam, pagesAMinuteParam, priceParam, typeParam)
	{ }

	virtual void print() const override
	{
		Printer::print();
		std::cout << " " << BwLaser::getHasWaranty() << " " << ColorLaser::getNumberOfColors() << std::endl;
	}

	virtual Printer* clone() const override
	{
		return new ColorInkjet(*this);
	}

private:

};