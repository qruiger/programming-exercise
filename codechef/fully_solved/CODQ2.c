 #include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",n/5);
	n%=5;
	printf("%d\n",n/3);
	n%=3;
	printf("%d\n",n/2);
	n%=2;
	printf("%d",n);
	return 0;
} 