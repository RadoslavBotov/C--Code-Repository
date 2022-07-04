#include<iostream>
using namespace std;

const int MAX_LENGTH = 128;

struct Owner
{
	char mFirstName[MAX_LENGTH] = "";
	char mFamilyName[MAX_LENGTH] = "";
	unsigned mAge = 0;
	char mCountry[MAX_LENGTH] = "";
};

struct BankAccount
{
	Owner owner;
	int mBalance = 0;
	int mTransactions[MAX_LENGTH];
	int mIndexTransactions = 0;
};

struct ListBankAccount
{
	BankAccount mAccounts[MAX_LENGTH];
	int mIndexAccounts = 0;
};

bool SameOwner(const Owner& ownerInfo, const Owner& person)
{
	if (strcmp(ownerInfo.mFirstName, person.mFirstName) == 0)
		if (strcmp(ownerInfo.mFamilyName, person.mFamilyName) == 0)
			return true;
	return false;
}

void printBalance(const ListBankAccount &system, const Owner &person)
{
	int netWorth = 0;
	bool match = true;

	for (int i = 0; i < system.mIndexAccounts; i++)
		if (SameOwner(system.mAccounts[i].owner, person))
		{
			match = false;
			netWorth += system.mAccounts[i].mBalance;

			cout << "> Balance: " << system.mAccounts[i].mBalance << endl;
			/*
			cout << "> Transactions: ";
			for (int j = 0; j < system.mAccounts[i].mIndexTransactions; j++)
				cout << system.mAccounts[i].mTransactions[j] << " ";
			cout << endl;
			*/
		}

	if (match) 
		cout << "No such account in system." << endl;

	cout << "> Net worth: " << netWorth << endl;
}

BankAccount getNthAccount(const ListBankAccount& system, const Owner& person, int n)
{
	int br = 0;

	for (int i = 0; i < system.mIndexAccounts; i++)
		if (SameOwner(system.mAccounts[i].owner, person))
		{
			br++;
			if (br == n)
				return system.mAccounts[i];
		}

	cout << "No such account. Created one." << endl;
	BankAccount empty;
	return empty;
}

enum Summary
{
	All,		// 0
	Positive,	// 1
	Negative	// 2
};

void printTransactions(const ListBankAccount& system, const Owner& person, int x, Summary type)
{
	BankAccount temp = getNthAccount(system, person, x);

	if (strcmp(temp.owner.mFirstName, "") == 0)
	{
		cout << "> Empty account." << endl;
		return;
	}

	cout << "> Transactions: ";

	switch (type)
	{
	case All:
		for (int j = 0; j < temp.mIndexTransactions; j++)
			cout << temp.mTransactions[j] << " ";
		break;
	case Positive:
		for (int j = 0; j < temp.mIndexTransactions; j++)
			if (temp.mTransactions[j] > 0)
				cout << temp.mTransactions[j] << " ";
		break;
	case Negative:
		for (int j = 0; j < temp.mIndexTransactions; j++)
			if (temp.mTransactions[j] < 0)
				cout << temp.mTransactions[j] << " ";
		break;
	default:
		cout << "> Error! No such type." << endl;
		break;
	}

	cout << endl;
}

int main()
{

	return 0;
}