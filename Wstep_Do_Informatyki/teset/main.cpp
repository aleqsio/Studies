using namespace std;
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>    
int main()
{
srand(time(0));
int size=1;
while(size<40)
{
	int curr=0;
	bool mybl=true;
	cout<<size<<" 10 ";
	for(int i=0;i<size;i++)
	{
		curr++;
		
		while(rand()%7<5)
		{
			curr++;
		}
		if(rand()%7>5)
		{
			mybl=false;
		}
		if(mybl)
		{
			cout<<curr+1000<<" ";
		}else
		{
			cout<<curr<<" ";
		}
		
	}
		cout<<endl;
	if(rand()%13==0)
	{
		size++;
	}
}
	
	return 0;
}