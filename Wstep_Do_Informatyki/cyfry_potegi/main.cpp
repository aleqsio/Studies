using namespace std;
#include <stdio.h>
#include <iostream>
#include <math.h>
int main()
{
	int number;
	cin>>number;
	int tmp_number=number;
	int last_digit;
	int prev_digit;
	int sum=0;
	int power=1;
	last_digit=tmp_number%10;
	while(tmp_number>9)
	{
		prev_digit=tmp_number%10;
		tmp_number/=10;
		power=1;
		for(int i=0;i<prev_digit;i++)
		{
			power*=tmp_number%10;
		}
		sum+=power;
	}
	power=1;
	for(int i=0;i<tmp_number%10;i++)
		{
			power*=last_digit;
		}
	sum+=power;
	cout<<sum;
}
