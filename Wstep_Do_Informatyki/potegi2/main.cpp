using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int number;
	cin>>number;
	int tmp_number=number;
	int length=0;
	while(tmp_number>0)
	{
		length++;
		tmp_number/=10;
	}
	int last_digit=number%10;
	tmp_number=number;
	int prev_digit=last_digit;
	tmp_number/=10;
	int sum=0;
	int power;
	while(tmp_number>0)
	{
		power=1;
		for(int i=0;i<prev_digit;i++)
		{
			power*=tmp_number%10;
		}
		sum+=power;
		prev_digit=tmp_number%10;
		tmp_number/=10;
	}
		power=1;
		for(int i=0;i<prev_digit;i++)
		{
			power*=last_digit%10;
		}
			sum+=power;
			cout<<sum;
}
