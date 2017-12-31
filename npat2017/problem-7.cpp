//Printing 2n lines in reverse sequence
#include <bits/stdc++.h>
using namespace std;
#define lim 10005
string in,a[lim][lim];
int main()
{
		int i=1,n=0;
		while(getline(std::cin,in))
		{
		    if(in.empty())
		        break;
		    a[i][0]=in;
		    i++;n++;
		}	
		for(int i=n/2+1;i<=n;i++)
		{
			cout<<a[i][0];
			cout<<endl;
		}
		for(int i=1;i<=n/2;i++)
		{
			cout<<a[i][0];
			cout<<endl;
		}
	return 0; 
}