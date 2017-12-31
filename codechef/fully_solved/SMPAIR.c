#include<stdio.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
int main()
{
	long int T,n,i;
	int a[100001];
	scanf("%ld",&T);
	while(T--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		 quicksort(a,0,n-1);
		 printf("%d\n",a[0]+a[1]);

	}
	return 0;
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
        int pindex;
        pindex=partition(A,start,end);
        quicksort(A,start,pindex-1);
        quicksort(A,pindex+1,end);
    }
}