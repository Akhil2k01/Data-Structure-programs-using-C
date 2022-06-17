#include<stdio.h>
#include<stdlib.h>
struct node
{
char usn[11];
char name[20];
char branch[5];
int sem;
char phno[20];
struct node *link;
};
typedef struct node *NODE;
NODE temp, last, FIRST=NULL;
NODE getnode() 
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
x->link=NULL;
return x; 
}
void read() 
{
temp=getnode();
printf("USN\t");
scanf("%s",temp->usn);
printf("Name\t");
scanf("%s",temp->name);
printf("Branch\t");
scanf(" %s",temp->branch);
printf("Sem\t");
scanf("%d",&temp->sem);
printf("Phone no\t");
scanf("%s",temp->phno);
}
void create()
{
int n,i;
printf("\nEnter the number of students\n");
scanf("%d",&n);
for(i=1;i<=n;i++) 
{
printf("\nEnter details of student %d\n",i);
read();
if(FIRST==NULL) 
{
FIRST=temp; 
}
else
{
temp->link=FIRST; 
FIRST=temp; 
}
}
}
void display()
{
int count=0;
temp=FIRST;
printf("Student details\n");
if(FIRST==NULL)
printf("No student records available\n");
else
{
printf("\nUSN\tName\tBranch\tSem\tPhone\n");
while(temp!=NULL)
{
count++;
printf("%s\t%s\t%s\t%d\t%s\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
temp=temp->link; 
}
printf("\nTotal no of Nodes=%d\n",count);
}
}
void insert_front()
{
printf("\nEnter the details of new student\n");
read();
if(FIRST==NULL)
FIRST=temp;
else{
temp->link=FIRST;
FIRST=temp;
}
}
void insert_end()
{
last=FIRST;
printf("\nEnter the details of new student\n");
read();
if(FIRST==NULL)
FIRST=temp;
else
{
while(last->link!=NULL) 
{
last=last->link;
}
last->link=temp;
}
}
void del_front()
{
temp=FIRST;
if(FIRST==NULL)
printf("List is Empty\n");
else
{
FIRST=FIRST->link; 
free(temp);
printf("Deleted\n");
}
}
void del_end()
{
NODE lastButOne=NULL;
temp=FIRST;
if(FIRST==NULL)
printf("List is Empty\n");
else if(FIRST->link==NULL) 
{
printf("Deleted\n");
free(FIRST);
FIRST=NULL;
}
else
{
while(temp->link!=NULL)
{
lastButOne =temp;
temp=temp->link;
}
lastButOne ->link=NULL;
printf("Deleted\n");
free(temp); 
}
}
void main()
{
int choice;
while(1)
{
printf("\n1.Create\n2.Display\n3.Insert FRONT\n4.Delete FRONT\n5.Insert END\n6.Delete END\n7.Exit\n");
printf("Enter Your Choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:create();
break;
case 2:display();
break;
case 3:insert_front();
break;
case 4:del_front();
break;
case 5: insert_end();
break;
case 6:del_end();
break;
case 7: return;
default: printf("Invalid choice\n");
}
}
}
