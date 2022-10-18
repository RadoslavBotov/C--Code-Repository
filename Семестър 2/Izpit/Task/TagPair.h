#pragma once
#include"SimplePair.h"

class TagPair : public SimplePair
{
public:
	TagPair(const char* keyParam, const char* valueParam);
	TagPair(const TagPair& source);
	TagPair(TagPair&& source);
	TagPair& operator = (const TagPair& source);
	TagPair& operator = (TagPair&& source);
	~TagPair() = default;

private:

};