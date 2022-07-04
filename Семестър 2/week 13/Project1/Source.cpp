#include<iostream>
#include"BwLaser.h"
#include"ColorLaser.h"
#include"ColorInkjet.h"
#include"PrinterStorage.h"
using namespace std;

void help()
{
	cout << "Please make your choice:\n";
	cout << "1 - Show the entire Print - IT catalog\n";
	cout << "2 - Add a new BW laser printer\n";
	cout << "3 - Add a new color laser printer\n";
	cout << "4 - Add a new ink-jet printer\n";
	cout << "5 - Show the entire Print - IT catalog sorted by type of printer\n";
	cout << "6 - Show the entire Print - IT catalog sorted by brand(alphabetically)\n";
	cout << "7 - Write to file\n";
	cout << "8 - Help\n";
	cout << "9 - Stop the program\n";
}

int main()
{
	PrinterStorage storage;
	bool runDialog = true;
	unsigned command;

	help();

	while (runDialog)
	{
		cout << "> Enter command: ";
		cin >> command;

		switch (command)
		{
		case 1:
			storage.print();
			break;

		case 2:
			//storage.addBwLaserPrinter();
			break;

		case 3:
			//storage.addColorLaserPrinter();
			break;

		case 4:
			//storage.addColorInkjetPrinter();
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		case 8:
			help();
			break;

		case 9:
			runDialog = false;
			break;

		default:
			cout<< "No such command.\n";
			break;
		}


		cout << endl;
	}

	cout << "> Program stopped.";

	return 0;
}