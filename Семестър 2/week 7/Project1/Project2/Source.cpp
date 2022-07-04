#include<iostream>
#include<fstream>
using namespace std;

class Student;
class University;
ostream& operator << (ostream&, const Student&);
istream& operator >> (istream&, Student&);

class Student
{
public:
	Student()
	{
		copy(name, "\0");
		age = 0;
	}

	Student(const char* nameParam, const unsigned short ageParam)
	{
		copy(name, nameParam);
		age = ageParam;
	}

	Student(const Student& source)
	{
		copy(name, source.name);
		age = source.age;
	}

	Student& operator = (const Student& source)
	{
		if (this != &source)
		{
			deleteMemory();

			copy(name, source.name);
			age = source.age;
		}
		return *this;
	}

	~Student()
	{
		deleteMemory();
	}

	friend ostream& operator << (ostream&, const Student&);
	friend istream& operator >> (istream&, Student&);

private:
	char* name;
	unsigned short age;

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

		age = 0;
	}
};

ostream& operator << (ostream& os, const Student& source)
{
	os << source.name << ", " << source.age << endl;
	return os;
}

istream& operator >> (istream& is, Student& target)
{
	is >> target.name >> target.age;
	return is;
}

class University
{
public:
	University()
	{
		copy(name, "\0");
		students = nullptr;
		currentSize = 0;
	}

	University(const char* nameParam, unsigned int currentSizeParam)
	{
		copy(name, nameParam);
		currentSize = currentSizeParam;
		students = new Student[currentSize];
	}

	University(const University& source)
	{
		copy(name, source.name);
		currentSize = source.currentSize;
		students = new Student[currentSize];
	}

	University& operator = (const University& source)
	{
		if (this != &source)
		{
			copy(name, source.name);
			for (size_t i = 0; i < source.currentSize; i++)
				students[i] = source.students[i];
			currentSize = source.currentSize;
		}
		return *this;
	}

	~University()
	{
		deleteMemory();
	}

	void addStudent(Student& source)
	{
		students[currentSize] = source;
		currentSize++;
	}

	friend ostream& operator << (ostream&, const University&);
	friend istream& operator >> (istream&, University&);

private:
	char* name;
	Student* students;
	int currentSize;

	void resize(const size_t index)
	{
		currentSize--;
		for (size_t i = index; i < currentSize; i++)
			students[i] = students[i + 1];
	}

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

		delete[] students;
		students = nullptr;

		currentSize = 0;
	}

	void writeTextFile()
	{
		char nameOfFile[] = "text_";
		strcat(nameOfFile, name);

		ofstream out(nameOfFile, ios::app);

		if (!out)
			return;

		out << *this;

		out.close();
	}

	/*
	функции, които записват и четат университет от бинарен файл, като името на файла е binary_<име_на_университета>.dat.
	Имената на файловете не се подават като аргумент, а се генерират във функциите!
	*/
};

ostream& operator << (ostream& os, const University& source)
{
	os << source.name << endl;
	for (size_t i = 0; i < source.currentSize; i++)
		cout << source.students[i];
	return os;
}

istream& operator >> (istream& is, University& target)
{
	is >> target.name;
	for (size_t i = 0; i < target.currentSize; i++)
		is >> target.students[i];
	return is;
}

int main()
{


	return 0;
}