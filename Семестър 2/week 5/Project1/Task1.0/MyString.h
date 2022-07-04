#pragma once

class MyString
{
public:
	MyString(const char* strSource);
	MyString(const MyString& source);
	MyString& operator = (const MyString& rhs);
	~MyString();

	bool empty() const;
	char& at(unsigned indx);
	unsigned int size() const;
	unsigned int capacity() const;
	void push_back(char c);

private:
	char* str;
	unsigned int mCapacity;

	void deleteMemory();
	void allocateMemory(char*& str, const char* strSource);
	void resize();
};