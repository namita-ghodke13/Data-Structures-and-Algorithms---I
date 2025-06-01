#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node));
typedef struct node
{
  int data;
  struct node *next,*prev;
}Node;
Node *createlist(Node *head)
{
  Node *new,*temp;
  int n,i,value;
  printf("Enter Limit :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=memory;
    printf("Enter element for %d Node : ",i+1);
    scanf("%d",&value);
    new->data=value;
    if(head==NULL)
    {
      head=temp=new;
    }
    new->next=NULL;
    new->prev=temp;
    temp->next=new;
    temp=new;
  }
  return head;
}
void display(Node *head)
{
  Node *temp;
  printf("\nLinked List is -\n");
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}