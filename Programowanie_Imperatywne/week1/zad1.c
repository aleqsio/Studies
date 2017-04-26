#include <stdio.h>
#define MAX 100
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
		if (init)	printf("%c", str[i]);
	}
	printf("\n");
}
void setzero(int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}
int lengthof(char *str)
{
	int len;
	for (len = 0; len < 2 * MAX && str[len] != '\0'; len++);
	return len;
}
int pushback(char* str, int length)
{
	int len = lengthof(str);
	for (int i = 0; i < len; i++)
	{
		str[(MAX - len) + i] = str[i];
	}
	for (int i = 0; i < length - len; i++)
	{
		str[i] = '0';
	}
	return len;
}

multiply(char* result, char* f1, char* f2, int la, int lb)
{
	int arr[MAX * 2];
	setzero(arr, MAX * 2);
	for (int i = MAX - 1; i >= MAX - 1 - la; i--)
	{
		for (int j = MAX - 1; j >= MAX - 1 - lb; j--)
		{
			int tmp = (f1[i] - 48) * (f2[j] - 48);
			arr[(i + j + 1)] += tmp % 10;
			if (i + j < 2 * MAX) arr[i + j] += tmp / 10;
		}
	}
	for (int i = 2 * MAX - 1; i >0; i--)
	{
		arr[i - 1] += (arr[i]) / 10;
		arr[i] = (arr[i]) % 10;
	}
	for (int i = 0; i < MAX * 2; i++)
	{
		result[i] = '0' + arr[i];
	}
}
int main(void)
{

	char a[MAX + 1];
	char b[MAX + 1];

	char c[2 * MAX + 1];


	printf("Podaj pierwsza liczbe");
	readstr(a);

	printf("Podaj druga liczbe");
	readstr(b);


	int la, lb;
	la = pushback(a, MAX);
	lb = pushback(b, MAX);

	multiply(c, a, b, la, lb);
	printstr(c);

	return 0;
}

