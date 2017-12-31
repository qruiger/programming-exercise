#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
     	LL sum1=0,n,sum=0,p=0,j,i,k;
     	scanf("%lld",&n);
     	LL a[n],b[n];
     	int flag=0;
     	for(i=1;i<=n;i++)
     	{	
     		scanf("%lld",&a[i]);
     		sum1+=a[i];
     	}
     	scanf("%lld",&k);
     	if(k==sum1)
     	{
     		for(i=1,j=n;i<=j;i++,j--)
     		{
     			if(i==j)
     			{	
     				printf("%lld",i);
     				break;
     			}
     			else	
     			printf("%lld %lld ",i,j);
     		}
     		printf("\n");
     		continue;
     	}	
     	for(i=1,j=n;i<=j;i++,j--)
     	{
     		sum+=a[i];
     		b[p++] = i;
     		if(sum>k)
     		{
     			flag = 0;
     			break;
     		}	
     		if(sum == k)
     		{
     			flag =1;	
     			break;
     		}	
     		sum+=a[j];
     		b[p++] = j;
     		if(sum>k)
     		{
     			flag = 0;
     			break;
     		}
		if(sum == k)
		{
			flag =1;		
			break;
		}	
     	}
     	if(flag!=1)
     	{
     		printf("BING\n");
     		continue;
     	}
     	for(i=0;i<p;i++)
     		printf("%lld ",b[i]);
     	printf("\n");	
    }
   return 0; 
}
