#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;
struct node *createlist(struct node *head)
{
  int i,n,value;
  struct node *new,*temp;
  printf("Enter Number of Nodes :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=(struct node *)malloc(sizeof(struct node));
    printf("Enter Data :");
    scanf("%d",&value);
    new->data=value;
    new->next=NULL;
    if(head==NULL)
    {
     head=temp=new;
    }
    else
    {
     temp->next=new;
     temp=new;
    }
  }
  return head;
}
void display(struct node *head)
{
  struct node *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
void deletepos(NODE *head,int pos)
{
  NODE *temp,*temp1;
  int i;
  temp=head;
  i=1;
  while((temp->next!=NULL)&&(i<=pos-1))
  {
    i++;
    temp=temp->next;
  }
  
  if(temp->next==NULL)
  {
    printf("\nPosition is out of Range");
  }
  temp1=temp->next;
  temp->next=temp1->next;
  free(temp1);
}
int main()
{
 int pos;
 struct node *head=NULL;
 head=createlist(head);
 printf("Enter Position :");
 scanf("%d",&pos);
 deletepos(head,pos);
 display(head);
}