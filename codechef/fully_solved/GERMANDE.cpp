#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define LL int long long
LL d[1000005],b[1000005],c[1000005];
int main()
{
	LL t; 
	scanf("%lld",&t);
	while(t--)
	{
		LL i,j,p,o1,o2,n,no=0,nz,ans,s,k,tone=0,tzero=0,flag=0,val1,val2;
		scanf("%lld %lld",&o1,&o2);
		n=o1*o2;
		for(i=1;i<=n;i++)
			scanf("%lld",&d[i]);
		for(i=1;i<=n;i++)
		{
			if(d[i]==1)
			{
				no++;
				b[i]=no;
			}
			else
				b[i]=no;
		}
		for(i=1;i<=o2;i++)
		{
			if(d[i]==1)
			{
				no++;
				c[i]=no;
			}
			else
				c[i]=no;
		}
		b[0]=0;	
		for(p=1;p<=o2;p++)
		{
			s=1,tone=0,tzero=0;
			for(j=p;s<=o1;)
			{
				printf("ind=%lld\n",j);
				no=0,nz=0;
				s++;
				if((n-j+1)<o2)
				{
					val1=(n-j)+1;
					val2=o2-val1;
					no=c[val2]-b[j-1];
					nz=o2-no;
				}
				else if(j+(o2-1)<=n)
				{
					no=b[j+(o2-1)]-b[j-1];
					nz=o2-no;
				}
				if(no>nz)
					tone++;
				else
					tzero++;
				j+=o2;
				printf("no=%lld nz=%lld\n",no,nz);
			}
			if(tone>tzero)
			{
				printf("1\n");
				flag=1;
				break;
			}
		}
		if(!flag)
			printf("0\n");
	}
	return 0; 
}  
