#pragma once

class Cubeoid
{
private:
	Point start;
	double height;
	double length;
	double width;

public:
	Cubeoid(double x, double y, double z, double heigth, double length, double width)
	{
		this->start.setX(x);
		this->start.setY(y);
		this->start.setZ(z);
		this->height = heigth;
		this->length = length;
		this->width = width;
	}

	Point getPoint()
	{
		return start;
	}

	double volume() const
	{
		return height * length * width;
	}
	
	void peakPoints() const
	{
		cout << "> All points of cuboid:" << endl;

		double x = start.getX();
		double y = start.getY();
		double z = start.getZ();

		cout << "(" << x << ", " << y << ", " << z << ")" << endl;
		cout << "(" << x + height << ", " << y << ", " << z << ")" << endl;
		cout << "(" << x << ", " << y - length << ", " << z << ")" << endl;
		cout << "(" << x + height << ", " << y - length << ", " << z << ")" << endl;
		cout << "(" << x << ", " << y << ", " << z + width << ")" << endl;
		cout << "(" << x + height << ", " << y << ", " << z + width << ")" << endl;
		cout << "(" << x << ", " << y - length << ", " << z + width << ")" << endl;
		cout << "(" << x + height << ", " << y - length << ", " << z + width << ")" << endl;
	}
	
	void print() const
	{
		cout << "> Cubeoid: " << endl;

		start.print();
		cout << "Heigth: " << height << endl;
		cout << "Length: " << length << endl;
		cout << "Width: " << width << endl;
	}
};