using namespace std;
#include <stdio.h>
#include <iostream>
int main()
{
	int number;
	cin>>number;
	int length=0;
	int tmp_number=number;
	while(tmp_number>0)
	{
		length++;
		tmp_number/=10;
	}
	int mask=1;
	for(int i=0;i<length;i++)
	{
		mask*=2;
	}
	mask--;
	int tmp_mask;
	int curr_number=0;
	for(int cmask=0;cmask<=mask;cmask++)
	{
		curr_number=0;
		tmp_number=number;
		tmp_mask=cmask;
		while(tmp_number>0)
		{
			if(tmp_mask%2==1)
			{
				curr_number*=10;
				curr_number+=tmp_number%10;
			}
				tmp_mask/=2;
				tmp_number/=10;
		}
	//	if(curr_number==number)
	//	{
			cout<<curr_number<<" ";
	//	}
	}
	
}
