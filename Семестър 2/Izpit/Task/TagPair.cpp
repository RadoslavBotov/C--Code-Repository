#include "TagPair.h"
#include<iostream>
#include<cstring>

TagPair::TagPair(const char* keyParam, const char* valueParam)
	: SimplePair(keyParam, valueParam)
{
	size_t sizeKeyParam = strlen(keyParam) + 1;
	if (sizeKeyParam >= 5)
		if (!(strncmp(keyParam + sizeKeyParam - 6, "_html", 5) == 0))
		{
			std::cout << "> Key is invalid!" << std::endl;
			SimplePair::freeMemory();
		}
	else
	{
		std::cout << "> Key is invalid!" << std::endl;
		SimplePair::freeMemory();
	}


	if (valueParam[0] != '\"')
		std::cout << "!" << std::endl;
}

TagPair::TagPair(const TagPair& source)
	: SimplePair(source) {}

TagPair::TagPair(TagPair&& source)
	: SimplePair(source) {}

TagPair& TagPair::operator=(const TagPair& source)
{
	if (this != &source)
	{
		SimplePair::operator = (source);
	}
	return *this;
}

TagPair& TagPair::operator=(TagPair&& source)
{
	if (this != &source)
	{
		SimplePair::operator = (source);
	}
	return *this;
}