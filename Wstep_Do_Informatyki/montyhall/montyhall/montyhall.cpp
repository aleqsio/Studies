// montyhall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <iostream>
using namespace std;
int gdoor() //returns a number representing one of the doors (1-3)
{
	return rand() % 3 + 1;
}
bool gpick()//returns a random boolean
{
	return rand() % 2 == 0;
}
bool testcase(bool switched)//switched is used to signify action taken by the contestant
{
	int cardoor = gdoor();//witch of the doors contains the car
	int doorpicked = gdoor();//witch of the doors is first picked by the contestant

	int doorshown = gdoor();//this segment of code chooses one of the doors not chosen and not containing a car as a door shown
	while(doorshown == cardoor || doorshown == doorpicked)
	{
		doorshown = gdoor();
	}

	int dooroption=1;//this segment finds the door the contestant may choose to switch to
	while((doorpicked == dooroption || doorshown == dooroption))
	{ 
		dooroption++;
	}
	//based on the parameter may switch to that door
	if (!switched)
	{
		return doorpicked == cardoor;
	}
	return dooroption == cardoor;//checks if contestant won the car
}

int main()
{
	srand(time(0));
	unsigned long successswitched=0;
	unsigned long successunswitched=0;
	for (unsigned long i = 0; i < 10000000; i++)//tallies the results
	{
		if (testcase(true))
			successswitched++;
		if (testcase(false))
			successunswitched++;
	}
	cout<<endl << successswitched << "switched  " << successunswitched << "unswitched, ratio:";//displays the count of games won in either scenario...
	float f = (float)successswitched / successunswitched;
	cout << f;//...and their ratio
    return 0;
}

