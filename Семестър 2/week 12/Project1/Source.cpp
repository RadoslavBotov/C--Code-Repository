#include<iostream>
#include<fstream>
#include"Room.h"
#include"ConferenceRoom.h"
#include"OfficeRoom.h"
#include"RestRoom.h"
#include"Building.h"
using namespace std;

int main()
{
	ConferenceRoom c1("Conference_room", 1, 1, 5);
	OfficeRoom o1("Office_room", 0, "Radoslav");
	RestRoom r1("Rest_room", 1, 10, 1, "FMI");

	Building b1;
	b1.addRoom(&c1);
	b1.addRoom(&o1);
	b1.addRoom(&r1);

	ofstream os("testFile.txt");
	b1.print(os);
	os.close();

	return 0;
}