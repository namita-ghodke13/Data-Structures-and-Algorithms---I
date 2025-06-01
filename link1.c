#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
  int data;
  struct node *next;
}NODE;
NODE *createlist(NODE *head)
{
  int i,n,num;
  NODE *new,*temp;
  printf("\nEnter Number of nodes :");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    new=(NODE *)malloc(sizeof(NODE));
    printf("Enter Data :");
    scanf("%d",&num);
    new->data=num;
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
void display(NODE *head)
{
  NODE *temp;
  for(temp=head;temp!=NULL;temp=temp->next)
  {
    printf("%d\t",temp->data);
  }
}
void mergelist(NODE *head1,NODE *head2,NODE *head3)
{
  NODE *temp1=head1->next,*temp2=head2->next,*temp3=head3,*new;
  while((temp1!=NULL)&&(temp2!=NULL))
  {
    new=(NODE *)malloc(sizeof(NODE));
    new->next=NULL;
    if(temp1->data<temp2->data)
    {
      new->data=temp1->data;
      temp1=temp1->next;
    }
    else
    {
      new->data=temp2->data;
      temp2=temp2->next;
    }
    temp3->next=new;
    temp3=new;
  }
  while(temp1!=NULL)
  {
    new=(NODE *)malloc(sizeof(NODE));
    new->data=temp1->data;
    new->next=NULL;
    temp1=temp1->next;
    temp3->next=new;
    temp3=new;
  }
  while(temp2!=NULL)
  {
    new=(NODE *)malloc(sizeof(NODE));
    new->data=temp2->data;
    new->next=NULL;
    temp2=temp2->next;
    temp3->next=new;
    temp3=new;
  }
}
int main()
{
 NODE *head1=NULL;
 head1=createlist(head1);
 display(head1);
 NODE *head2=NULL;
 head2=createlist(head2);
 display(head2);
 NODE *head3;
 mergelist(head1,head2,head3);
 display(head3);
}
