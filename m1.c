#include<stdio.h>
#include<stdlib.h>
#define memory (Node *)malloc(sizeof(Node))
typedef struct node
{
int data;
struct node *next;
}Node;
Node *createlist(Node *head)
{ Node *new,*temp;
 int n,i,value;
 printf("Enter Limit");
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
 {
 new=memory;
 printf("Enter Element for %d node:" ,i+1);
 scanf("%d",&value);
 new->data=value;
 new->next=NULL;
 if(head==NULL)
 { head=temp=new;
 }
 temp->next=new;
 temp=new;
 }
return head;
}
void display(Node *head)
{
Node *temp;
printf("\nLinked List is \n");
for(temp=head;temp!=NULL;temp=temp->next)
{
printf("%d\t",temp->data);
}
}
void insertlast(Node *head,int num)
{
 Node *new,*temp=head;
 new=memory;
 new->data=num;
 new->next=NULL;
 printf("Node to be insertd%d",new->data);
 while(temp->next!=NULL)
 {
 temp=temp->next;
 }
 temp->next=new;
}
void insertbypos(Node *head,int num,int pos)
{
 int i;
 Node *new,*temp=head;
 new=memory;
 new->data=num;
 new->next=NULL;
 if(pos==1)
 {
 
 new->next=head->next;
 head->next=new;
 display(head);
 
 }
 else
 {
 temp=head;
 i=1;
 while((temp!=NULL)&&(i<pos-1))
 {
 temp=temp->next;
 i++;
 }
 if(temp->next==NULL)
 printf("OUTOF RANGE");
 
 new->next=temp->next;
 temp->next=new;
 }
 
}
void search(Node *head,int num)
{
Node *temp;
int flag=0,i;
for(temp=head,i=1;temp!=NULL;temp=temp->next,i++)
{
if(temp->data==num)
{
flag=1;
break;
}
}
if(flag==1)
printf("data found at position:%d",i);
else
printf("Data NOT Found");
}
void deletelast(Node *head)
{
Node *temp=head,*temp1;
while(temp->next->next!=NULL)
{
temp=temp->next;
}
temp1=temp->next;
temp->next=NULL;
free(temp1);
}
void delbypos(Node *head,int pos)
{
int i;
Node *temp1,*temp;
if(pos==1)
{
temp=head->next;
head->next=temp->next;
free(temp);
}
else
{
 temp=head;
 i=1;
 while((temp->next!=NULL)&&(i<pos-1))
 {
 temp=temp->next;
 i++;
 }
 if(temp->next==NULL)
 printf("OUTOF RANGE");
temp1=temp->next;
temp->next=temp1->next;
free(temp1); 
}
}
void delbyvalue(Node *head,int num)
{
Node *temp,*temp1;
for(temp=head;temp!=NULL;temp=temp->next)
{
if(temp->next->data==num)
{
temp1=temp->next;
 break;
}
}
temp->next=temp1->next;
free(temp1);
}
void main()
{
 int ch,num,pos;
 Node *head=NULL;
 head=createlist(head);
 do
 {
printf("\n------------");
printf("----MENU------");
printf("---------------");
printf("\n1.INSERT LAST\n");
printf("\n2.INSERT BY POSITION\n");
printf("\n3.SERACH\n");
printf("\n4.DELETE LAST\n");
printf("\n5.DELETE BY POSITION\n");
printf("\n6.DELETE BY VALUE\n");
printf("\n7.DISPLAY\n");
printf("\nEnter Your Choice");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter eLement to insert");
 scanf("%d",&num);
 insertlast(head,num);
 break; 
case 2: printf("Enter eLement to insert");
 scanf("%d",&num);
printf("Enter Position to insert");
scanf("%d",&pos);
insertbypos(head,num,pos);
break;
case 3: printf("Enter eLement to serach");
 scanf("%d",&num);
search(head,num);
break;
case 4: deletelast(head);
break;
case 5: printf("Enter Position to delete");
 scanf("%d",&pos);
delbypos(head,pos);
break;
case 6: printf("Enter Number to delete");
 scanf("%d",&num);
delbyvalue(head,num);
break;
case 7:display(head);
break;
default: printf("INVALID CHOICE");
break;
 }
 }while(ch<8);
}