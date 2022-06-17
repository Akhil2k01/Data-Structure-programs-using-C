#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct {
int front,rear;
char item[MAX];
}cqueue;
void insert(cqueue *q,char element[1])
{
q->rear=(q->rear+1)%MAX;
if(q->rear==q->front)
{
if(q->rear==0)
q->rear=MAX-1;
else
q->rear--;
printf("Circular Queue is FULL\n");
return;
}
q->item[q->rear]=element[0];
printf("Element inserted\n");
}
void delete(cqueue *q)
{
if(q->front==q->rear)
{
printf("\nCircular QUEUE is empty\n");
return;
}
else
{
q->front=(q->front+1)%MAX;
printf("Deleted element is %c\n",q->item[q->front]);
}
}
void display(cqueue *q)
{
int i;
if(q->front==q->rear)
{
printf("Circular QUEUE is EMPTY\n");
return;
}
else if(q->front<q->rear)
{
for(i=q->front+1;i<=q->rear;i++)
printf("%c\t",q->item[i]);
}
else
{
for(i=q->front+1;i<=MAX-1;i++)
printf("%c\t",q->item[i]);
for(i=0;i<=q->rear;i++)
printf("%c\t",q->item[i]);
}
}
int main()
{
cqueue q;
int choice;
char c[1];
q.front=q.rear=0;
while(1)
{
printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("\nEnter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("Enter the character to insert\n");
scanf("%s",c);
insert(&q,c);
break;
case 2: delete(&q);
break;
case 3: display(&q);
break;
case 4: exit(0);
default: printf("\nInvalid Choice\n");
}
}
}
