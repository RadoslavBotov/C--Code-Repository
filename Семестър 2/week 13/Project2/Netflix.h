#pragma once
#include<vector>
#include"StreamingService.h"
#include"Streamable.h"

class Netflix : public StreamingService
{
public:
	Netflix(Account* accountsParam, size_t numberOfAccountsParam, Streamable** streamableContentParam, size_t numberOfContentParam)
	{
		totalWatchedTime = 0;
		numberOfAccounts = numberOfAccountsParam;
		numberOfContent = numberOfContentParam;

		for (size_t i = 0; i < numberOfAccounts; i++)
			accounts[i] = accountsParam[i];

		for (size_t i = 0; i < numberOfContent; i++)
			streamableContent.push_back(streamableContentParam[i]->clone());
	}

	~Netflix()
	{
		delete[] accounts;

		for (Streamable* st : streamableContent)
			delete st;
		streamableContent.clear();
	}

	void addVideo(Streamable* source)
	{
		numberOfContent++;
		streamableContent.push_back(source->clone());
	}

	virtual void watch(Account user, std::string videoContentName) override
	{
		bool userExists = false;

		for (size_t i = 0; i < numberOfAccounts; i++)
			if (accounts[i].getName() == user.getName())
			{
				userExists = true;
				break;
			}

		if (userExists)
			for (size_t i = 0; i < numberOfAccounts; i++)
				if (streamableContent[i]->getTitle() == videoContentName)
				{
					totalWatchedTime += streamableContent[i]->getDuration();
					break;
				}
	}

	virtual int totalWatchedTimeByUsers() const override
	{
		return totalWatchedTime;
	}

private:
	Account* accounts;
	size_t numberOfAccounts;
	std::vector <Streamable*> streamableContent;
	size_t numberOfContent;
	unsigned totalWatchedTime;
};