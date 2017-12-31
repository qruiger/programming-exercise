#include<stdio.h>
int main()
{
	int T,A,B,C,z;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&A,&B,&C);
		z=A>B?(A>C?(B>C?B:C):A):(B>C?(C>A?C:A):B);
		printf("%d\n",z);
	}
	return 0;
}