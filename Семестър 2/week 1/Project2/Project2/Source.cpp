/*#include<iostream>
using namespace std;

const int MAX_LENGTH = 128;

enum SwordType
{
	SHARP, HEAVY_DAMAGE, COMPACT,
};

struct Sword
{
	char* mModel;
	unsigned mStrength;
	SwordType mType;
	unsigned mYearOfProduction;
};

struct Warrior
{
	char* mName;
	unsigned mAge;
	Sword mSword;
};

void initializeSword(Warrior& warrior)
{
	warrior.mSword.mModel = new char[MAX_LENGTH];

	cout << "> Input sword model: ";
	cin >> warrior.mSword.mModel;
	
	cout << "> Input sword strength: ";
	cin >> warrior.mSword.mStrength;

	cout << "> Input sword age of production: ";
	cin >> warrior.mSword.mYearOfProduction;

	int typeCode;
	cout << "> Input sword type:\n";
	cout << "> 1 - SHARP\n";
	cout << "> 2 - HEAVY_DAMAGE\n";
	cout << "> 3 - COMPACT\n";
	cin >> typeCode;

	switch (typeCode)
	{
	case 1: 
		warrior.mSword.mType = SHARP; 
		break;
	case 2:
		warrior.mSword.mType = HEAVY_DAMAGE;
		break;
	case 3:
		warrior.mSword.mType = COMPACT;
		break;
	default:
		cout << "Not a suported type.";
		break;
	}
	cout << endl;
}

void initializeWarrior(Warrior& warrior)
{
	warrior.mName = new char[MAX_LENGTH];
	cout << "> Input warrior name: ";
	cin >> warrior.mName;

	cout << "> Input warrior age: ";
	cin >> warrior.mAge;

	initializeSword(warrior);
}

void printSword(const Sword& sword)
{
	cout << sword.mModel << endl;
	cout << sword.mStrength << endl;
	
	switch (sword.mType)
	{
	case SHARP:
		cout << "Sharp\n";
		break;
	case HEAVY_DAMAGE:
		cout << "Heacy damage\n";
		break;
	case COMPACT:
		cout << "Compact\n";
		break;
	default:
		break;
	}

	cout << sword.mYearOfProduction << endl;
}

void printWarrior(const Warrior& warrior)
{
	cout << warrior.mName << endl;
	cout << warrior.mAge << endl;
	printSword(warrior.mSword);
}

void killWarrior(Warrior& warrior)
{
	delete[] warrior.mName;
	delete[] warrior.mSword.mModel;
}

int main()
{
	Warrior warrior;

	initializeWarrior(warrior);

	printWarrior(warrior);

	killWarrior(warrior);

	return 0;
}*/