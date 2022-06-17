#include<stdio.h>
#include<math.h>
#define MAX 20
typedef struct{
int top;
int item[MAX];
}STACK;
void push(STACK *,int);
int pop(STACK *);
void push(STACK *s, int ele)
{
if(s->top==MAX-1)
printf("Stack Overflow\n");
else
{
s->top++;
s->item[s->top]=ele;
}
}
int pop(STACK *s)
{
int num;
if(s->top==-1)
printf("Stack Underflow\n");
else
{
num=s->item[s->top];
s->top--;
return num;
}
}
void main()
{
STACK s;
char post[MAX],ch;
int i,opr1,opr2;
s.top=-1;
printf("Enter the postfix expression\n");
scanf("%s",post);
for(i=0;post[i]!='\0';i++)
{
ch=post[i];
switch(ch)
{
case '+':opr2=pop(&s);
	opr1=pop(&s);
	push(&s,opr1 + opr2);
	break;
case '-':opr2=pop(&s);
	opr1=pop(&s);
	push(&s ,opr1 - opr2);
	break;
case '*':opr2=pop(&s);
	opr1=pop(&s);
	push(&s ,opr1 * opr2);
	break;
case '/':opr2=pop(&s);
	opr1=pop(&s);
	push(&s ,opr1 / opr2);
	break;
case '^':opr2=pop(&s);
	opr1=pop(&s);
	push(&s ,(pow(opr1,opr2)));
	break;
case '%':opr2=pop(&s);
	opr1=pop(&s);
	push(&s ,opr1 % opr2);
	break;
default:push(&s ,ch-'0');
}
}
printf("result = %d\n",s.item[s.top]);
}

