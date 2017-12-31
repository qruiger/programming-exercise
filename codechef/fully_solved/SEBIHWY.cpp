#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    long int test;
    scanf("%ld",&test);
    while(test--)
    {
		 double s,sg,fg,d,t,oc,diff1,diff2;
		 scanf("%lf %lf %lf %lf %lf",&s,&sg,&fg,&d,&t);
		 d*=180;
		 oc=s+(d/t);
		 //printf("%lf\n",oc);
		 diff1=abs((double)(sg-oc));
		 diff2=abs((double)(fg-oc));
		 if(diff1==diff2)
		 	printf("DRAW\n");
		 else if(diff2<diff1)
		 	printf("FATHER\n");
		 else if(diff1<diff2)
		 	printf("SEBI\n");
    }
 	return 0; 
}