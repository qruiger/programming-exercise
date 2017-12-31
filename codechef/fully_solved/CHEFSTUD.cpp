#include<cstdio>
#include<climits>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL int long long
int main()
{
    LL t;
    scanf("%lld",&t);
    while(t--)
    {
    	char s[100005];
    	LL i,count=0,len;	  
    	scanf("%s",s);
    	len=strlen(s);
    	for(i=0;i<lens-1;i++)
    	{
    		if(s[i]=='<' && s[i+1]=='>')
    			count++;
    	}
    	printf("%lld\n",count);
    }
 	return 0; 
}