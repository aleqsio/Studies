//Aleksander Mikucki kartkowka 2 PI
#include <stdio.h>
#include <malloc.h>

int max(int* arr,int i,int end)
{
    arr[i] = i%2 ? arr[i/2]+arr[(i+1)/2] :  arr[i/2];
    if(i==end)
        return arr[i];
    else
    {
        int next=max(arr,i+1,end);
        return next>arr[i] ? next : arr[i];
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int*arr = malloc(sizeof(int)*(n+1));
    if(NULL==arr)   return 1;
    arr[0]=0;
    arr[1]=1;
    printf("%d",max(arr,0,n));
    return 0;
}