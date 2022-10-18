#pragma once

class SimplePair
{
public:
	SimplePair(const char* keyParam, const char* valueParam);
	SimplePair(const SimplePair& source);
	SimplePair(SimplePair&& source);
	SimplePair& operator = (const SimplePair& source);
	SimplePair& operator = (SimplePair&& source);
	virtual ~SimplePair();

	const char* getValue() const;

	void print() const;
	void freeMemory();

private:
	char* key;
	char* value;

	void copyStr(char*& destination, const char* source);
};