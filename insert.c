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
struct node *insertbeg(struct node *head,int value)
{
 struct node *new;
 new=(struct node *)malloc(sizeof(struct node));
 printf("\nEnter Value :");
 scanf("%d",&value);
 new->next=NULL;
 new->data=value;
 new->next=head;
 head=new;
 return head;
}
struct node *insertbeg2(struct node *head,int num)
{
 struct node *new;
 new=(struct node *)malloc(sizeof(struct node));
 printf("Enter Value :");
 scanf("%d",&num);
 new->data=num;
 new->next=head->next;
 head->next=new;
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
int main()
{
 struct node *head=NULL;
 int value,num;
 head=createlist(head);
 head=insertbeg(head,value);
 head=insertbeg2(head,num);
 display(head);
}
