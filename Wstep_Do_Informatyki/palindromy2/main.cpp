using namespace std;
#include <iostream>
#include <stdio.h>

int main()
{
	int number;
	cin>>number;
	int new_number=0;
	int tmp_number=number;
	while(tmp_number>0)
	{
		new_number*=10;
		new_number+=tmp_number%10;
		tmp_number/=10;
	}
	cout<<new_number;
}
