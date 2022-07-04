#include<iostream>
using namespace std;

class Point
{
private:
	double x;
	double y;

public:
	Point();

	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	double getX() const
	{
		return x;
	}

	double getY() const
	{
		return y;
	}

	void setX(double x)
	{
		this->x = x;
	}

	void setY(double y)
	{
		this->y = y;
	}

	void quadrant()
	{
		if (x > 0)
		{
			if (y > 0)
				cout << "> Point is in first quadrant." << endl;
			else if (y < 0)
				cout << "> Point is in third quadrant." << endl;
		}
		else if (x < 0)
		{
			if (y > 0)
				cout << "> Point is in second quadrant." << endl;
			else if (y < 0)
				cout << "> Point is in fourth quadrant." << endl;
		}
	}

	void print() const
	{
		cout << "> X : " << x << endl;
		cout << "> Y : " << y << endl;
	}
};

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
		cout << "> Radius: " << rad << endl;
	}
};
/*
int main()
{
	Square s(1, 1, 1);
	Rectangle r(2, 2, 2, 2);
	Circle c(3, 3, 3);

	cout << s.area() << endl;
	s.peakPoints();
	s.print();

	cout << endl;

	cout << r.area() << endl;
	r.peakPoints();
	r.print();

	cout << endl;

	cout << c.area() << endl;
	c.print();

	return 0;
}
*/