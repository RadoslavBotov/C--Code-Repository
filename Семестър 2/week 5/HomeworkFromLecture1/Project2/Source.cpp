#include<iostream>
using namespace std;

class Command
{
private:
	char name;

public:
	Command(const char nameParam)
	{
		name = nameParam;
	}

	bool operator == (const char command)
	{
		return this->name == command;
	}

	char getName() const
	{
		return name;
	}

	void execute()
	{
		cout << "Command \""<< name <<"\" executed." << endl;
	}

	bool sameCommand(const char* listOfCommands) const
	{
		unsigned int len = strlen(listOfCommands);

		for (unsigned int i = 0; i < len; i++)
			if (listOfCommands[i] == name)
				return true;
		return false;
	}
};

class Program
{
private:
	Command** commands;
	unsigned int size;

	void allocateMemory(Command**& target, const unsigned int sizeParam)
	{
		target = new Command * [sizeParam];
	}

	void allocateMemory(Command**& target, const Program& source)
	{
		commands = new Command * [source.size];
		for (unsigned int i = 0; i < source.size; i++)
			commands[i] = source.commands[i];
	}

	void deleteMemory()
	{
		for (unsigned int i = 0; i < size; i++)
			delete commands[i];
		delete[] commands;
	}

	bool isSupportedCommand(const char command) const
	{
		for (unsigned int i = 0; i < size; i++)
			if ((*commands[i]) == command)
				return true;
		return false;
	}

	int getCommandIndex(const char command) const
	{
		for (unsigned int i = 0; i < size; i++)
			if ((*commands[i]) == command)
				return i;
	}

public:
	Program(const char* listOfCommands = "\0", const unsigned int sizeParam = 0)
	{
		size = strlen(listOfCommands);
		allocateMemory(commands, size);

		for (unsigned int i = 0; i < size; i++)
			commands[i] = new Command(listOfCommands[i]);
	}

	Program(const Program& source)
	{
		size = source.size;
		allocateMemory(commands, source);
	}

	Program& operator = (const Program& rhs)
	{
		if (this != &rhs)
		{
			deleteMemory();
			allocateMemory(commands, rhs.size);
			for (unsigned int i = 0; i < rhs.size; i++)
				commands[i] = rhs.commands[i];
		}
		return *this;
	}

	~Program()
	{
		deleteMemory();
	}

	void print() const
	{
		cout << "> List of supported commands:\n";
		for (unsigned int i = 0; i < size; i++)
			cout << commands[i]->getName() << " ";

		cout << "\n-----------------------------\n";
	}

	void executeCommandsFromList(const char* listOfCommands = "\0") const
	{
		unsigned int sizeOfList = strlen(listOfCommands);

		cout << "\n> List of commands: " << listOfCommands << "\n";

		for (unsigned int i = 0; i < sizeOfList; i++)
		{
			const char command = listOfCommands[i];

			if (isSupportedCommand(command))
				(*commands[getCommandIndex(command)]).execute();
			else
				cout << "Command \"" << command << "\" not supported!\n";
		}
	
		cout << "\n-----------------------------\n";

	}
	
	void executeSuportedCommands()
	{
		cout << "\n> Executing all supported commands:\n";

		for (unsigned int i = 0; i < size; i++)
			(*commands[i]).execute();

		cout << "\n-----------------------------\n";
	}
};



int main()
{
	char listOfCommands[] = "as.6$9>? _";
	Program p1(listOfCommands);

	p1.print();
	
	p1.executeCommandsFromList("<>?,./");

	p1.executeSuportedCommands();

	return 0;
}