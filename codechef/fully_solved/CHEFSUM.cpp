#include <bits/stdc++.h>
using namespace std;
#define LL int long long
#define lim 100005
LL a[lim];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL sum=0,n;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{	
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		LL minval=a[1]+sum;
		LL val1=a[1],val2=sum,minindex=1;
		for(int i=2;i<=n;i++)
		{
			val1+=a[i];
			val2-=a[i-1];
			//printf("prefix=%lld suffix=%lld\n",val1,val2);
			if(val1+val2<minval)
			{
				minval=val1+val2;
				minindex=i;
			}	
		}
		printf("%lld\n",minindex);	
	}
	return 0; 
}