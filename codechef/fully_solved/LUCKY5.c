//If the digit do not contain 4&7 then the steps required are the length of the digit entered
//if the digit contains 4||7 then steps is length of digit minus no of lucky numbers in the digit
//if the digit contains 4&7 then steps is 0
#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i,j=0,l;
		char s[100000];
		scanf("%s",s);
		l=strlen(s);
		for(i=0;i<l;i++)
		{
			if(s[i]!='4' && s[i]!='7')
				j++;
		}
		printf("%d\n",j);
	}
	return 0;
} 
