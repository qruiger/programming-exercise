#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define vv 1000001
#define LL int long long
LL s[vv],a[vv],n;
LL binarysearch(LL low, LL high, LL item)
{
	LL mid;
	if(item<=s[low])
		return low;
	mid=(low+high)/2;
	if(s[mid]==item)
		return mid;
	else if(s[mid]<item)
	{
		if(item<=s[mid+1] && mid+1<=high)
			return mid+1;
		else
			return binarysearch(mid+1,high,item);
	}
	else
	{
		if(item>s[mid-1] && mid-1>=low)
			return mid;
		else
			return binarysearch(low,mid-1,item);
	}
}
LL LIS(LL L, LL R)
{
	LL i,k=L,pos,len=0;
	for(i=0;i<n;i++)
		s[i]=0;
	for(i=L;i<=R;i++)
	{
		if(a[i]>s[k-1])
		{	
			s[k++]=a[i];
			//printf("append %lld\n",a[i]);
		}
		else
		{
			pos=binarysearch(L,k-1,a[i]);
			//printf("pos=%lld\n",pos);
			s[pos]=a[i];
		}
	}
	for(i=L;i<=R;i++)
	{
		if(s[i]!=0)
		{	
			//printf("%lld ",s[i]);
			len++;
		}
	}
	return len;
	//printf("\n");
}	
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL m,i,L,R,p;
		scanf("%lld %lld",&n,&m);
		if(n==1)
		{
			scanf("%lld",&p);
			while(m--)
			{
				scanf("%lld %lld",&L,&R);
				printf("1\n");
			}
			continue;
		}
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		while(m--)
		{
			scanf("%lld %lld",&L,&R);L--,R--;
			if(L==R)
			{
				printf("1\n");
			}
			else
			printf("%lld\n",LIS(L,R));
		}
	}
	return 0; 
} 