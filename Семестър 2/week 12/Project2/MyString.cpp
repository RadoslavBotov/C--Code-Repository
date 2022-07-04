#include "MyString.h"
#include<cstring>

MyString::MyString(const char* source)
{
	copy(str, source);
}

MyString::MyString(const MyString& source)
{
	copy(str, source.str);
}

MyString& MyString::operator=(const MyString& source)
{
	if (this != &source)
	{
		delete[] str;

		copy(str, source.str);
	}
	return *this;
}

MyString::~MyString()
{
	delete[] str;
}

void MyString::copy(char*& destination, const char* source)
{
	size_t size = strlen(source) + 1;
	destination = new char[size];
	strcpy_s(destination, size, source);
}

std::ostream& operator<<(std::ostream& os, const MyString& source)
{
	os << source.str;
	return os;
}
