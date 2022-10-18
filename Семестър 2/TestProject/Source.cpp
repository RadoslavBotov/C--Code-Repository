#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base() ";
	}
	
	~Base()
	{
		cout << "~Base() ";
	}

	void print() const
	{
		cout << "\nBase::Print()\n";
	}
};

class Der1 : virtual public Base
{
public:
	Der1() : Base()
	{
		cout << "Der1() ";
	}

	~Der1()
	{
		cout << "~Der1() ";
	}

	void print() const
	{
		cout << "\nDer1::Print()\n";
	}
};

class Der2 : virtual public Base
{
public:
	Der2() : Base()
	{
		cout << "Der2() ";
	}

	~Der2()
	{
		cout << "~Der2() ";
	}

	void print() const
	{
		cout << "\nDer2::Print()\n";
	}
};

class Der : public Der1, public Der2
{
public:
	Der() : Der1(), Der2()
	{
		cout << "Der() ";
	}

	~Der()
	{
		cout << "~Der() ";
	}

	// Print fields current of Der object.
	void print() const
	{
		cout << "\nDer::Print()\n";
	}
};

int main()
{
	Der d;
	((Base*)&d)->print();
	//((Der1&)d).print();
	//((Der2&)d).print();
	//((Der&)d).print();

	return 0;
}