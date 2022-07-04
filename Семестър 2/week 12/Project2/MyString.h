#pragma once
#include<iostream>

class MyString
{
public:
	MyString(const char* source = "\0");
	MyString(const MyString& source);
	MyString& operator = (const MyString& source);
	~MyString();

	friend std::ostream& operator << (std::ostream& os, const MyString& source);

private:
	char* str;

	void copy(char*& destination, const char* source);
};