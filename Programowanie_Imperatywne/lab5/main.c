#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

struct complex {
    double x;
    double y;
};

void randomise(struct complex* complex);

void printcmp(struct complex *pComplex);

double getmodule(struct complex* complex);

int comparator(void* a,void *b);

int main() {
    struct complex* numbers = malloc(sizeof(struct complex)*10);
    srand(time(0));
    for(int i=0;i<10;i++)
    {
        randomise(&(numbers[i]));
    }
    qsort(numbers,10,sizeof(struct complex),comparator);
    printcmp(numbers);
    return 0;
}

void printcmp(struct complex *complex) {
for(int i=0;i<10;i++)
{
    printf("Complex x=%lf, y=%lf, module=%lf\n",complex[i].x,complex[i].y,getmodule(&complex[i]));
}
}

int comparator(void* a,void *b)
{

   return getmodule((struct complex *)a)==getmodule((struct complex *)b) ? 0 : ( getmodule((struct complex *)a)>getmodule((struct complex *)b) ? 1 : -1);
}
void randomise(struct complex* complex) {
    complex->x=(double)rand()/(double)(RAND_MAX/20)-10;
    complex->y=(double)rand()/(double)(RAND_MAX/20)-10;
}
double getmodule(struct complex* complex) {
    return sqrt(pow(complex->x,2)+pow(complex->y,2));
}