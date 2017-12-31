#include <stdio.h>
int main ()
{
	long int n,t;
	scanf ("%ld",&t);
	while (t--)
   	{
		scanf ("%ld",&n);
		if (n%6==0)
			printf("Misha\n");
		else
			printf ("Chef\n");
   	}
	return 0;
} 
