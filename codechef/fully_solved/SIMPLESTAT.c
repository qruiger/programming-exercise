#include<stdio.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
int main()
{
    int A[100000];
    float sum;
    int i,j,N,K,T,t;
    scanf("%d",&T);
    while(T--)
   {
    scanf("%d%d",&N,&K);
    for(i=0;i<N;i++)
    scanf("%d",&A[i]);
    quicksort(A,0,N-1);
    sum=0;
    for(i=K;i<N-K;i++)
        sum+=A[i];
    if(K!=0)
    sum/=(N-2*K);
    else
    sum/=N;
    printf("%f\n",sum);
   }
}    
int partition(int *A,int start,int end)
{
    
    int i,t=0,pivot,pindex;
    pivot=A[end];
    pindex=start;
    for(i=start;i<end;i++)
    {
        if(A[i]<=pivot)
        { 
         t=A[i];
         A[i]=A[pindex];
         A[pindex]=t; 
         pindex++;
        }
    }
    t=A[pindex];
    A[pindex]=A[end];
    A[end]=t;
    return pindex;
}
void quicksort(int *A,int start,int end)
{
    if(start<end)
    {
        int pindex=partition(A,start,end);
        quicksort(A,start,pindex-1);
        quicksort(A,pindex+1,end);
    }
}
