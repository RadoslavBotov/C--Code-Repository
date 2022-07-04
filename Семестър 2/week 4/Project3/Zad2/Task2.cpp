#include<iostream>
using namespace std;

class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point() {}

	Point(double x, double y, double z) : x(x), y(y), z(z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	double getX() const
	{
		return x;
	}

	double getY() const
	{
		return y;
	}

	double getZ() const
	{
		return z;
	}

	void setX(double x)
	{
		this->x = x;
	}

	void setY(double y)
	{
		this->y = y;
	}

	void setZ(double z)
	{
		this->z = z;
	}

	void quadrant()
	{
		bool X = x > 0;
		bool Y = y > 0;
		bool Z = z > 0;

		if (X)
			if (Y)
				if (Z)
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the first quadrant." << endl;
				else
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the fifth quadrant." << endl;
			else
				if (Z)
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the fourth quadrant." << endl;
				else
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the eight quadrant." << endl;
		else
			if (Y)
				if (Z)
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the second quadrant." << endl;
				else
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the sixth quadrant." << endl;
			else
				if (Z)
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the third quadrant." << endl;
				else
					cout << "> Point (" << x << ", " << y << ", " << z << ") is in the seventh quadrant." << endl;
	}

	void print() const
	{
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
		cout << "Z: " << z << endl;
	}
};

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

int main()
{
	Cube c1(1, 1, 1, 1);
	Cubeoid c2(2, 2, 2, 2, 2, 2);
	Sphere s(3, 3, 3, 3);

	c1.print();
	c1.peakPoints();
	c1.getPoint().quadrant();
	cout << "> Cube volume: " << c1.volume() << endl << endl;

	c2.print();
	c2.peakPoints();
	c2.getPoint().quadrant();
	cout << "> Cubeoid volume: " << c2.volume() << endl << endl;

	s.print();
	s.getPoint().quadrant();
	cout << "> Sphere volume: " << s.volume() << endl;

	return 0;
}