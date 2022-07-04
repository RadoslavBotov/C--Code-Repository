#pragma once

enum Company
{
	BOROVEC,
	TROQ,
	MORENI
};

class Waffle
{
private:
	Company logo;
	unsigned grams;
	unsigned wholesalePrice;
	unsigned customerPrice;

public:
	Waffle() : logo{ BOROVEC }, grams{ 100 }, wholesalePrice{ 10 }, customerPrice{ 20 }
	{ }

	Waffle(Company logo, unsigned grams, unsigned wholesalePrice, unsigned customerPrice)
	{
		this->logo = logo;
		this->grams = grams;
		this->wholesalePrice = wholesalePrice;
		this->customerPrice = customerPrice;
	}

	Company getCompanyLogo()
	{
		return logo;
	}

	unsigned getGrams()
	{
		return grams;
	}

	unsigned getWholesalePrice()
	{
		return wholesalePrice;
	}

	unsigned getCustomerPrice()
	{
		return customerPrice;
	}

};