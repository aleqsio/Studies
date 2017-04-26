using namespace std;
#include <stdio.h>
#include <iostream>
#include <string.h>

void generate(string s,int cnt)
{
	if(cnt<14)
	{
		generate(s+"A",cnt+1);
		generate(s+"B",cnt+1);
	}else
	{
		cout<<s<<endl;
	}
}

int main()
{
	generate("",0);
}
