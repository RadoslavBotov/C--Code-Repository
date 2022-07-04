#pragma once
#include"MyString.h"
#include<cstring>

void MyString::deleteMemory()
{
	delete[] str;
}

void MyString::allocateMemory(char*& str, const char* strSource)
{
	unsigned size = strlen(strSource) + 1;

	str = new char[size];
	strcpy_s(str, size, strSource);
}

void MyString::resize()
{
	char* temp = new char[mCapacity];

	strcpy_s(temp, mCapacity, str);

	deleteMemory();

	mCapacity *= 2;
	strcpy_s(str, mCapacity, temp);

	delete[] temp;
}

MyString::MyString(const char* strSource = "\0")
{
	allocateMemory(str, strSource);
}

MyString::MyString(const MyString& source)
{
	allocateMemory(str, source.str);
}

MyString& MyString::operator = (const MyString& rhs)
{
	if (this == &rhs) return *this;

	deleteMemory();
	allocateMemory(str, rhs.str);

	return *this;
}

MyString::~MyString()
{
	deleteMemory();
}

bool MyString::empty() const
{
	return strlen(str) == 0;
}

char& MyString::at(unsigned indx)
{
	return str[indx];
}

unsigned int MyString::size() const
{
	return strlen(str);
}

unsigned int MyString::capacity() const
{
	return mCapacity;
}

void MyString::push_back(char c)
{
	unsigned int size = strlen(str) + 1;
	if (size >= mCapacity)
		resize();

	str[size - 1] = c;
	str[size] = '\0';
}