#include<stdio.h>
#include<string.h>
int main()
{
	int T,i,j,count;
	char A[1001],B[1001];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",A);
		scanf("%s",B);
		count=0;
		for(i=0;i<strlen(A);i++)
		{
			for(j=0;j<strlen(B);j++)
			{
			   if(A[i]==B[j])
			   {
			       count=1;
			       break;
			   }
			}
		}
		if(count==1)
			printf("Yes\n");
		else
			printf("No\n");
    	
	}
	return 0;
}
