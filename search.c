#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
  int data;
  struct node *next;
};
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
void search(struct node *head)
{
  int num,flag=0;
  struct node *temp;
  printf("\nEnter Number to Search :");
  scanf("%d",&num);
  for(temp=head;temp->next!=NULL;temp=temp->next)
  {
    if((temp->data)==num)
    {
      flag=1;
      break;
    }
  }
  if(flag==1)
    printf("\nNumber Found");
  else 
    printf("\nNumber not Found");
}
int main()
{
 struct node *head=NULL;
 head=createlist(head);
 display(head);
 search(head);
}
