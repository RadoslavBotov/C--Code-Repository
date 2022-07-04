#pragma once
#include<string>

class Account
{
public:
	Account(std::string nameParam, std::string timeOfRegParam)
	{
		name = nameParam;
		timeOfReg = timeOfRegParam;
	}

	const std::string& getName() const
	{
		return name;
	}

private:
	std::string name;
	std::string timeOfReg; // registration time
};