#include<stdio.h>
#define LL long long int
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		LL i,n,a[100001],sum=0,p=0,f=0;
		float avg;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{		
			scanf("%lld",&a[i]);
			if(a[i]>2)
				p++;
			if(a[i]==5)
				f++;
			sum+=a[i];
		}
		avg=1.0*sum/n;
		if(avg<4)
		{
			printf("No\n");
			continue;
		}
		if(p==n && f>0)
			printf("Yes\n");
		if(p<n || f==0)
			printf("No\n");    	
	}
	return 0;
}
