#include<stdio.h>
#include<stdlib.h>
struct node
{
char ssn[10];
char name[20];
char dept[20];
char designation[20];
int salary;
char phno[20];
struct node *prev;
struct node *next;
};
typedef struct node *NODE;
NODE temp,last,lastButOne, FIRST=NULL;
NODE getnode()
{
NODE x;
x=(NODE)malloc(sizeof(struct node));
x->prev=NULL;
x->next=NULL;
return x;
}
void read()
{
temp=getnode();
printf("SSN\t");
scanf("%s",temp->ssn);
printf("Enter Name\t");
scanf("%s",temp->name);
printf("Department\t");
scanf("%s",temp->dept);
printf("Designation\t");
scanf("%s",temp->designation);
printf("Salary\t");
scanf("%d",&temp->salary);
printf("Phone No.\t");
scanf("%s",temp->phno);
}
void create()
{
int n,i;
printf("Enter the number of employees\n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter details of employees %d\n",i);
read();
if(FIRST==NULL) 
{
FIRST=temp; 
}
else
{
last=FIRST;
while(last->next!=NULL)
{
last=last->next;
}
last->next=temp;
temp->prev=last;
}
}
}
void display()
{
int count=0;
temp=FIRST;
if(FIRST==NULL)
printf("No employee details available\n");
else
{
printf("\nSSN\tName\tDept\tDesig\tSalary\tPhone\n");
while(temp!=NULL)
{
count++;
printf("%s\t%s\t%s\t",temp->ssn,temp->name,temp->dept);
printf("%s\t%d\t%s\n",temp->designation,temp->salary,temp->phno);
temp=temp->next;
}
printf("\nTotal no of nodes=%d\n",count);
}
}
void insert_front()
{
printf("Enter the details of new employee\n");
read();
if(FIRST==NULL)
FIRST=temp;
else
{
temp->next=FIRST;
FIRST->prev=temp;
FIRST=temp;
}
}
void del_front()
{
temp=FIRST;
if(FIRST==NULL)
printf("List is empty\n");
else
{
FIRST=FIRST->next;
free(temp);
printf("Deleted\n");
}
}
void insert_end()
{
last=FIRST;
printf("Enter the details of new employee\n");
read();
if(FIRST==NULL)
FIRST=temp;
else
{
while(last->next!=NULL)
{
last=last->next;
}
last->next=temp;
temp->prev=last;
}
}
void del_end()
{
lastButOne=NULL;
temp=FIRST;
if(FIRST==NULL)
printf("List is empty\n");
else if(FIRST->next==NULL)
{
printf("Deleted\n");
free(FIRST);
FIRST=NULL;
}
else
{
while(temp->next!=NULL)
{
lastButOne=temp;
temp=temp->next;
}
lastButOne->next=NULL;
printf("Deleted\n");
free(temp); 
}
}
void main()
{
int choice,n,i;
char c;
while(1)
{
printf("\n1. Create\n2. Display\n3. Insert FRONT\n4. Delete FRONT\n5. Insert END\n6. Delete END\n7. Exit\n");
printf("Enter Your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:create();
break;
case 2: display();
break;
case 3:insert_front();
break;
case 4:del_front();
break;
case 5:insert_end();
break;
case 6:del_end();
break;
case 7: exit(0);
default: printf("Invalid Choice\n");
}
}
}
