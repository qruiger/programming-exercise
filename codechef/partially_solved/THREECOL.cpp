#include <cstdio>
#include <cmath>
using namespace std;
void twoxtwo(int i,int j)
{
	printf("%d %d %d %d\n",i,j,i+1,j);
	printf("%d %d %d %d\n",i,j+1,i+1,j+1);
	printf("%d %d %d %d\n",i+1,j,i+1,j+1);
	printf("%d %d %d %d\n",i,j,i,j+1);
}
void fourxfour(int i, int j)
{
	//2x2 corners
	twoxtwo(i,j);
	twoxtwo(i,j+2);
	twoxtwo(i+2,j);
	twoxtwo(i+2,j+2);
	//2x2 centre
	twoxtwo(i+1,j+1);
	//2x2 corners
	twoxtwo(i,j);
	twoxtwo(i,j+2);
	twoxtwo(i+2,j);
	twoxtwo(i+2,j+2);
}
void eightxeight(int i, int j)
{
	//4x4 corners
	fourxfour(i,j);
	fourxfour(i,j+4);
	fourxfour(i+4,j);
	fourxfour(i+4,j+4);
	//4x4 centre
	fourxfour(i+2,j+2);
	//4x4 corners
	fourxfour(i,j);
	fourxfour(i,j+4);
	fourxfour(i+4,j);
	fourxfour(i+4,j+4);
}
int main()
{
	int n,i,j,count=0;
	scanf("%d",&n);
	if(n==2)
	{
		printf("4\n");
		twoxtwo(1,1);
	}
	else if(n==4)
	{
		printf("36\n");	
		fourxfour(1,1);
	}
	else if(n==5)
	{
		printf("72\n");
		fourxfour(2,2);
		fourxfour(1,1);	
	}
	else if(n==8)
	{
		printf("324\n");
		eightxeight(1,1);
	}
	else if(n==16)
	{
		printf("2916\n");
		//8x8 corners
		eightxeight(1,1);
		eightxeight(1,9);
		eightxeight(9,1);
		eightxeight(9,9);
		//8x8 centre
		eightxeight(5,5);
		//8x8 corners
		eightxeight(1,1);
		eightxeight(1,9);
		eightxeight(9,1);
		eightxeight(9,9);
	}
	return 0;		  
} 