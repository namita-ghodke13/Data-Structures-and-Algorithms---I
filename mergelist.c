#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
typedef struct node
{
 int data;
 struct node *next;
}Node;
Node *create(Node *head)
{
 Node *temp,*new;
 int i,n;
 printf("\nEnter Limit :");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  new=memory;
  printf("Enter Value :");
  scanf("%d",&new->data);
  new->next=NULL;
  if(head==NULL)
  {
   temp=head=new;
  }
  else
  {
   temp->next=new;
   temp=new;
  }
 }
 return head;
}
void display(Node *head)
{
 Node *temp;
 for(temp=head;temp!=NULL;temp=temp->next)
 {
  printf("%d\t",temp->data);
 }
}
Node *merge(Node *list,int num)
{
 Node *new,*temp;
 new=memory;
 new->data=num;
 new->next=NULL;
 if(list==NULL)
 {
  return new;
 }
 else
 {
  for(temp=list;temp->next!=NULL;temp=temp->next);
  temp->next=new;
  return list;
 }
}
Node *mergelist(Node *list1,Node *list2)
{
 Node *temp1=list1,*temp2=list2,*list3=NULL;
 while(temp1!=NULL&&temp2!=NULL)
 {
  if(temp1->data<temp2->data)
  {
   list3=merge(list3,temp1->data);
   temp1=temp1->next;
  }
  else
  {
   list3=merge(list3,temp2->data);
   temp2=temp2->next;
  }
 }
 while(temp1!=NULL)
 {
  list3=merge(list3,temp1->data);
  temp1=temp1->next;
 }
 while(temp2!=NULL)
 {
  list3=merge(list3,temp2->data);
  temp2=temp2->next;
 }
 return list3;
}
int main()
{
 Node *list1=NULL,*list2=NULL,*list3=NULL;
 list1=create(list1);
 list2=create(list2);
 list3=mergelist(list1,list2);
 display(list3);
}