#include<stdio.h>
int main()
{
	int T,i,n,temp;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		temp=n;
		int r1=0,c=0,count=0,r=0,sum=0;
		while(temp>0)
		{
			r1=temp%10;
			c++;
			temp/=10;
		}
		while(n>0)
		{
			count++;
			r=n%10;
			if(count==1 || count==c)
				sum+=r;
			n/=10;
		}
		printf("%d\n",sum);
	}
	return 0;
}