using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
double test=1;
double test_o;
while (test!=0)
{
	test_o=test;
	test=test/2;
	cout<<test;
}
cout<<"WYNIK "<<test_o;
}
