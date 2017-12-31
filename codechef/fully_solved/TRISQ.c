#include<stdio.h>
#include<math.h>
int main()
{
	int T,s;
	long int b;
	scanf("%ld",&T);
	while(T--)
	{
		s=0;
		scanf("%d",&b);
		while(b>2)
		{
			s+=(b-2)/2;
			b-=2;
		}
	   	printf("%d\n",s);
    	}
	return 0;
}
