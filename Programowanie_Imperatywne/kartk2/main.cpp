#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include<cstring>
struct car{
    char brand[20];
    int engine;
    char model[20];
};

int comparator(const void* a, const void *b)
{

    return strcmp(((struct car *)a)->brand,((struct car *)b)->brand);
}
int main() {
    int n;
    scanf("%d",&n);
    struct car* cars =(struct car*) malloc(n*sizeof(struct car));
    for(int i=0;i<n;i++)
    {
        scanf("%s %d %s",&cars[i].brand,&cars[i].engine,&cars[i].model);
    }
    char request[20];
    scanf("%s",&request);
    qsort(cars, n, sizeof(struct car), comparator); //astabline ale w tym przypadku nie ma to znaczenia
    int lw=1;
    int last=0;
    //for(int i=0;i<n;i++)  printf("\n%s %d %s",cars[i].brand,cars[i].engine,cars[i].model);
    for(int i=1;i<n;i++)
    {

        if(strcmp(cars[i].brand,cars[last].brand))
        {
            lw++;
            last=i;
        }
    }
    //printf("\nliczba marek: %d",lw);
    //alokacja drugiej tablicy
    struct car* cars2[lw];
    int lenw[lw];
    last=-1;
    int currentbrand=-1;
    for(int i=0;i<lw;i++) lenw[i]=0;

    for(int i=0;i<n;i++)
    {

        if(last<0 || strcmp(cars[i].brand,cars[last].brand))
        {
            currentbrand++;
           cars2[currentbrand]=&cars[i];

            last=i;
        }
        lenw[currentbrand]++;
    }
    //for(int i=0;i<lw;i++)    printf("\npierwszy samochód danej marki:%s, liczba %d",cars2[i]->model,lenw[i]);
    //szukanie konkretnej marki
    int summator=0;
    int beginning=0;
    int end=0;
    int ind=-1;
    while(end==0)       //unikamy iterowania po cars korzystając z tablicy marek
    {
        ind++;
        if(!strcmp(cars2[ind]->brand,request))
        {
             beginning=summator;
        }
        summator+=lenw[ind];
        if(beginning) end=summator;
    }
    printf("\nLista samochodow marki %s:",request);
    for(int i=beginning;i<end;i++)    printf("\n%s, %d, %s",cars[i].brand,cars[i].engine,cars[i].model);
    return 0;
}