#include "InterpolationPair.h"
#include<iostream>
#include<cstring>

InterpolationPair::InterpolationPair(const char* keyParam, const char* valueParam)
	: SimplePair(keyParam, valueParam)
{
	bool valueValid = true;
	size_t i = 0;
	size_t startPos = 0;
	size_t endPos = 0;

	while (valueParam[i] != '\0')
	{
		if (valueParam[i] == '%' && valueParam[i + 1] == '{')
			startPos = i;

		if (valueParam[i] == '}')
			endPos = i;

		if (startPos != 0 && endPos != 0)
			break;

		i++;
	}

	if (startPos >= endPos)
	{
		std::cout << "> Value is invalid!" << std::endl;
		SimplePair::freeMemory();
	}
}

InterpolationPair::InterpolationPair(const InterpolationPair& source)
	: SimplePair(source) {}

InterpolationPair::InterpolationPair(InterpolationPair&& source)
	: SimplePair(source) {}

InterpolationPair& InterpolationPair::operator=(const InterpolationPair& source)
{
	if (this != &source)
	{
		SimplePair::operator = (source);
	}
	return *this;
}

InterpolationPair& InterpolationPair::operator=(InterpolationPair&& source)
{
	if (this != &source)
	{
		SimplePair::operator = (source);
	}
	return *this;
}

void InterpolationPair::printValue()
{
	if (SimplePair::getValue() != nullptr)
	{
		char parameter[100] = {};
		char parameterValue[100] = {};

		size_t sizeValueParam = strlen(SimplePair::getValue()) + 1;
		char* valueParam = new char[sizeValueParam];
		strcpy_s(valueParam, sizeValueParam, SimplePair::getValue());

		std::cout << valueParam << std::endl;

		while (containSymbol(valueParam, '%'))
		{
			size_t i = 0;
			size_t startPos = 0;
			size_t endPos = 0;

			while (valueParam[i] != '\0')
			{
				if (valueParam[i] == '%' && valueParam[i + 1] == '{')
					startPos = i;

				if (valueParam[i] == '}')
					endPos = i;

				i++;
			}

			size_t sizeParameter = endPos - startPos + 1;
			strncpy(parameter, valueParam + startPos, sizeParameter);

			std::cout << "> Enter value for " << parameter << " : ";
			std::cin >> parameterValue;

			size_t sizeParameterValue = strlen(parameterValue) + 1;

			if (sizeParameterValue == sizeParameter) // %{username} with $[qwertyui] = $[qwertyui]
				strncpy(valueParam + startPos, parameterValue, strlen(parameterValue) + 1);
			else if (sizeParameterValue < sizeParameter) // %{username} with 123 = 123sername}
			{
				strncpy(valueParam + startPos, parameterValue, strlen(parameterValue)); // replace %{...} with user input

				size_t difference = sizeParameter - sizeParameterValue; // size difference between %{...} and uset input
				size_t offSet = startPos + sizeParameterValue;	// end of user input and start of left over symbols of %{...}
				strcpy(valueParam + offSet - 1, valueParam + offSet + difference); // shift symbols after %{...} to the left
			}
			else if (sizeParameterValue > sizeParameter) // %{years} with 123456789 = 123456789
			{
				size_t difference = sizeParameterValue - sizeParameter;
				size_t newSize = strlen(valueParam) + difference;
				char* temp = new char[newSize];

				strcpy(temp, valueParam); // copy valueParam to temp

				size_t offSet = startPos + sizeParameterValue;	// end of user input and start of left over symbols of %{...}
				//strncpy(temp + , valueParam, strlen(valueParam));

				strncpy(temp + startPos, parameterValue, strlen(parameterValue)); // replace %{...} with user input
				
				delete[] valueParam;
				valueParam = new char[newSize];
				strcpy(valueParam, temp); // copy temp valueParam

				delete[] temp;
			}
			//else if (sizeParameterValue > sizeParameter) // %{username} with 1234567890qwerty = 1234567890qwerty
			//{
			//	size_t offSet = sizeParameterValue - sizeParameter;
			//	strncpy(valueParam + startPos, parameterValue, strlen(parameterValue));
			//}
		}

		std::cout << valueParam << std::endl;
		delete[] valueParam;
		valueParam = nullptr;
	}
	else
		std::cout << "> Key and value are nullptrs. Invalid input for at least one of them." << std::endl;
}

bool InterpolationPair::containSymbol(const char* str, char symbol) const
{
	size_t i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '{')
			return true;
		
		i++;
	}

	return false;
}