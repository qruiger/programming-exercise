#include<stdio.h>
int main()
{
	long int T,n,i,j;
	char a[1001],b[1001];
	scanf("%ld",&T);
	while(T--)
	{
		long int w[1001],max,m=0;
		scanf("%ld",&n);
		scanf("%s",a);
		scanf("%s",b);
		for(i=0;i<=n;i++)
			scanf("%ld",&w[i]);
		max=w[0];
		for(i=0;i<n;i++)
		{
			if(a[i]==b[i])
			{	
				m++;
				if(max<w[m]) 
					max=w[m];
			}
		}
		if(m==n)
			printf("%ld\n",w[n]);
		else
			printf("%ld\n",max);
	}
	return 0;
}
