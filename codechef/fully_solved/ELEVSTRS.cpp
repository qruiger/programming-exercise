#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		float s,n,v1,v2,t1,t2;
		scanf("%f %f %f",&n,&v1,&v2);
		t1=(sqrt(2)*n)/v1;
		t2=(n*2)/v2;
		//printf("%f %f\n",t1,t2);
		if(t1 < t2)
			printf("Stairs\n");
		else
			printf("Elevator\n");
	}
	return 0; 
}