#pragma once
#include<string>
#include"Account.h"

class StreamingService
{
public:
	//StreamingService() = default;
	virtual ~StreamingService() = default;

	virtual void watch(Account user, std::string videoContentName) = 0;
	virtual int totalWatchedTimeByUsers() const = 0;
};