#pragma once
#include"Waffle.h"

class Store
{
private:
	Waffle** waffles;
	int size;
	int capacity;
	int income;
	int expences;

	void shift(int pos)
	{
		size--;
		for (int i = pos; i < size; ++i)
			waffles[i] = waffles[i + 1];
	}

public:
	Store()
	{

	}

	~Store()
	{
		for (int i = 0; i < size; ++i)
			delete waffles[i];
		delete[] waffles;
	}

	void sellWaffle(Company logo)
	{
		for (int i = 0; i < size; i++)
			if (waffles[i]->getCompanyLogo() == logo)
			{
				income += waffles[i]->getCustomerPrice();
				delete waffles[i];
				shift(i);
				break;
			}
	}

	void buyWaffles(Company logo, int amount)
	{

	}

	void getProfit()
	{
		std::cout << "Profit: " << income - expences << std::endl;
	}
};

/*
Продава се вафла.
Поръчват се вафли от склада на дадена марка.
Показва колко вафли има от дадена марка или даден грамаж
Показва печалбата до момента.
*/