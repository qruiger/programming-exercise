#include <cstdio>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define LL unsigned int long long
int main()
{
	LL t;
	scanf("%lld",&t);
	while(t--)
	{
		LL n,i,count=0,temp,r;
		scanf("%lld",&n);
		if(n==0)
		{
			printf("0\n");
			continue;
		}
		if(n==1)
		{
			printf("INFINITY\n");
			continue;
		}
		if(n==2)
		{
			printf("1\n");
			continue;
		}
		for(i=3;i<n;i++)
		{
			temp=n;
			while(temp!=0)
			{
				r=temp%i;
				temp=temp/i;
			}
			if(r==1)
				count++;
		}
		printf("%lld\n",count+2);				  
	}
	return 0; 
} 
