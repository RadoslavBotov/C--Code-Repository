#pragma once
#include<iostream>
#include<cstring>

class HelperString
{
public:
	HelperString(const char* strParam = "\0")
	{
		copy(str, strParam);
	}

	HelperString(const HelperString& source)
	{
		copy(str, source.str);
	}

	HelperString& operator = (const HelperString& source)
	{
		if (this != &source)
		{
			delete[] str;

			copy(str, source.str);
		}
		return *this;
	}

	~HelperString()
	{
		delete[] str;
	}

	friend std::ostream& operator << (std::ostream& os, const HelperString& source)
	{
		os << source.str;
		return os;
	}

	friend std::istream& operator >> (std::istream& is, HelperString& destination)
	{
		char buffer[128];
		is.getline(buffer, 128, '\n');

		size_t size = strlen(buffer) + 1;
		destination.str = new char[size];
		strcpy_s(destination.str, size, buffer);

		return is;
	}

private:
	char* str;

	void copy(char*& destination, const char* source)
	{
		size_t size = strlen(source) + 1;
		destination = new char[size];
		strcpy_s(destination, size, source);
	}
};