#define _XOPEN_SOURCE
#define MIN	0
#define MAX 1
#define MINIMUM(x,y) x<y ? x : y
#include <stdio.h>
struct size {
	int x;
	int y;
};
void fill(int** t, struct size s)
{
	for (int i = 0; i < s.y; i++)
	{
		for (int j = 0; j < s.x; j++)
		{
			t[i][j] = MIN + rand() % (MAX - MIN + 1);
		}
	}
}
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
	struct size s1;
	s1.x = SZ;
	s1.y = SZ;
	struct size s2;
	s2.x = SZ;
	s2.y = SZ;
	int**a = create_two_dim_array(s1);
	int**b = create_two_dim_array(s2);
	fill(a, s1);
	fill(b, s2);
	print(a, s1);
	print(b, s2);
	printf("%d ", sum_diagonal(a, s1));
	printf("%d ", sum_under_diagonal(a, s1));
	struct size s3;
	s3.x = s2.x;
	s3.y = s1.y;
	int**c = create_two_dim_array(s3); //matrix multipication requires square array
	printf("\n\n\n");
	multiplyarray(a, b, c, s1, s2, s3);
	print(c, s3);

	return 0;
}

