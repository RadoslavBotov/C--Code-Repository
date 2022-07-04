#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void catt(ifstream& file)
{
	char str[10];
	while (file.get(str, 10))
	{
		cout << str;
		if (file.peek() == '\n')
			cout << char(file.get());
	}
	
	cout << endl;

	file.clear();
	file.seekg(0, ios::beg);
}

int wc(ifstream& file)
{
	int wordCount = 0;

	char ch;
	while (file.get(ch))
	{
		if (ch == ' ' || ch == '\n')
			wordCount++;
	}

	file.clear();
	file.seekg(0, ios::beg);

	return wordCount;
}

int main()
{
	ifstream file1("Test1.txt");

	catt(file1);
	cout << wc(file1) << endl;

	file1.close();

	return 0;
}