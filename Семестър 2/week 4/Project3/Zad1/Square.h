#pragma once
#include"Point.h"
#include<iostream>
using namespace std;

class Square
{
private:
	Point start;
	double sideLength;
public:
	Square(double x, double y, double sideLength)
	{
		this->start.setX(x);
		this->start.setY(y);
		this->sideLength = sideLength;
	}

	double area() const
	{
		return sideLength * sideLength;
	}

	void peakPoints()
	{
		cout << "> All points of square:" << endl;

		cout << start.getX() << " " << start.getY() << endl;
		cout << start.getX() + sideLength << " " << start.getY() << endl;
		cout << start.getX() << " " << start.getY() - sideLength << endl;
		cout << start.getX() + sideLength << " " << start.getY() - sideLength << endl;
	}

	void print() const
	{
		cout << "> Square: " << endl;

		start.print();
		cout << "> Side length: " << sideLength << endl;
	}
};