#include "SimplePair.h"
#include<iostream>
#include<cstring>

SimplePair::SimplePair(const char* keyParam, const char* valueParam)
{
	bool keyValid = true;
	size_t i = 1;

	if (keyParam[0] >= 'a' && keyParam[0] <= 'z')
		while (keyParam[i] != '\0')
		{
			if (!((keyParam[i] >= 'a' && keyParam[i] <= 'z') || keyParam[i] == '_'))
			{
				keyValid = false;
				break;
			}
			i++;
		}
	else
		keyValid = false;

	if (keyValid)
	{
		copyStr(key, keyParam);
		copyStr(value, valueParam);
	}
	else
	{
		std::cout << "> Key has invalid symbols!" << std::endl;
		key = nullptr;
		value = nullptr;
	}
}

SimplePair::SimplePair(const SimplePair& source)
{
	copyStr(key, source.key);
	copyStr(value, source.value);
}

SimplePair::SimplePair(SimplePair&& source)
{
	key = source.key;
	source.key = nullptr;

	value = source.value;
	source.value = nullptr;
}

SimplePair& SimplePair::operator=(const SimplePair& source)
{
	if (this != &source)
	{
		freeMemory();

		copyStr(key, source.key);
		copyStr(value, source.value);
	}
	return *this;
}

SimplePair& SimplePair::operator = (SimplePair&& source)
{
	if (this != &source)
	{
		key = source.key;
		source.key = nullptr;

		value = source.value;
		source.value = nullptr;
	}
	return *this;
}

SimplePair::~SimplePair()
{
	freeMemory();
}

const char* SimplePair::getValue() const
{
	return value;
}

void SimplePair::copyStr(char*& destination, const char* source)
{
	size_t size = strlen(source) + 1;
	destination = new char[size];
	strcpy_s(destination, size, source);
}

void SimplePair::print() const
{
	std::cout << key << " " << value << std::endl;
}

void SimplePair::freeMemory()
{
	delete[] key;
	key = nullptr;

	delete[] value;
	value = nullptr;
}