using namespace std;
#include <stdio.h>
#include <iostream>
int main()
{
	int number;
	cin>>number;
	int length=0;
	int mask=1;
	int tmp_mask;
	int tmp_number;
	int gen_number;
	tmp_number=number;
	while(tmp_number>0)
	{
		tmp_number/=10;
		length++;
		mask*=2;
	}
	
	for(int curr_mask=0;curr_mask<mask;curr_mask++)
	{
		gen_number=0;
		tmp_mask=curr_mask;
		tmp_number=number;
		while(tmp_number>0)
		{
			if(tmp_mask%2==1)
			{
				gen_number=gen_number*10+tmp_number%10;
			}
			tmp_number/=10;
			tmp_mask/=2;
			
		}
		tmp_number=gen_number;
		gen_number=0;
		while(tmp_number>0)
		{
			gen_number*=10;
			gen_number+=tmp_number%10;
			tmp_number/=10;
		}
		cout<<gen_number<<" ";
	}

}
