#include<iostream>
#include<fstream>
//#include<doctest.h>
using namespace std;

class A;
class B;

ostream& operator << (ostream&, const A&);
istream& operator >> (istream&, A&);

ostream& operator << (ostream&, const B&);
istream& operator >> (istream&, B&);

class A
{
public:
	A()
	{
		a = 0;
		d = 1.23;
	}

	A(const int aParam, const double dParam = 1.23)
	{
		a = aParam;
		d = dParam;
	}

	friend ostream& operator << (ostream& os, const A& source)
	{
		os << source.a << " " << source.d;
		return os;
	}

	friend istream& operator >> (istream& is, A& target)
	{
		is >> target.a >> target.d;
		return is;
	}

	void writeToTextFile(const char* fileName) const
	{
		ofstream out(fileName);

		out << a << '\n';
		out << d << '\n';

		out.close();
	}

	void readFromTextFile(const char* fileName)
	{
		ifstream in(fileName);

		if (!in)
		{
			cout << "> File \"" << fileName << "\" could not be opened." << endl;
			return;
		}

		char buffer[1024];
		in.getline(buffer, 100);
		a = atoi(buffer);

		in.getline(buffer, 100);
		d = atof(buffer);

		in.close();
	}

	void writeToBinaryFile(const char* fileName) const
	{
		ofstream out(fileName, ios::binary);

		if (!out)
		{
			cout << "> File \"" << fileName << "\" could not be opened." << endl;
			return;
		}

		out.write((const char*)&a, sizeof(a));
		out.write((const char*)&d, sizeof(d));

		out.close();
	}

	void readFromBinaryFile(const char* fileName)
	{
		ifstream in(fileName, ios::binary);

		if (!in)
		{
			cout << "> File \"" << fileName << "\" could not be opened." << endl;
			return;
		}

		in.read((char*)&a, sizeof(a));
		in.read((char*)&d, sizeof(d));

		in.close();
	}

	int getA() const
	{
		return a;
	}

private:
	int a;
	double d;
};

class B
{
public:
	B()
	{
		b = 0;
		numberA = A();
	}

	B(const int bParam, const A obj)
	{
		b = bParam;
		numberA = obj;
	}

	friend ostream& operator << (ostream& os, const B& source)
	{
		os << source.b << " " << source.numberA;
		return os;
	}

	friend istream& operator >> (istream& is, B& target)
	{
		is >> target.b >> target.numberA;
		return is;
	}

	void writeToTextFile(const char* fileName) const
	{
		ofstream out(fileName);

		if (!out)
		{
			cout << "> File \"" << fileName << "\" could not be opened." << endl;
			return;
		}

		out << b << '\n';
		out << numberA << '\n';

		out.close();
	}

	void readFromTextFile(const char* fileName)
	{
		ifstream in(fileName);

		if (!in)
		{
			cout << "> File \"" << fileName << "\" could not be opened." << endl;
			return;
		}

		char buffer[1024];
		while (in.getline(buffer, 100))
		{
			std::cout << buffer << ' ';
		}
		cout << endl;

		in.close();
	}

	void writeToBinaryFile(const char* fileName) const
	{
		ofstream out(fileName, ios::binary);

		if (!out)
		{
			cout << "> File \"" << fileName << "\" could not be opened." << endl;
			return;
		}

		out.write((const char*)&b, sizeof(int));
		out.write((const char*)&numberA, sizeof(A));

		out.close();
	}

	void readFromBinaryFile(const char* fileName)
	{
		ifstream in(fileName, ios::binary);

		if (!in)
		{
			cout << "> File \"" << fileName << "\" could not be opened." << endl;
			return;
		}

		in.read((char*)&b, sizeof(int));
		in.read((char*)&numberA, sizeof(A));

		in.close();
	}

private:
	int b;
	A numberA;
};
// /*
int main()
{
	A objA(2, 10.101);
	B objB(3, objA);

	cout << "> ObjA: " << objA << endl;
	cout << "> ObjB: " << objB << endl;
	cout << "------------------------------------------" << endl;

	objA.writeToTextFile("info_text_objA.txt");
	objA.writeToBinaryFile("binary_objA.dat");

	objB.writeToTextFile("info_text_objB.txt");
	objB.writeToBinaryFile("binary_objB.dat");

	//objA.readFromTextFile("info_text_objA.txt");
	//objA.readFromBinaryFile("binary_objA.dat");

	//objB.readFromTextFile("info_text_objB.txt");
	//objB.readFromBinaryFile("binary_objB.dat");

	B objC(4, objA);
	B objD;

	objC.writeToBinaryFile("binary_objC.dat");
	objD.readFromBinaryFile("binary_objC.dat");

	cout << "> ObjA: " << objA << endl;
	cout << "> ObjB: " << objB << endl;
	cout << "> ObjC: " << objC << endl;
	cout << "> ObjD: " << objD << endl;
	
	return 0;
}
// */