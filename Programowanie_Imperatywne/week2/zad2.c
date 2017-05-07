#define _XOPEN_SOURCE 700
#define MIN(x,y) (x<y ? x : y)
#define MAX(x,y) (x>y ? x : y)
#include <stdio.h>
#include <stdlib.h>

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
            t[i][j] = 0;
        }
    }
}
void read(int** t,struct size s)
{
    for (int i = 0; i < s.y; i++)
    {
        for (int j = 0; j < s.x; j++)
        {
            scanf("%d", &t[i][j]);
        }
    }
}
void print(int** t, struct size s)
{
    for (int i = 0; i < s.y; i++)
    {
        for (int j = 0; j < s.x; j++)
        {
            printf("%d ", t[i][j]);
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
void populate(int** res,int** t,struct size s,int r)
{
    for (int i = 0; i < s.y; i++)
    {
        for (int j = 0; j < s.x; j++)
        {
            for (int k = MAX(0,i-r); k <= MIN(i+r,s.y-1); k++)
            {
                for (int l = MAX(0,j-r); l <= MIN(j+r,s.x-1); l++)
                {
                  res[k][l]+=t[i][j];
                }
            }
        }
    }
}
int main(void)
{
    struct size s;
    int r;
    scanf("%d %d",&s.x,&r);
    s.y=s.x;
    int** arr = create_two_dim_array(s);
    int** res = create_two_dim_array(s);
    read(arr,s);
    fill(res,s);
    populate(res,arr,s,r);
    print(res,s);
    return 0;
}

