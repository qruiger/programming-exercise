#include<stdio.h>
void quicksort(int *,int,int);
int partition(int *,int,int);
int main()
{
	int T,N,K,y,z,i;
	int A[10001];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		for(i=0;i<N;i++)
			scanf("%d",&A[i]);
		scanf("%d",&K);
		for(i=0;i<N;i++)
		{
			if(K==(i+1))
				y=A[i];
		}
		quicksort(A,0,N-1);
		for(i=0;i<N;i++)
		{
			if(A[i]==y)
				z=i;
		}
		printf("%d\n",z+1);
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
