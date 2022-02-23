#include<iostream>
#include<cstring>

void calculateExpr(char* str)
{
	bool isNegative = false;
	int sum = 0;

	char digit[6];
	int i = 0;

	while (*str) // onetwominusonethree
	{

		digit[i] = *str;

		if (*str == 'm')
		{
			isNegative = true;
			digit[i] = '\0';
			i = 0;
		}
		else if (*str == 'p')
		{
			isNegative = false;
			digit[i] = '\0';
			i = 0;
		}

		i++;
		str++;

		std::cout << digit << std::endl;
	}
}

int main()
{
	//char compare[12][6] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "plus", "minus" };
	char buffer[1025];
	std::cin.getline(buffer, 1024); // onetwominusonethree    oneminustwothreeplusfourfivesix

	char* str = new char[strlen(buffer) + 1];
	strcpy(str, buffer);

	calculateExpr(str);

	delete[] str;

	return 0;
}