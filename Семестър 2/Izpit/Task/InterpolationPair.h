#pragma once
#include"SimplePair.h"

class InterpolationPair : public SimplePair
{
public:
	InterpolationPair(const char* keyParam, const char* valueParam);
	InterpolationPair(const InterpolationPair& source);
	InterpolationPair(InterpolationPair&& source);
	InterpolationPair& operator = (const InterpolationPair& source);
	InterpolationPair& operator = (InterpolationPair&& source);
	~InterpolationPair() = default;

	void printValue();

private:
	bool containSymbol(const char* str, char symbol) const;
};