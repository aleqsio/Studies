using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	long long counter=25260000000;
	long long curr_number;
	short last_digit;
	short prev_digit;
	int power;
	long long sum;
	
	while(counter>0)
	{
		curr_number=counter;
		last_digit=curr_number%10;
		prev_digit=last_digit;
		curr_number/=10;
		sum=0;
		while(curr_number>0 && sum<=counter)
		{
			power=1;
			if(curr_number%10!=0)
		{
			for(int i=0;i<prev_digit;i++)
			{
				power=power*=curr_number%10;
			}
		}
			sum+=power;
			prev_digit=curr_number%10;
			curr_number/=10;
		}
		if(sum<=counter)
		{
		power=1;
		if(last_digit!=0)
		{
			for(int i=0;i<prev_digit;i++)
			{
				power=power*=last_digit;
			}
		}
			sum+=power;
		if(counter==sum)
		{
			cout<<"\n\n\n"<<counter<<" - liczba";
			counter=-1;
		}
		}
		
		if(counter%10000000==0)
		{
				cout<<"|"<<counter<<"|";
		}
		counter++;
	}
}
