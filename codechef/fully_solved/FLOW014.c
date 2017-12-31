#include<stdio.h>
int main()
{
	int g,T,h,ts;
	float cc;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%f%d",&h,&cc,&ts);
		g=(h>50&&cc<0.7&&ts>5600)?10:(h>50&&cc<0.7)?9:(cc<0.7&&ts>5600)?8:(h>50&&ts>5600)?7:(h>50||cc<0.7||ts>5600)?6:5;
		printf("%d\n",g);
	}
	return 0;
}