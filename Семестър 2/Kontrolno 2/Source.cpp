#include<iostream>
#include"TrainTravel.h"
#include"CarTravel.h"
#include"CombinedTrip.h"
using namespace std;

int main()
{
	//char arr2[3][2] = { "1","2"};
	unsigned arr1[] = {1,2,3,4,5};

	TrainTravel train("Line 1", 10);
	CarTravel car(arr1, 1, 5);

	train.print();
	car.print();

	//CombinedTrip trip("Line 1", 10, arr1, 1, 5, arr2, 2, 1);


	return 0;
}