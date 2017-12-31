#include<stdio.h>
int main()
{
	long int T,i,n,m;
	scanf("%ld",&T);
	while(T--)
	{
		scanf("%ld",&n);
		n++;
		m=n;
		while(m)
		{
			i=m;
			long int sum=0;
			while(i>0)
			{
				sum=sum*10+i%10;
				i/=10;
			}
			if(sum==m)
			{ 	
				printf("%ld\n",m);
				break;
			}
			else
				m++;
		}
	}
	return 0;
} 
