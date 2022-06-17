#include<stdio.h>
#define MAX 7
typedef struct
{
int top;
int element[MAX];
}STACK;
void push(STACK *s1,int item)
{
if(s1->top==(MAX-1))
printf("\n Stack Overflow");
else
{
s1->top++;
s1->element[s1->top]=item;
}
}
int pop(STACK *s1)
{
if(s1->top==-1)
return -1;
else
{
return s1->element[s1->top--];
}
}
void display(STACK *s1)
{
int i;
if(s1->top==-1)
printf("\n Empty Stack");
else
{
printf("\nThe elements of the stack are\n");
for(i=s1->top;i>=0;i--)
printf("%d\n",s1->element[i]);
}
}
int palindrome(STACK *s1)
{
int number,temp;
printf("Enter the number to be checked for palindrome\n");
scanf("%d",&number);
temp = number;
while(temp!=0)
{
int digit = temp % 10;
push(s1,digit);
temp/=10;
}
temp=number;
while(temp!=0)
{
int digit = temp % 10;
if (digit != pop(s1))
return 0;
temp/=10;
}
return 1;
}
void main()
{
STACK s;
s.top=-1;
int choice,item;
while(1)
{
printf("\n STACK OPERATIONS\n");
printf("1.Push\n 2.Pop\n 3.Display\n 4.Palindrome\n 5.Exit\n");
printf("Enter your choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("\n Enter the element to be pushed :");
scanf("%d",&item);
push(&s,item);
break;
case 2:
item = pop(&s);
if (item == -1)
printf("Stack Underflow\n");
else
printf(" \nPoped element is %d ",item);
break;
case 3: display(&s);
break;
case 4:
if(palindrome(&s))
printf("Entered number is a palindrome");
else
printf("Entered number is not a palindrome");
break;
case 5:return;
default: printf("Invalid choice\n");
}
}
}
