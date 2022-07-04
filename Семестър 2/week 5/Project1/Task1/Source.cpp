#include<iostream>
using namespace std;

class Example1
{
private:
	char* str;

	void deleteMemory()
	{
		delete[] str;
	}

	void allocateMemory(char *& str, const char* strVal)
	{
		unsigned size = strlen(strVal) + 1;

		str = new char[size];
		strcpy_s(str, size, strVal);
	}

public:
	Example1() : str(nullptr) { }

	Example1(const char* strVal) : str(nullptr)
	{
		cout << "> Example1 constructor." << endl;
		allocateMemory(str, strVal);
	}

	~Example1()
	{
		cout << "> Example1 destructor." << endl;
		deleteMemory();
	}

	Example1(const Example1& obj)
	{
		cout << "> Example1 copy constructor." << endl;
		allocateMemory(str, obj.getStr());
	}

	Example1& operator = (const Example1& obj)
	{
		cout << "> Example1 operator." << endl;
		if (this == &obj) return *this;

		deleteMemory();
		allocateMemory(str, obj.getStr());

		return *this;
	}

	char* getStr() const
	{
		return str;
	}

	void setStr(const char* strVal)
	{
		deleteMemory();
		allocateMemory(str, strVal);
	}

	void print() const
	{
		cout << str << endl;
	}
};

class Example2
{
private:
	Example1 str;

public:
	Example2(const Example1& obj)
	{
		cout << "> Example2 constructor." << endl;
		str = obj;
	}

	~Example2()
	{
		cout << "> Example2 destructor." << endl;
	}

	char* getStr() const
	{
		return str.getStr();
	}
};

int main()
{
	Example1 ex1("text 1");
	Example1 ex2 = ex1;
	Example1 ex3("text 3");

	cout << "Ex1: " << ex1.getStr() << endl;
	cout << "Ex2: " << ex2.getStr() << endl;
	cout << "Ex3: " << ex3.getStr() << endl << endl;

	ex3 = ex2;

	cout << "Ex3: " << ex3.getStr() << endl << endl;

	Example2 exx1(ex3);
	cout << "Exx1: " << exx1.getStr() << endl << endl;

	return 0;
}