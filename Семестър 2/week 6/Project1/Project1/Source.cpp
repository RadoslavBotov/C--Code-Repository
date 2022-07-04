#include<iostream>
using namespace std;

class MoveTest
{
public:
	MoveTest(const char* dataParam) : data(allocateMemory(dataParam)) 
	{
		cout << "Default constructor ( " << data << " )" << endl;
	}

	MoveTest(const MoveTest& rhs)
	{
		cout << "Copy constructor ( " << data << " )" << endl;
		data = allocateMemory(rhs.data);
	}

	MoveTest& operator = (const MoveTest& other)
	{
		cout << "Operator (" << data << ") = ( " << other.data << " )" << endl;
		if (this == &other) return *this;
		
		deleteMemory();
		data = allocateMemory(other.data);
		
		return *this;
	}
	/*
	MoveTest(const MoveTest&& rhs)
	{
		cout << "Move copy constructor ( " << data << " )" << endl;
		data = other.data;

	}

	MoveTest& operator = (const MoveTest&& other)
	{
		cout << "Move operator (" << data << ") = ( " << other.data << " )" << endl;
		if (this == &other) return *this;

		deleteMemory();
		data = allocateMemory(other.data);

		other.data = nullptr;

		return *this;
	}
	*/
	~MoveTest()
	{
		cout << "Destructor ( " << (data == nullptr ? "nullptr" : data) << " )" << endl;
		deleteMemory();
	}

	void print() const
	{
		cout << data << endl;
	}

private:
	char* data;

	char* allocateMemory(const char* source)
	{
		unsigned int size = strlen(source) + 1;

		char* target = new char[size];
		strcpy_s(target, size, source);

		return target;
	}

	void deleteMemory()
	{
		delete[] data;
	}
};

int main()
{
	MoveTest x = MoveTest("123");
	MoveTest y = MoveTest("qwe");

	x = y;
	
	y = MoveTest("!?!");

	x.print();
	y.print();

	return 0;
}