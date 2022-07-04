#pragma once

class Point
{
private:
	double x;
	double y;
	double z;

public:
	Point(){}

	Point(double x, double y, double z) : x(x) , y(y), z(z)
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