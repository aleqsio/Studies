using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	long n,k;
    cin>>n;
	long num[n];
	cin>>k;
	long currnum;
	unsigned long currstart;
	unsigned long currend;
	unsigned long middleindex;
	unsigned long maxindex=0;
	cin>>num[0];
	for(long i=1;i<n;i++)
	{
		cin>>num[i];
		if(num[i-1]<num[i])
		{
			maxindex=i;
		}
	}
	for(long i=0;i<k;i++)
	{
		cin>>currnum;
		if(maxindex==0)
		{
			currstart=0;
			currend=n-1;
		}
		else if(currnum>=num[0])
		{
			currend=minindex;
			currstart=0;
		}else
		{
			currstart=minindex;
			currend=n-1;
		}
		while(currend!=currstart)
		{
			middleindex=(currend+currstart)/2;
			if(num[middleindex]<currnum)
			{
				currstart=middleindex+1;
			}else
			{
				currend=middleindex;
			}
		
		}
            if(num[currstart]==currnum)
{ 
              cout<<currstart+1<<" ";
            }else
                {
                cout<<"-1 ";
            }
	}
	
	return 0;
}