//DOUBLY LINKED LIST
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
  int data;
  struct node *next,*prev;
}NODE;
void createlist(NODE *head)
{
  int n,i;
  NODE *last,*new;
  printf("Enter Limit :");
  scanf("%d",&n);
  last=head;
  for(i=1;i<=n;i++)
  {
    new=(NODE *)malloc(sizeof(NODE));
    new->next=new->prev=NULL;
    printf("\nEnter Value :");
    scanf("%d",&new->data);
    last->next=new;
    new->prev=last;
    last=new;
  }
}
void deletevalue(NODE *head,int num)
{
  NODE *temp,*temp1;
  for(temp=head;temp->next!=NULL;temp=temp->next)
     if(temp->next->data==num)
     {
       temp1=temp->next;
       temp->next=temp1->next;
       if(temp1->next!=NULL)
         temp->next->prev=temp;
       free(temp1);
       return;
     }
     printf("Element not Found");
}
void display(NODE *head)
{
  NODE *temp;
  for(temp=head->next;temp!=NULL;temp=temp->next)
    printf("%d\t",temp->data);
}
int main()
{
  NODE *head;
  int num;
  createlist(head);
  printf("Enter Number :");
  scanf("%d",&num);
  deletevalue(head,num);
  display(head);
}
