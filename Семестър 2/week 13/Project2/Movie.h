#pragma once
#include<string>
#include"Streamable.h"

class Movie : public Streamable
{
public:
	Movie(std::string nameParam, Genre typeParam, PgRating ratingParam, unsigned lengthOfFilmParam)
	{
		name = nameParam;
		type = typeParam;
		rating = ratingParam;
		lengthOfFilm = lengthOfFilmParam;
	}

	virtual std::string getTitle() const override
	{
		return name;
	}

	virtual int getDuration() const override
	{
		return lengthOfFilm;
	}

	virtual Genre getGenre() const override
	{
		return type;
	}

	virtual PgRating getRating() const override
	{
		return rating;
	}

	virtual Streamable* clone() override
	{
		return new Movie(*this);
	}

private:
	std::string name;
	Genre type;
	PgRating rating;
	unsigned lengthOfFilm;
};