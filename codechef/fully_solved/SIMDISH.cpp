#include <bits/stdc++.h>
using namespace std;
string a1,a2,a3,a4,b1,b2,b3,b4;
int main()
{
	int t; 
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		cin>>a1;
		cin>>a2;
		cin>>a3;
		cin>>a4;
		cin>>b1;
		cin>>b2;
		cin>>b3;
		cin>>b4;
		if(a1.compare(b1)==0)
			ans++;
		if(a1.compare(b2)==0)
			ans++;
		if(a1.compare(b3)==0)
			ans++;
		if(a1.compare(b4)==0)
			ans++;
		if(a2.compare(b1)==0)
			ans++;
		if(a2.compare(b2)==0)
			ans++;
		if(a2.compare(b3)==0)
			ans++;
		if(a2.compare(b4)==0)
			ans++;
		if(a3.compare(b1)==0)
			ans++;
		if(a3.compare(b2)==0)
			ans++;
		if(a3.compare(b3)==0)
			ans++;
		if(a3.compare(b4)==0)
			ans++;
		if(a4.compare(b1)==0)
			ans++;
		if(a4.compare(b2)==0)
			ans++;
		if(a4.compare(b3)==0)
			ans++;
		if(a4.compare(b4)==0)
			ans++;
		if(ans>1)
			printf("similar\n");
		else
			printf("dissimilar\n");
	}
	return 0; 
} 