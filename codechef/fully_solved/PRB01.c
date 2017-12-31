#include<stdio.h>
#include<math.h>
int main()
{
	int T,i,flag,n;
	scanf("%d",&T);
	while(T--)
	{
		flag=0;
		scanf("%d",&n);
		for(i=2;i<=sqrt(n);i++)
		{
			if(n%i==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}
