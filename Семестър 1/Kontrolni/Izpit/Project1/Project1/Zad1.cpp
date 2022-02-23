#include<iostream>
#include<cstring>

bool validInput(char *buffer)
{
	while (*buffer)
	{
		if (*buffer != 'g' && *buffer != 'y' && *buffer != 'r')
			return false;
		buffer++;
	}
	return true;
}

void inputBuffer(char *buffer)
{
	do
	{
		std::cout << "> Input str: ";
		std::cin.getline(buffer, 1024);
	} while (!validInput(buffer));
}

void longestPath(char* str)
{
	int longestPath = 0;
	int currentPath = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		while (*str)
		{
			while (*str == 'g')
			{
				currentPath++;
				str++;
			}

			if (*str == 'y')
			{
				while (*str != 'g')
				{
					if (*str == '\0')
					{
						if (currentPath > longestPath)
						{
							longestPath = currentPath;
							currentPath = 0;
						}
						break;
					}
					str++;
				}
				currentPath++;
			}

			if (*str == 'r')
			{
				if (currentPath > longestPath)
				{
					longestPath = currentPath;
					currentPath = 0;
				}
				str++;
			}
		}
	}

	std::cout << "Longest path possible: " << longestPath << std::endl;
}

int main()
{
	char buffer[1025];
	inputBuffer(buffer);

	char* str = new char[strlen(buffer) + 1];
	strcpy(str, buffer);

	longestPath(str);

	delete[] str;

	return 0;
}