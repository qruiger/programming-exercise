#include<stdio.h>
int main()
{
	int T,q,p;
    	float a;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&q,&p);
		a=(float)(q*p);
		if(q>1000)
			printf("%.6f\n",a-(0.1*a));
		else
			printf("%.6f\n",a);		
	}
	return 0;
}
