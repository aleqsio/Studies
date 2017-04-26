#include <stdio.h>
#include <iostream>
using namespace std;
bool compute(int*,int,int,int);
int main()
{
	int weight,num,*sizes;
	cin>>weight>>num;
	sizes = new int[num];
	for(int i=0;i<num;i++)
	{
		cin>>*(sizes+i);
	}
	compute(sizes,num,0,weight);
}
bool compute(int* sizes,int num,int curr,int weight)
{
	if(curr>num-1)
	{
		return false;
	}
	if(weight==0)
	{
	return true;
	}else if(weight<0)
	{
		return false;
	}
	if(compute(sizes,num,curr+1,weight-sizes[curr]))
	{
		cout<<curr<<":";
		cout<<sizes[curr]<<" ";
		return true;
	}
	return compute(sizes,num,curr+1,weight);
}

