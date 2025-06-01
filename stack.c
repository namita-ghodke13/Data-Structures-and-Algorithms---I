#include<stdio.h>
#define MAX 20
struct stack
{
  int data[MAX];
  int top;
}s;
void init(STACK *s)
{
  s->top=-1;
}
int isfull(STACK *s)
{
  if(s->top==MAX-1)
     return -1;
}
int isempty(STACK *s)
{
  if(s->top==-1)
     return -1;
}
int peek(STACK *s)
{
  int num;
  num=s->data[s->top];
  return num;
}
void push(STACK *s,int num)
{
  if(isfull())
  {
    printf("\nPush Successfully");
  }
  else
  {
    s->data[s->top++]=num;
  }
}
void pop(STACK *s,int num)
{
  if(isempty())
  {
    printf("\nPop Successfully");
  }
  else
  {
    num=s->data[s->top];
    s->top--;
    return -1;
  }
}
int main()
{
   STACK s;
   int ch,num;
   init(&s);
   do
   {
    printf("\nMENU-");
    printf("\n1-PUSH \n2-POP \n3-PEEK");
    printf("\nEnter Your Choice :");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter Number :");
             scanf("%d",&num);
             push(s,num);
             break;
      case 2:printf("\nPoped Value=%d",pop());
             break;
      case 3:printf("\nPeek Value=%d",peek());
             break;
      default :printf("\nInvalid Choice...");
               break;
    }
   } while (ch<4);
}