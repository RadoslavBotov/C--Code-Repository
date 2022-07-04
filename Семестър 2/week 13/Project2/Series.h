#pragma once
#include<string>
#include<vector>
#include"Streamable.h"
#include"Episode.h"

class Series : public Streamable
{
public:
	Series(std::string nameParam, Genre typeParam, PgRating ratingParam)
	{
		name = nameParam;
		type = typeParam;
		rating = ratingParam;
	}

	~Series()
	{
		for (Episode* ep : episodes)
			delete ep;
		episodes.clear();
	}

	virtual std::string getTitle() const override
	{
		return name;
	}

	virtual int getDuration() const override
	{
		unsigned sum = 0;

		for (Episode* ep : episodes)
			sum += ep->getLengthOfFilm();

		return sum;
	}

	virtual Genre getGenre() const override
	{
		return type;
	}

	virtual PgRating getRating() const override
	{
		return rating;
	}

	const std::vector<Episode*>& getEpisodes() const
	{
		return episodes;
	}

	virtual Streamable* clone() override
	{
		return new Series(*this);
	}

private:
	std::string name;
	Genre type;
	PgRating rating;
	std::vector <Episode*> episodes;
};