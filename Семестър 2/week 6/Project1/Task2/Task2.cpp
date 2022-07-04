#include<iostream>
using namespace std;

class Player
{
public:
	Player()
	{
		name = new char[1];
		strcpy_s(name, 1, "\0");

		number = 0;
		coefficient = 0;
	}

	Player(const char* nameParam, const unsigned int numberParam, const double coefficientParam)
	{
		unsigned int size = strlen(nameParam) + 1;
		name = new char[size];
		strcpy_s(name, size, nameParam);

		number = numberParam;
		coefficient = coefficientParam;
	}

	Player(const Player& source)
	{
		unsigned int size = strlen(source.name) + 1;
		name = new char[size];
		strcpy_s(name, size, source.name);

		number = source.number;
		coefficient = source.coefficient;
	}

	Player& operator = (const Player& source)
	{
		if (this == &source)
			return *this;

		delete[] name;

		unsigned int size = strlen(source.name) + 1;
		name = new char[size];
		strcpy_s(name, size, source.name);

		number = source.number;
		coefficient = source.coefficient;

		return *this;
	}

	~Player()
	{
		delete[] name;
	}

private:
	char* name;
	unsigned int number;
	double coefficient;
};

class FootballTeam
{
public:
	FootballTeam(unsigned int sizeParam = 0)
	{
		size = sizeParam;
		players = new Player[size];
	}

	FootballTeam(const FootballTeam& source)
	{

	}

	FootballTeam& operator = (const FootballTeam& source)
	{

	}

	~FootballTeam()
	{

	}

private:
	Player* players;
	unsigned int size;
};

int main()
{
	return 0;
}

/*
�� �� ��������� ����������� �����������.
�� �� ��������� operator++, ����� ��������� ����������� �� ����� ���� �� ����� ����� � 1.
�� �� ������ �����, ����� ����� ����������� �� ����� ���� �� ����� (������ ������������� �� ������������� �� ����� ���� �� ������������ ��).
�� �� ��������� operator+, ����� ����� ��� ������, ���� ������ 11-�� ���-����� ������ � �� ����� �� ���� ���������� � ��������, � ����� ������.
�� �� ��������� ���������� ������� game, ����� �� ������ �� ������������� �� ����� ���� �� ��� ������, �������� ��������� � ��������� ���� �� 
�������� �� ������ � ���� �� �������� �� ������ �����.
*/