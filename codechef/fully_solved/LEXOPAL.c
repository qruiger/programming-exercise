#include<stdio.h>
#include<string.h>
#define LL long long int
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char s[12346]={0};
        scanf("%s",s);
        LL l,i,j,flag=0;
        l = strlen(s);
        for(i=0,j=l-1;i<j;i++,j--)
        {
            if((s[i]!='.' && s[j]!='.') && (s[i]!=s[j]))
            {   
                printf("-1\n");
                flag=1;
                break;
            }
        }
        if(flag==1)
            continue;   
        for(i=0,j=l-1;i<j;i++,j--)
        {
            if(s[i]=='.' && s[j]!='.')
                s[i]=s[j];
            if(s[j]=='.' && s[i]!='.')
                s[j]=s[i];
            if(s[j]=='.' && s[i]=='.')
                s[j]=s[i]='a';
        }
        if(l%2!=0)
        {
            if(s[l/2] == '.')
                s[l/2]='a';
            printf("%s",s);
            printf("\n");
        }
        else
        {   
            printf("%s",s);
            printf("\n");
        }   
    }
    return 0;
}
