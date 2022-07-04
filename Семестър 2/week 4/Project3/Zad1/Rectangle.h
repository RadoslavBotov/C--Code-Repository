#pragma once
#include"Point.h"
#include<iostream>
using namespace std;

class Rectangle
{
private:
	Point start;
	double height;
	double length;

public:
	Rectangle(double x, double y, double heigth, double length)
	{
		this->start.setX(x);
		this->start.setY(y);
		this->height = heigth;
		this->length = length;
	}

	double area() const
	{
		return height * length;
	}

	void peakPoints()
	{
		cout << "> All points of rectangle:" << endl;

		cout << start.getX() << " " << start.getY() << endl;
		cout << start.getX() + length << " " << start.getY() << endl;
		cout << start.getX() << " " << start.getY() - height << endl;
		cout << start.getX() + length << " " << start.getY() - height << endl;
	}

	void print() const
	{
		cout << "> Rectangle: " << endl;

		start.print();
		cout << "> Heigth: " << height << endl;
		cout << "> Length: " << length << endl;
	}
};