#include<iostream>
using namespace std;

class Owner
{
private:
	char* firstName;
	char* middleName;
	char* lastName;
	unsigned EGN[10];

	static void strAllocate(char*& target, const char* source)
	{
		target = new char[strlen(source)];
		strcpy(target, source);
	}

	static void EgnAllocate(unsigned target[10], const unsigned source[10])
	{
		for (int i = 0; i < 10; i++)
			target[i] = source[i];
	}

public:
	Owner(const char* firstName, const char* middleName, const char* lastName, unsigned EGN[10])
	{
		strAllocate(this->firstName, firstName);
		strAllocate(this->middleName, middleName);
		strAllocate(this->lastName, lastName);

		EgnAllocate(this->EGN, EGN);
	}

	~Owner()
	{
		delete[] firstName;
		delete[] middleName;
		delete[] lastName;
	}

	char *GetFirstName() const
	{
		return firstName;
	}

	char* GetMiddleName() const
	{
		return middleName;
	}

	char* GetLastName() const
	{
		return lastName;
	}

	unsigned* GetEGN()
	{
		return EGN;
	}
};

class Transaction
{
private:
	int index = 0;
	int transactions[100];

public:
	Transaction(int index, int transactions[])
	{
		this->index = index;

		for (int i = 0; i < this->index; i++)
			this->transactions[i] = transactions[i];
	}
};

class BankAccount
{
private:
	int balance;
	int IBAN;
	Owner owner;
	Transaction transaction;

public:
	BankAccount(int balance, int IBAN, Owner owner, Transaction transaction)
	{

	}

	~BankAccount()
	{

	}
};

int main()
{

	return 0;
}