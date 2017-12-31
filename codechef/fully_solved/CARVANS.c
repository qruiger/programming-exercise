#include<stdio.h>
int main()
{
	int T,i,n,a[10001];
	scanf("%d",&T);
	while(T--)
	{
		int car=1;
		scanf("%d",&n);	
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
				car++;
			else
				a[i]=a[i-1];
		}
		printf("%d\n",car);
	}
	return 0;
}
 
