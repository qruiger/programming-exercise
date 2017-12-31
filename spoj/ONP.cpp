#include<stdio.h>
#include<ctype.h>
#define MAX 405
int a[405];
int top=-1;
void push(int item)
{
  a[++top] = item;
}
char pop()
{
  if(top == -1)
  return -1;
  else
  return a[top--];
}
int priority(char x)
{
  switch(x)
  {
    case '(':return 0;
             break;
    case '+':
    case '-':return 1;
             break;
    case '*':
    case '/':return 2;
             break;
    case '^':return 3;
             break;	 
  }
}
int main()
{
  int i,t;
  char x, exp[405];
  scanf("%d",&t);
  while(t--)
  {	
    i = 0;	
    scanf("%s",exp);
    while(exp[i]!='\0')
    {
      if(isalnum(exp[i]))
        printf("%c",exp[i]);
      else if(exp[i] == '(' )
        push(exp[i]);
      else if(exp[i] == ')' )
      {
        while((x=pop()) != '(' )
          printf("%c",x);
      }
      else
      {
        while(priority(exp[i]) <=  priority(a[top]))
          printf("%c",pop());
        push(exp[i]);
      }
      i++;
    }
    while(top != -1)
      printf("%c",pop());
    printf("\n");
  }
  return 0;
} 
