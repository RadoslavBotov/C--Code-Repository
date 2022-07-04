#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include<doctest.h>
#include<iostream>
using namespace std;

int main()
{
	int** arr = new int* [5];
	int a = 1;
	int b = 2;
	int c = 3;

	arr[0] = nullptr;
	arr[1] = &a;
	arr[2] = &b;
	arr[3] = nullptr;
	arr[4] = &c;

	for (int i = 0; i < 5; i++)
		(arr[i] == nullptr) ? cout << "nullptr" << endl : cout << arr[i] << " = " << *arr[i] << endl;

	/*char buffer;

	cin >> buffer;
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "> Entered wrong input" << endl;
			cin >> buffer;
		}
		if (!cin.fail())
			break;
	}

	cout << buffer;*/

	return 0;
}

ostream& operator<<(ostream&, const Aaa&)
{
	// TODO: insert return statement here
}
