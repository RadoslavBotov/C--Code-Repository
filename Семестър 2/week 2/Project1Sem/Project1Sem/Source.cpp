#include<iostream>
using namespace std;

enum Faculty
{
	FMI,
	HF,
	FF
};

class Student
{
private:
	char* mFirstName;
	char* mMiddleName;
	char* mLastName;
	unsigned mFacultyNumber;
	Faculty mFaculty;

	void copy(char*& target, const char* source)
	{
		int size = strlen(source) + 1;
		target = new char[size];
		strcpy_s(target, size, source);
	}

	void deleteMemory()
	{
		delete[] mFirstName;
		delete[] mMiddleName;
		delete[] mLastName;
	}

public:
	Student(const char* firstName = "Placeholder", const char* middleName = "Placeholder", 
		    const char* lastName = "Placeholder", unsigned facultyNumber = 1, Faculty faculty = FMI)
	{
		copy(mFirstName, firstName);
		copy(mMiddleName, middleName);
		copy(mLastName, lastName);

		mFacultyNumber = facultyNumber;
		mFaculty = faculty;
	}

	Student(const Student& source)
	{
		copy(mFirstName, source.mFirstName);
		copy(mMiddleName, source.mMiddleName);
		copy(mLastName, source.mLastName);

		mFacultyNumber = source.mFacultyNumber;
		mFaculty = source.mFaculty;
	}

	Student& operator = (Student const& other)
	{
		if (this != &other)
		{
			deleteMemory();

			copy(mFirstName, other.mFirstName);
			copy(mMiddleName, other.mMiddleName);
			copy(mLastName, other.mLastName);

			mFacultyNumber = other.mFacultyNumber;
			mFaculty = other.mFaculty;
		}
		return *this;
	}

	bool operator == (Student const& other)
	{
		bool a = (strcmp(mFirstName, other.mFirstName) == 0);
		bool b = (strcmp(mMiddleName, other.mMiddleName) == 0);
		bool c = (strcmp(mLastName, other.mLastName) == 0);
		bool d = (mFacultyNumber == other.mFacultyNumber);
		bool e = (mFaculty == other.mFaculty);
		return a && b && c && d && e;
	}

	~Student()
	{
		deleteMemory();
	}

	char* getFirstName()const
	{
		return mFirstName;
	}

	char* getMiddleName()const
	{
		return mMiddleName;
	}

	char* getLastName()const
	{
		return mLastName;
	}

	unsigned getFacultyNumber()const
	{
		return mFacultyNumber;
	}

	Faculty getFaculty()const
	{
		return mFaculty;
	}
};

void printStudent(Student& student)
{
	cout << "First Name    : " << student.getFirstName() << endl;
	cout << "Middle Name   : " << student.getMiddleName() << endl;
	cout << "Last Name     : " << student.getLastName() << endl;
	cout << "Faculty       : " << student.getFaculty() << endl;
	cout << "Faculty Number: " << student.getFacultyNumber() << endl << endl;
}

int main()
{
	Student student1("Radoslav", "Anatoliev", "Botov", 30800064, FMI);
	Student student2("Radoslav", "Anatoliev", "Botov", 30800064, FMI);
	Student student3("Radoslav", "Anatoliev", "Botov", 30800064, HF);

	printStudent(student1);
	printStudent(student2);
	printStudent(student3);

	cout << "> 1 == 2: " << (student1 == student2) << endl;
	cout << "> 2 == 1: " << (student2 == student1) << endl;
	cout << "> 1 == 3: " << (student1 == student3) << endl;
	cout << "> 2 == 3: " << (student2 == student3) << endl;

	return 0;
}