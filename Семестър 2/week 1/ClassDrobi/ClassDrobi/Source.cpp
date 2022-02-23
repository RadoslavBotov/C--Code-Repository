#include<iostream>
using namespace std;

class Fractions
{
	int numerator;
	int denominator;

	public:
		Fractions()
		{
			numerator = 1;
			denominator = 1;
		}
	
		Fractions(int n, int d = 1)
		{
			numerator = n;
			if (d == 0)
				cout << "Error: Denominator is 0!" << endl;
			else
				denominator = d;
		}

		int gcd(int a, int b)
		{
			while (b != 0)
			{
				a %= b;
				swap(a, b);
			}
			return a;
		}

		void simplyfy(int &a, int &b)
		{
			int number = gcd(a, b);
			if (number != 1)
			{
				a /= number;
				b /= number;
			}
		}

		Fractions Addition(Fractions b)
		{
			int n = numerator * b.denominator + denominator * b.numerator;
			int d = denominator * b.denominator;
			simplyfy(n, d);
			return Fractions(n, d);
		}

		Fractions Subtraction(Fractions b)
		{
			int n = numerator * b.denominator - denominator * b.numerator;
			int d = denominator * b.denominator;
			simplyfy(n, d);
			return Fractions(n, d);
		}
	
		Fractions Multiplication(Fractions b)
		{
			int n = numerator * b.numerator;
			int d = denominator * b.denominator;
			simplyfy(n, d);
			return Fractions(n, d);
		}
	
		Fractions Division(Fractions b)
		{
			int n = numerator * b.denominator;
			int d = denominator * b.numerator;
			simplyfy(n, d);
			return Fractions(n, d);
		}

		void print()
		{
			cout << numerator << "/" << denominator << endl;
		}
};

int main()
{
	Fractions a(2, 3), b(3, 4);
	Fractions c;

	a.print();
	b.print();
	c.print();

	cout << endl;
	c = a.Addition(b);
	c.print();

	cout << endl;
	c = a.Subtraction(b);
	c.print();

	cout << endl;
	c = a.Multiplication(b);
	c.print();

	cout << endl;
	c = a.Division(b);
	c.print();

	return 0;
}