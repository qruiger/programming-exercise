#include<stdio.h>
#include<string.h>
int main()
{
	int r,b,g,T,N,i,j,z;
	scanf("%d",&T);
	char s[100001];
	for(i=0;i<T;i++)
	{
		r=0,b=0,g=0;
		scanf("%d",&N);
		scanf("%s",s);
		for(j=0;j<N;j++)
		{	
			if(s[j]=='R')
				r+=1;
			if(s[j]=='B')
				b+=1;
			if(s[j]=='G')
				g+=1;
		}
		z=r;
		if(b>z)
			z=b;
		if(g>z)
			z=g;
		printf("%d\n",N-z);
	}
	return 0;
}    
