using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	while(true)
		{
	long n;
    cin>>n;
	long num[n];
	long currstart;
	long currend;
	long middleindex;
	for(long i=0;i<n;i++)
	{
		cin>>num[i];
	}
		currend=n-1;
		currstart=1;
		while(true)
		{
			
			middleindex=(currend+currstart)/2;
			if(currend<=currstart)
			{
				if(num[currend]>num[currend-1])
				{
				cout<<num[currend];
				}
				else
				{
				cout<<num[currend-1];
				}
				break;
			}
			if(num[middleindex-1]<num[middleindex])
			{
				currstart=middleindex+1;
				continue;
			}else if(num[middleindex-1]>num[middleindex])
						{
				currend=middleindex-1;
				continue;
			}
		}
		}
	return 0;
}
