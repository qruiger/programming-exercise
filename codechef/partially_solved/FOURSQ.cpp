#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define LL int long long
#define size 100005
LL arr[size],n,p,q;
void print(LL L, LL R)
{
	LL mult=1,a,b,c,d,flag=0,i,val;
	for(i=L;i<=R;i++)
	{
		mult=((mult%p)*(arr[i]%p))%p;
	}
	if(mult%p==0)
	{
		printf("0 0 0 0\n");
	}
	else
	{
		for(a=0;a<=sqrt(mult) && a<p;a++)
		{
			for(b=a;b<=sqrt(mult-(a*a)) && b<p;b++)
			{
				for(c=b;c<=sqrt(mult-((a*a)-(b*b))) && c<p;c++)
				{
					val=mult-(a*a)-(b*b)-(c*c);
					d=sqrt(val);
					if(d*d==val && d<p)
					{
						printf("%lld %lld %lld %lld\n",a,b,c,d);
						flag=1;
						break;
					}
				}
				if(flag)
					break;
			}
			if(flag)
				break;
		}
		if(flag==0)
			printf("-1\n");
	}
}
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL i,qtype,var1,var2;
		scanf("%lld %lld %lld",&n,&q,&p);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		while(q--)
		{
			scanf("%lld %lld %lld",&qtype,&var1,&var2);
			if(qtype==1)
			{
				arr[--var1]=var2;
			}
			if(qtype==2)
			{
				print(--var1,--var2);
			}
		}
	}
	return 0; 
}   
