using namespace std;
#include <stdio.h>
#include <iostream>
	double a;
	const double limit=100;
	const double inv=0.01;
	int  medebug()
{
			cout<<"\nA"<<a-(a-((double)((int)a)));
			cout<<"\nB" <<((a-((double)((int)a)))*limit);
}
int main()
{
	a=1;
	a=a+(1*inv);
	while (a+(a-(( double)((int)a)))*(limit-1)<limit)
	{
		//b=a+b;
		a+=((int)(a-(a-((double)((int)a)))+0.1))*inv;
		//	a=b-a;
		a=(((a-((int)(a+0.1)))*limit))-((double)((int)(a+0.1)))+(a-((int)(a+0.1)));
	
		cout<<"\n"<<(int)(((a-((int)a))*limit)+0.1)<<"\n";
			medebug();
	}
}
