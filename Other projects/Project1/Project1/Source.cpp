#include<iostream>
#include "MyWindow.h"
using namespace std;

int main()
{
	cout << "Creating window ..." << endl;

	MyWindow* pWindow = new MyWindow();

	bool running = true;
	while (running)
	{
		if (!pWindow->ProcessMessages())
		{
			cout << "Closing window ..." << endl;
			running = false;
		}

		
	}

	delete pWindow;

	return 0;
}