//first sort and then multiply lowest with n-1
#include<stdio.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
int main()
{
	int T,i,n;
	int a[10001],m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		quicksort(a,0,n-1);
		printf("%lld\n",(long long)a[0]*(n-1));
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