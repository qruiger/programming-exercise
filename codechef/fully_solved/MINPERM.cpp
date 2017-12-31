#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL a[lim];
void print2(int x,int y)
{
	printf("%d %d ",y,x);
}
void print3(int x,int y,int z)
{
	printf("%d %d %d ",y,z,x);
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			a[i]=i;
		if(n==2 || n==3)
		{
			n==2?print2(a[1],a[2]):print3(a[1],a[2],a[3]);
			printf("\n");
			continue;
		}
		print2(a[1],a[2]);
		if(n%2==0)
		{	
			for(int i=3;i<=n-1;i+=2)
			{
				print2(a[i],a[i+1]);
			}
		}
		if(n%2!=0)
		{	
			i=3;
			while(i<=n)
			{
				if(n-i==2)
				{	
					print3(a[i],a[i+1],a[i+2]);
					i+=3;
				}
				else
				{	
					print2(a[i],a[i+1]);
					i+=2;
				}
			}
		}
		printf("\n");
	}
	return 0; 
}