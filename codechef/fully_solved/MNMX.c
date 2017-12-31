//finding minimum value and then multiplying with n-1
#include<stdio.h>
int main()
{
	int T,i,n;
	int a[10001],m;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		m=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<m) 	
          			m=a[i];
		}
		printf("%d\n",m*(n-1));
    	}
	return 0;
}
