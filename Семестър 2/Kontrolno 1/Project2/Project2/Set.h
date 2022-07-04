#pragma once
#include<iostream>

class Set;
ostream& operator << (ostream& os, const Set& source);
istream& operator >> (istream& is, const Set& target);

class Set
{
public:
	Set();
	Set(const char* nameParam, const unsigned int** elemntsParam, const unsigned int sizeParam);
	Set(const Set& source);
	Set& operator = (const Set& source);
	~Set();

	Set& operator + (const Set& source);
	friend ostream& operator << (ostream& os, const Set& source);
	friend istream& operator >> (istream& is, const Set& target);
	//bool operator  (const Set&);

private:
	char* name;
	unsigned int** elements;
	unsigned int size;

	void copy(char*& target, const char* source);
	void copy(unsigned int**& targets, const unsigned int** source, unsigned int size);
	void deleteMemory();
};