//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.h"
#include<iostream>
#include<fstream>
using namespace std;

class StringHolder;
ostream& operator << (ostream&, const StringHolder&);
ofstream& operator << (ofstream&, const StringHolder&);

class StringHolder
{
public:
	StringHolder(const char* strSource = "\0")
	{
		size_t size = strlen(strSource) + 1;
		str = new char[size];
		strcpy_s(str, size, strSource);
	}

	StringHolder(const StringHolder& source)
	{
		size_t size = strlen(source.str) + 1;
		str = new char[size];
		strcpy_s(str, size, source.str);
	}

	StringHolder& operator = (const StringHolder& source)
	{
		if (this != &source)
		{
			delete[] str;

			size_t size = strlen(source.str) + 1;
			str = new char[size];
			strcpy_s(str, size, source.str);
		}
		return *this;
	}

	~StringHolder()
	{
		delete[] str;
	}

	friend ostream& operator << (ostream& os, const StringHolder& source)
	{
		cout << source.str;
		return os;
	}

	friend ofstream& operator << (ofstream& of, const StringHolder& source)
	{
		of.write(source.str, strlen(source.str) + 1);
		return of;
	}

private:
	char* str;
};

int main()
{
	

	return 0;
}

/*
int main()
{
	if (false)
	{
		StringHolder a("qwerty");
		cout << a << endl;

		ofstream out("testFile3");

		if (!out)
		{
			cout << "> File could not be opened." << endl;
			throw exception("File could not be opened.");
		}

		out << a;

		out.close();
	}

	if (false)
	{
		ofstream file3("testFile2", ios::binary);

		char source[128];
		cin >> source;

		size_t size = strlen(source) + 1;
		char* str = new char[size];
		strcpy_s(str, size, source);

		file3.write(str, size);

		delete[] str;
		file3.close();
	}

	if (false)
	{
		ifstream file4("testFile2", ios::binary);

		char buffer[128];
		file4.read(buffer, 25);
		cout << buffer << endl;

		file4.close();
	}

	if (false)
	{
		ofstream file1("testFile.txt", ios::binary);

		if (!file1)
		{
			cout << "> File cannot be opened!" << endl;
			throw exception("File cannot be opened!");
		}

		int a = -1;
		int b = -10;
		int c = -100;

		file1.write((const char*)&a, sizeof(a));
		file1.write((const char*)&b, sizeof(b));
		file1.write((const char*)&c, sizeof(c));

		double d = 10.123;
		float e = 123.101;

		file1.write((const char*)&d, sizeof(d));
		file1.write((const char*)&e, sizeof(e));

		char ch = 'a';
		char str1[7] = "qwerty";
		char str2[10] = "123456789";

		file1.write((const char*)&ch, sizeof(ch));
		file1.write(str1, sizeof(str1));
		file1.write(str2, sizeof(str2));

		file1.close();
	}

	if (false)
	{
		ifstream file2("testFile.txt", ios::binary);

		if (!file2)
		{
			cout << "> File cannot be opened!" << endl;
			throw exception("File cannot be opened!");
		}

		int var;

		file2.read((char*)&var, sizeof(int));
		cout << var << endl;

		file2.read((char*)&var, sizeof(int));
		cout << var << endl;

		file2.read((char*)&var, sizeof(int));
		cout << var << endl;

		double dd;
		float f;

		file2.read((char*)&dd, sizeof(double));
		file2.read((char*)&f, sizeof(float));
		cout << dd << endl;
		cout << f << endl;

		char ch2;
		char buffer[1024];

		file2.read((char*)&ch2, sizeof(char));
		cout << ch2 << endl;

		file2.read(buffer, 7);
		cout << buffer << endl;

		file2.read(buffer, 10);
		cout << buffer << endl;

		file2.close();
	}

	return 0;
}
*/