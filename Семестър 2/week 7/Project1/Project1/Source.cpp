#include<iostream>
#include<fstream>
using namespace std;

class Animal;
ostream& operator << (ostream&, const Animal&);
istream& operator >> (istream&, Animal&);

class Animal
{
private:
	char* name;
	char* breed;
	unsigned short age;
	char* nameOfOwner;

	void copy(char*& target, const char* source)
	{
		size_t size = strlen(source) + 1;
		target = new char[size];
		strcpy_s(target, size, source);
	}

	void deleteMemory()
	{
		delete[] name;
		name = nullptr;

		delete[] breed;
		breed = nullptr;

		delete[] nameOfOwner;
		nameOfOwner = nullptr;
	}

public:
	Animal()
	{
		copy(name, "\0");
		copy(breed, "\0");
		copy(nameOfOwner, "\0");

		age = 0;
	}

	Animal(const char* nameParam, const char* breedParam, unsigned short ageParam, const char* nameOfOwnerParam)
	{
		copy(name, nameParam);
		copy(breed, breedParam);
		copy(nameOfOwner, nameOfOwnerParam);

		age = ageParam;
	}

	Animal(const Animal& source)
	{
		copy(name, source.name);
		copy(breed, source.breed);
		copy(nameOfOwner, source.nameOfOwner);

		age = source.age;
	}

	Animal& operator = (const Animal& other)
	{
		if (this != &other)
		{
			deleteMemory();

			copy(name, other.name);
			copy(breed, other.breed);
			copy(nameOfOwner, other.nameOfOwner);

			age = other.age;
		}
		return *this;
	}

	~Animal()
	{
		deleteMemory();
	}

	void textFileWrite(const char* nameOfFile) const
	{
		ofstream out(nameOfFile, ios::app);

		if (!out)
			return;

		out << *this;

		out.close();
	}

	void binaryFileWrite(const char* nameOfFile) const
	{
		ofstream out(nameOfFile, ios::binary);

		if (!out)
			return;

		size_t size1 = strlen(name) + 1;
		out.write((const char*)&size1, sizeof(size1));
		out.write(name, size1);

		size_t size2 = strlen(breed) + 1;
		out.write((const char*)&size2, sizeof(size2));
		out.write(breed, size2);

		size_t size3 = strlen(nameOfOwner) + 1;
		out.write((const char*)&size3, sizeof(size3));
		out.write(nameOfOwner, size3);

		out.write((const char*)&age, sizeof(age));

		out.close();
	}

	friend ostream& operator << (ostream&, const Animal&);
	friend istream& operator >> (istream&, Animal&);
};

ostream& operator << (ostream& os, const Animal& source)
{
	os << source.name << ", " << source.breed << ", " << source.age << ", " << source.nameOfOwner << endl;
	return os;
}

istream& operator >> (istream& is, Animal& target)
{
	is >> target.name >> target.breed >> target.age >> target.nameOfOwner;
	return is;
}

int main()
{
	Animal a1("Rex", "German shepard", 1, "Pesho");
	Animal a2("May", "Golden retriever", 2, "Ivan");

	cout << a1 << a2;

	a1.textFileWrite("AnimalTextTest");
	a2.textFileWrite("AnimalTextTest");

	return 0;
}