using namespace std;
#include <stdio.h>
#include <iostream>
#include <cmath>
int main()
{
	int n,i,s;
	const int l=1000;
	const double sqrt_five_plus_one_div_two=1.61803398875;
	const double one_div_sqrt_five=0.4472135955;
	double pow=sqrt_five_plus_one_div_two;
	for(n=1;n<=l;n++)
	{
	cout<<(long)(pow*one_div_sqrt_five+0.5)<<"\n";
	pow=pow*sqrt_five_plus_one_div_two;
	}
}
	
