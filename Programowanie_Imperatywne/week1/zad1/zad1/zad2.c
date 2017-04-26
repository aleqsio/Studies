#include <stdio.h>
void readstr(char* str)
{
	scanf("%s", str);
}
void printstr(char *str)
{
	int init = 0;
	for (int i = 0; i < 100; i++)
	{
		if (str[i] != '0') init = 1;
		if(init)	printf("%c", str[i]);
	}
	printf("\n");
}
int lengthof(char *str)
{
	int len;
	for (len = 0; len < 100 && str[len] != '\0'; len++);
	return len;
}
void pushback(char* str)
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
int main(void)
{
	char a[101];
	char b[101];

	printf("Podaj pierwsza liczbe");
	readstr(a);

	printf("Podaj druga liczbe");
	readstr(b);

	pushback(a);
	pushback(b);

	add(a, b);

	printstr(a);

    return 0;
}

