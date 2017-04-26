using namespace std;
#include <stdio.h>
#include <iostream>
int main()
{
	int number;
	cin>>number;
	int tmp_number=number;
	int rev_number=0;
	while(tmp_number>0)
	{
		rev_number=rev_number*10+tmp_number%10;
		tmp_number/=10;
	}
	cout<<rev_number;
	if(number==rev_number)
	{
		cout<<number;
	}
}
