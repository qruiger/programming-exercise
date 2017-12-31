#include<stdio.h>
#include<math.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int sum,x,y,b,i;
		scanf("%d %d",&x,&y);
		sum=x+y;
		b=sum;
		b++;
		while(b)
		{
			int flag=0;
			for(i=2;i<=sqrt(b);i++)
			{
				if(b%i==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{	
				printf("%d\n",b-sum);
				break;
			}
			else
				b++;
		}
	}
	return 0;
} 
