#include<stdio.h>
#include<math.h>
int main()
{
	int T,b,ls;
	float max,min;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&b,&ls);
		min=(float)sqrt((ls*ls)-(b*b));
		max=(float)sqrt((ls*ls)+(b*b));
		printf("%.5f %.5f\n",min,max);
	}
	return 0;
}