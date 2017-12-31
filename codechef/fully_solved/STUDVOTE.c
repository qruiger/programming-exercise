#include<stdio.h>
#include<stdlib.h>
#define LL long long int
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,k,c=0,a[100];
		scanf("%d %d",&n,&k);
		int b[100]={ 0 };
		for(i=1;i<=n;i++)    
		{
			scanf("%d",&a[i]);
			b[a[i]]++;
		}
		for(i=1;i<=n;i++)
		{
			if(b[i]>=k && a[i]!=i)
				c++;    
		}
		printf("%d\n",c); 
	}
    	return 0;
}
