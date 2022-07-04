#pragma once

class Cube
{
private:
	Point start;
	double sideLength;

public:
	Cube(double x, double y, double z, double sideLength)
	{
		this->start.setX(x);
		this->start.setY(y);
		this->start.setZ(z);
		this->sideLength = sideLength;
	}

	Point getPoint()
	{
		return start;
	}

	double volume() const
	{
		return sideLength * sideLength * sideLength;
	}
	
	void peakPoints()
	{
		cout << "> All points of cube:" << endl;

		double x = start.getX();
		double y = start.getY();
		double z = start.getZ();

		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
		cout << "(" << x + sideLength << ", " << y << ", " << z << ")" << endl;
		cout << "(" << x << ", " << y - sideLength << ", " << z << ")" << endl;
		cout << "(" << x + sideLength << ", " << y - sideLength << ", " << z << ")" << endl;
		cout << "(" << x << ", " << y << ", " << z + sideLength << ")" << endl;
		cout << "(" << x + sideLength << ", " << y << ", " << z + sideLength << ")" << endl;
		cout << "(" << x << ", " << y - sideLength << ", " << z + sideLength << ")" << endl;
		cout << "(" << x + sideLength << ", " << y - sideLength << ", " << z + sideLength << ")" << endl;
	}
	
	void print() const
	{
		cout << "> Cube: " << endl;

		start.print();
		cout << "Side length: " << sideLength << endl;
	}
};