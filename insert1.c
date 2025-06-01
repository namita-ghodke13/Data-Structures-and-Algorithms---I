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
struct node *insertmid(struct node *head,int num,int pos)
{
 int i;
 struct node *new,*temp;
 new=(struct node *)malloc(sizeof(struct node));
 new->data=num;
 for(i=1,temp=head;i<pos-1&&temp->next!=NULL;i++,temp=temp->next);
 new->next=temp->next;
 temp->next=new;
 return head;
}
void insertend(struct node *head,int num)
{
 struct node *new,*temp;
 new=(struct node *)malloc(sizeof(struct node));
 new->data=num;
 new->next=NULL;
 for(temp=head;temp->next!=NULL;temp=temp->next);
 temp->next=new;
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
 struct node *head=NULL,*temp;
 int num,pos;
 head=createlist(head);
 printf("\nEnter Number :");
 scanf("%d",&num);
 insertend(head,num);
 display(head);
 printf("\nEnter Position :");
 scanf("%d",&pos);
 head=insertmid(head,num,pos);
}
