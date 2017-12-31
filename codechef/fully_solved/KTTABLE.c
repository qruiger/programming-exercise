#include<stdio.h>
int main()
{
	int c,T,i,I,n;
	scanf("%d",&T);
	while(T--)
	{
		c=0;
		int a[10000];
		int b[10000];
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			scanf("%d",&b[i]);
		if(a[0]>=b[0])
			c++;
		for(i=1;i<n;i++)
		{
			if(a[i]-a[i-1]>=b[i])
				c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
