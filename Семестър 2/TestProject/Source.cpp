#include<iostream>
#include<fstream>
using namespace std;

class A
{
public:
	A(const int& xParam = 0, const char* strParam = "\0")
	{
		x = xParam;
		copy(str, strParam);
	}
	
	A(const A& source)
	{
		x = source.x;
		copy(str, source.str);
	}

	A& operator = (const A& source)
	{
		if (this != &source)
		{
			delete[] str;

			x = source.x;
			copy(str, source.str);
		}
		return *this;
	}

	~A()
	{
		delete[] str;
	}

	void print() const
	{
		cout << x << " " << str << " ";
	}

	void serialize(std::ofstream& out)
	{
		if (!out)
			return;

		out.write((const char*)&x, sizeof(int));

		size_t size = strlen(str) + 1;
		out.write((const char*)&size, sizeof(size_t));
		out.write(str, size);
	}

	void deserialize(std::ifstream& in)
	{
		if (!in)
			return;

		in.read((char*)&x, sizeof(int));

		size_t size = 0;

		in.read((char*)&size, sizeof(size_t));
		str = new char[size];
		in.read(str, size);
	}

	void writeToFile(std::ofstream& out)
	{
		if (!out)
			return;

		out << x << " " << str;
	}

	void readFromFile(std::ifstream& in)
	{
		char buffer[128] = {};

		in >> x;
		in.get();

		in.getline(buffer, 128, ' ');
		delete[] str;
		copy(str, buffer);
	}

private:
	int x;
	char* str;

	void copy(char*& destination, const char* const& source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
};

class B
{
public:
	B(int x, const char* str, int numberParam)
		: character(x, str)
	{
		number = numberParam;
	}

	B(const A& objAParam, int numberParam)
		: character(objAParam)
	{
		number = numberParam;
	}

	void print() const
	{
		character.print();
		cout << number << endl;
	}

	void serialize(const char* filename)
	{
		std::ofstream out(filename, std::ios::binary);

		if (!out)
			return;

		number++;

		character.serialize(out);

		out.write((const char*)&number, sizeof(int));

		out.close();
	}

	void deserialize(const char* filename)
	{
		std::ifstream in(filename, std::ios::binary);

		if (!in)
			return;

		character.deserialize(in);

		in.read((char*)&number, sizeof(int));

		in.close();
	}

	void writeToFile(const char* filename)
	{
		std::ofstream out(filename, std::ios::binary);

		if (!out)
			return;

		character.writeToFile(out);
		out << " " << number << endl;

		out.close();
	}

	void readFromFile(const char* filename)
	{
		std::ifstream in(filename, std::ios::binary);

		if (!in)
			return;

		character.readFromFile(in);

		in >> number;
		in.get();

		in.close();
	}

private:
	A character;
	int number;
};

int main()
{
	B b1(A(101, "!@#"), 5);
	B b2(A(0, ""), 0);

	b1.print();
	b1.writeToFile("textFile.txt");

	b2.readFromFile("textFile.txt");
	b2.print();

	return 0;
}