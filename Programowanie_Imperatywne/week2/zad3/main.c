#define _XOPEN_SOURCE 700
#define MIN(x,y) (x<y ? x : y)
#define MAX(x,y) (x>y ? x : y)
#include <stdio.h>
#include <stdlib.h>

struct matrix {
    int n;
    int r;
    double** AB;
    double* X;
};
struct size {
   int x,y;
};
void read(struct matrix *m)
{
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->r; j++)
        {
            scanf("%lf", &m->AB[j][i]);
        }
    }
    for (int i = 0; i < m->n; i++)
    {

            scanf("%lf", &m->AB[m->r][i]);
    }
}
double** create_two_dim_array(struct size s)
{

    double** a = malloc(sizeof(double*)*s.y);
    for (int i = 0; i < s.x; i++)
    {
        a[i] = malloc(sizeof(double)*s.x);
    }
    return a;
}
void initialise(struct matrix *m)
{
struct size s;
    s.x=m->r+1;
    s.y=m->n;
    m->AB=create_two_dim_array(s);
    m->X=malloc(sizeof(double)*m->r);
}

void print(struct matrix *m)
{
    for (int i = 0; i < m->n; i++)
    {
        for (int j = 0; j < m->r+1; j++)
        {
            printf("%lf ", m->AB[j][i]);
        }
        printf("\n");
    }
    printf("--->\n");
}
int isemptybelow(struct matrix *m,int y,int x)
{
    int res=1;
    for(int i=y;i<m->n;i++)
    {
        if(m->AB[x][i]) res=0;
    }
    return res;
}
void swapwithnext(struct matrix *m,int y,int x)
{
    for(int i=y;i<m->n;i++)
    {
        if(m->AB[x][i])
        {
            for(int a=0;a<m->r+1;a++)
            {
                double tmp=m->AB[a][y];
                m->AB[a][y]=m->AB[a][i];
                m->AB[a][i]=tmp;
            }
            i=m->n;
        }
    }
}
void zerorow(struct matrix *m,int y,int x,int base)
{
    double mult=(m->AB[x][y])/m->AB[x][base];


            for(int a=0;a<m->r+1;a++)
            {
                m->AB[a][y]-=m->AB[a][base]*mult;
            }

}
int getrank(struct matrix *m,int complete)
{
    int rank=0;
    for(int y=0;y<m->n;y++)
    {
        for(int x=0;x<(complete ? m->r+1:m->r);x++)
        {
            if(m->AB[x][y]) rank=y;
        }
    }
    return rank+1;
}
void calculate(struct matrix *m)
{
    int y=0;
    for (int i = 0; i < m->r; i++) {
        print(m);
        if(!isemptybelow(m,y,i)) {
            if(m->AB[i][y]==0)
            {
                swapwithnext(m,y,i);
            }
            for (int j = y+1; j < m->n; j++) {
                zerorow(m,j,i,y);
            }
            y++;
        }
    }
}
void result(struct matrix *m)
{
    printf("rzad macierzy A: %d, rzad macierzy AB: %d\n",getrank(m,0),getrank(m,1));
    if(getrank(m,0)<getrank(m,1)) printf("Brak rozwiazan macierzy");
    else if(getrank(m,1)<m->r) printf("Nieskonczenie wiele rozwiazan zaleznych od %d parametrow",m->r-getrank(m,1));
    else
    {
        printf("Jedno rozwiazanie:");
        for(int i=m->n-1;i>=0;i--)
        {
            m->X[i]=m->AB[m->r][i]/m->AB[i][i];
            printf("%lf  ",m->X[i]);
            for(int k=i-1;k>=0;k--)
            {
                m->AB[m->r][k] -= m->AB[i][k] * m->X[i];
            }
        }
    }
    getchar();
}
int main(void)
{
    struct matrix m;
    scanf("%d",&m.r);
    scanf("%d",&m.n);
    initialise(&m);
    read(&m);
    calculate(&m);
    result(&m);
    return 0;
}

