#pragma once
#include"Point.h"
#include<iostream>
using namespace std;

class Circle
{
private:
	Point start;
	double rad;
	const double PI = 3.1415926535;

public:
	Circle(double x, double y, double rad)
	{
		this->start.setX(x);
		this->start.setY(y);
		this->rad = rad;
	}

	double area() const
	{
		return PI * rad * rad;
	}

	void print() const
	{
		cout << "> Circle: " << endl;

		start.print();
		cout << "> Radius: "<< rad << endl;
	}
};