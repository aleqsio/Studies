using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int perm_number;
	cin>>perm_number;
	int tmp_number=perm_number;
	for(int dzielnik=2;dzielnik*dzielnik<=perm_number;dzielnik++)
	{
		while(tmp_number%dzielnik==0)
		{
			cout<<dzielnik<<" ";
			tmp_number/=dzielnik;
		}
	}
}
