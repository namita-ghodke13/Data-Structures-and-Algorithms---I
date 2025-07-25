#include<stdio.h>
#include<ctype.h>
#define MAX 100
struct stack
{
    char a[MAX];
    int top;
}s;
void init ()
{
   s.top=-1;
}
int isempty()
{
   if(s.top==-1)
       return 1;
   else 
       return 0;
}
int isfull()
{
    if(s.top==MAX-1)
        return -1;
    else 
        return 0;
}
void push(char x)
{
    if(isfull())
       printf("Stack is full ..... don't push");
    else 
    {
         s.top++;
         s.a[s.top]=x;
    }
}
char pop()
{
    char ch;
    if(isempty())
       return -1;
    else 
    {
        ch=s.a[s.top];
        s.top--;
        return ch;
    }
}
int priority(char x)
{
    if(x=='(')
       return 0;
    if(x=='+' || x=='-')
       return 1;
    if(x=='*' || x=='/')
       return 2;
    if(x=='$' || x=='^' || x=='->')
       return 3;
    return 0;
}
int main()
{
  char infix[100],prefix[100],ch;
  int i,j=0;
  printf("Enter Prefix Expression :");
  scanf("%s",&infix);
  strrev(infix);
  for(i=0;infix[i]!='\0';i++)
  {
     if(infix[i]=='(')
         infix[i]=')';
     else if(infix[i]==')')
         infix[i]='(';
  }
  init();
  
  for(i=0;infix[i]!='\0';i++)
  {
      if(isalpha(infix[i]))
         prefix[j++]=infix[i];
      else if(infix[i]=='(')
         push(infix[i]);
      else if(infix[i]==')')
      {
          while((ch=pop())!='(')
          {
             prefix[j++]=ch;
          }
      }
      else 
      {
         while(priority(s.a[s.top])>=priority(infix[i]))
          {
              prefix[j++]=pop();
          }
          push(infix[i]);
      }
   }
   while(!isempty())
   {
       prefix[j++]=pop();
   }
   prefix[j]='\0';
   strrev(prefix);
   printf("\nPrefix Expression=%s",prefix);
}