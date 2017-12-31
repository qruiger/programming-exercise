#include<stdio.h>
int main()
{
	int c,r,a,b;
	scanf("%d %d",&a,&b);
	c=a-b;
	r=c%10;
	if(r==9)
		c--;	
	if(r<9)
		c++;
	printf("%d\n",c);
	return 0;
} 
