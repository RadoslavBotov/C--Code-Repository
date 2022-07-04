#pragma once
#include<string>

class Episode
{
public:
	Episode(std::string nameParam, unsigned lengthOfFilmParam)
	{
		name = nameParam;
		lengthOfFilm = lengthOfFilmParam;
	}

	const std::string& getName() const
	{
		return name;
	}

	unsigned getLengthOfFilm() const
	{
		return lengthOfFilm;
	}

private:
	std::string name;
	unsigned lengthOfFilm;
};