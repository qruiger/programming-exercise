#include <stdio.h>
#include <string.h>
int main ()
{
    long long int t;
    scanf ("%lld",&t);
    while ( t--)
    {
        char a[1000001],b[1000001];
        scanf ("%s %s",a,b);
        long long int c,h=0,l=0,o=0,z=0,l1,i;
        l1=strlen (a);
        for(i=0;i<l1;i++)
        {
            if (a[i]=='0')
                z++;
            else
                o++;
        }
        if (z==l1 || o==l1)
        { 
            printf ("Unlucky Chef\n");
        }
        else
        {
            for(i=0;i<l1;i++)
            {
      	         if(a[i]!=b[i])
      	         {
      		        if(a[i]=='1' && b[i]=='0')
      			       h++;
      		        else
      			       l++;
      	         }
            }
            if(h==l)
            {   	
                printf ("Lucky Chef\n");
                printf ("%lld\n",h);
                continue;
            }
            c=h>l?h:l;
            printf ("Lucky Chef\n");
            printf ("%lld\n",c);
        }
    }
    return 0;
}
