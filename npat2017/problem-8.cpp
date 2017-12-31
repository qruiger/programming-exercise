//Most Frequent 3 integers
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
void mostFreq3(int *a, int n, int b[3]) {

  int maxval=0,k;
  for(int i=0;i<n;i++)
  {
    maxval=max(maxval,a[i]);
  }
  int count[maxval+2]={0};
  for(int i=0;i<n;i++)
  {
    count[a[i]]++;
  }
  k=0;
  b[0]=-999999999;b[1]=-999999999;b[2]=-999999999;
  for(int i=0;i<=maxval;i++)
  {
  	if(count[i]!=0)
  	{
  		if(count[i]>b[0])
  		{
  			b[2]=b[1];
  			b[1]=b[0];
  			b[0]=i;
  		}
  		else if(count[i]>b[2])
  		{
  			b[2]=i;
  		}
  		else if(count[i]>b[1])
  		{
  			b[2]=b[1];
  			b[1]=i;
  		}

  	}
  }
}
int main()
{
	int n;
	int a[100];
	int b[3];
	int i=0;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
  mostFreq3(a,n,b);
  for(i=0; i<3; i++)
      cout << b[i] << " ";

	return 0;
} 