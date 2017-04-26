using namespace std;
#include <stdio.h>
#include <iostream>
int main()
{
	int perm_number;
	cin>>perm_number;
	int length=0;
	int tmp_number=perm_number;
	while(tmp_number>0)
	{
		length++;
		tmp_number/=10;
	}	
	int perm_mask=1;
	for(int i=0;i<length;i++)
	{
		perm_mask*=2;
	}
	for(int curr_mask=0;curr_mask<perm_mask;curr_mask++)
	{
		tmp_number=perm_number;
		int curr_gen_number=0;
		int tmp_mask=curr_mask;
		while(tmp_number>0)
		{
			if(tmp_mask%2==1)
			{
				curr_gen_number=curr_gen_number*10+tmp_number%10;
			}
			tmp_number/=10;
			tmp_mask/=2;
		}
		cout<<curr_gen_number<<" ";
	}
}
