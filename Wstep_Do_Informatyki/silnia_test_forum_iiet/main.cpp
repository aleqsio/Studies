
#include <iostream>

int main()
{
	long long int multi;
	
	const int max=10;
	int num[max]={};
	
	num[0]=1;
	for (int n =1; n<max;n++) num[n]=0;
	
	int fcrl; //factorial
	std::cout << "Podaj silnie: "; 
	std::cin  >> fcrl;
	
	for (;fcrl >1; fcrl--)
	{
		int max_temp = max-1;
		int xx;
		
		for (;max_temp>=0;max_temp--)
		{
			multi = num[max_temp]*fcrl;
			xx = max_temp+1;
			
			num[max_temp] = multi%100;
			multi/=100;
			
			//num_temp = num[max_temp]/10;
			//num[max_temp] = num[max_temp]%10;
			
			while (multi>0 && xx<max)
			{
				num[xx]+=multi%100;
				multi/=100;
				xx++;
			}
			
			//if (xx<max) std::cout << "Przeciążenie buffowa\n";
		}
		
		for (int n=max-1; n>=0; n--)
                	std::cout << num[n];//0;
		
		std::cout << "\n";
		
	}
	for (int n=max-1; n>=0; n--)
		std::cout << num[n];//0;
        
	std::cout << "\n";
	
	return 0;
}