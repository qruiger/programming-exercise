#include<stdio.h>
int main()
{
	int T,min,i,n,c;
	int a[6]={1,2,5,10,50,100};
	scanf("%d",&T);
	while(T--)
	{
		min=0;
		scanf("%d",&n);
		for(i=5;i>=0;i--)
		{
			if(a[i]<=n)
			{	
				min+=n/a[i];
				n=n%a[i];
			}
			if(!n)
			{
				break;
			}
		}
		printf("%d\n",min);
	}
	return 0;
}
