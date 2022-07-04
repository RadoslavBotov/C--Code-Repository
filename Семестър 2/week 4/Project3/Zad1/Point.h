#pragma once


class Point
{
private:
	double x;
	double y;

public:
	Point(){}

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