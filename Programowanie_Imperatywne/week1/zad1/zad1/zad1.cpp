#define _XOPEN_SOURCE
#define MIN(x,y) (x<y ? x : y)
#define MAX(x,y) (x>y ? x : y)
#include <stdio.h>
struct size {
	int x;
	int y;
};
void print(int** t, struct size s)
{
	for (int i = 0; i < s.y; i++)
	{
		for (int j = 0; j < s.x; j++)
		{
			printf("%d,", t[i][j]);
		}
		printf("\n");
	}
}
void read(int**F, struct size s1)
{
	for (int i = 0; i < s1.x; i++)
	{
		for (int j = 0; j < s1.y; j++)
		{
			scanf("%d", &F[i][j]);
		}
	}
}
int getsum(int**F,int x,int y, struct size s1, int r)
{
	int sum = 0;
	for (int i = MIN(0, x - r); i < MAX(s1.x, x + r); i++)
	{
		for (int j = MIN(0, y - r); j < MAX(s1.y, y + r); j++)
		{
			sum += F[i][j];
		}
	}
}
int** create_two_dim_array(struct size s)
{
	int** a = malloc(sizeof(int*)*s.y);
	for (int i = 0; i < s.x; i++)
	{
		a[i] = malloc(sizeof(int)*s.x);
	}
	return a;
}
int main(void)
{
	int n,r;
	scanf("%d %d", &n,&r);
	struct size s1;
	s1.x = n;
	s1.y = n;
	int**F = create_two_dim_array(s1);
	read(F, s1);
	print(F, s1);
	return 0;
}

