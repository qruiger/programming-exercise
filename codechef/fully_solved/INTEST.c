#include<stdio.h>
int main()
{
	long n,k,z,y;
	y=0;
	scanf("%lu %lu\n",&n,&k);
	while(n--)
	{
		scanf("%lu\n",&z);
		if(z%k==0)
			y++;
	}
	printf("%d",y);
	return 0;
}
