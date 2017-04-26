#include <stdio.h>
void readstr(char* str)
{
	scanf("%s", str);
}
void printstr(char *str)
{
	int init = 0;
	int len = lengthof(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] != '0') init = 1;
		if(init)	printf("%c", str[i]);
	}
	printf("\n");
}
int lengthof(char *str)
{
	int len;
	for (len = 0; len < 200 && str[len] != '\0'; len++);
	return len;
}
int pushback(char* str)
{
	int len = lengthof(str);
	for (int i = 0; i < len; i++)
	{
		str[(100 - len) + i] = str[i];
	}
	for (int i = 0; i < 100 - len; i++)
	{
		str[i] = '0';
	}
	return len;
}
add(char* main, char* summand)
{
	int tmp = 0;
	for (int i = 99; i >=0; i--)
	{
		tmp += (main[i] + summand[i] - 96);
		main[i] = (tmp%10)+48;
		tmp /= 10;
	}
}
multiply(char* result,char* f1, char* f2,int la,int lb)
{
	int tmp = 0;
	
	for (int i = 99; i >= 99-la; i--)
	{
		for (int j = 99; j >= 99 - lb; j--)
		{
			tmp = (f1[i]-48) * (f2[j]-48);
			result[i + j] = tmp % 10;
			if (i + 1 < 200) result[i + j + 1] = tmp / 10;
		}
	}
}
int main(void)
{
	char a[101];
	char b[101];
	char c[201];

	printf("Podaj pierwsza liczbe");
	readstr(a);

	printf("Podaj druga liczbe");
	readstr(b);

	c[0] = '\0';
	pushback(c);

	int la, lb;
	la=pushback(a);
	lb=pushback(b);

	//add(a, b);
	multiply(c, a, b,la,lb);
	printstr(c);

    return 0;
}

