#pragma once
#include<string>

enum Genre
{
	ACTION,
	HORROR,
	COMEDY
};

enum PgRating
{
	G,
	PG13,
	NC17
};

class Streamable
{
public:
	virtual ~Streamable() = default;

	virtual std::string getTitle() const = 0; // name
	virtual int getDuration() const = 0;	  // duration in movie
	virtual Genre getGenre() const = 0;		  // type
	virtual PgRating getRating() const = 0;	  // rating

	virtual Streamable* clone() = 0;
};