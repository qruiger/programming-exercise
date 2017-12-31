#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define LL long long int
#define lim 1000001
LL SegTree[4*lim], a[lim], lpd[lim], prime[lim];
LL max(LL a, LL b)
{
	LL m = a>b?a:b;
	return m;
}
void ConstSegTree(LL input[], LL low, LL high, LL pos)
{
	if(low == high)
	{
		SegTree[pos] = input[low];
		return;
	}
	LL mid = (low+high)/2;
	ConstSegTree(input, low, mid, 2*pos+1);
	ConstSegTree(input, mid+1, high, 2*pos+2);
	SegTree[pos] = 	max(lpd[SegTree[2*pos+1]], lpd[SegTree[2*pos+2]]);
}
LL MaxRangeQuery( LL qlow, LL qhigh, LL low, LL high, LL pos)
{
	if(qlow <= low && qhigh >= high) 
		return lpd[SegTree[pos]];
	if(qlow > high || qhigh < low)	
		return -1;
	LL mid = (low+high)/2;
	return max(MaxRangeQuery(qlow, qhigh, low, mid, 2*pos+1) , 
			      MaxRangeQuery(qlow, qhigh, mid+1, high, 2*pos+2));
}
void UpdateVal(LL qlow, LL qhigh, LL low, LL high, LL pos)
{
	if(qlow > high || qhigh < low || SegTree[pos] == 1)
		return;
	if(low == high)
	{
		SegTree[pos] /= lpd[SegTree[pos]];
		return;
	}
	LL mid = (low+high)/2;
	UpdateVal(qlow, qhigh, low, mid, 2*pos+1);
	UpdateVal(qlow, qhigh, mid+1, high, 2*pos+2);
	SegTree[pos] = max(lpd[SegTree[2*pos+1]], lpd[SegTree[2*pos+2]]);
}
int main()
{
	LL i,j,temp;
	for(i=0;i<=lim;i++)
	lpd[i]=0;
	lpd[1]=1;
	for(i=2;i<=lim;i++)
	{
		if(lpd[i]==0)
		{
			temp=i;    
			for(j=temp;j<=lim;j+=temp)
			{	 
				if(lpd[j] == 0)
				lpd[j]=temp;
			}
		}     
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL n,m,L,R,op,val[lim],k=0;
		scanf("%lld %lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		ConstSegTree(a, 0, n-1, 0);	
		while(m--)
		{
			scanf("%lld %lld %lld",&op,&L,&R);
			if(op == 1)
			{
				val[k++] = MaxRangeQuery(L-1, R-1, 0, n-1, 0);
			}
			if(op == 0)
			{
				UpdateVal(L-1, R-1, 0, n-1, 0);
			}
		}
		for(i=0;i<k;i++)
		printf("%lld ",val[i]);
		printf("\n");	
	}
	return 0;	
}  
