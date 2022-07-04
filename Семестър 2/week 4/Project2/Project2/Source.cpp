#include<iostream>
using namespace std;

class Person
{
private:
	int x;
public:
	Person(int x)
	{
		this->x = x;
	}

	Person operator = (const Person other)
	{
		x = other.x;
		return x;
	}

	int getX()
	{
		return x;
	}
};



int main()
{
	Person person1(1);
	Person person2(5);

	cout << person1.getX() << endl;
	cout << person2.getX() << endl;
	person1 = person2;
	cout << person1.getX() << endl;
	cout << person2.getX() << endl;

	return 0;
}