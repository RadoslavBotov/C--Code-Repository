#pragma once

class Sphere
{
private:
	Point start;
	double rad;
	const double PI = 3.1415926535;

public:
	Sphere(double x, double y, double z, double rad)
	{
		this->start.setX(x);
		this->start.setY(y);
		this->start.setZ(z);
		this->rad = rad;
	}

	Point getPoint()
	{
		return start;
	}

	double volume() const
	{
		return 4 / 3 * PI * rad * rad * rad;
	}

	void print() const
	{
		cout << "> Sphere: " << endl;

		start.print();
		cout << "> Radius: " << rad << endl;
	}
};