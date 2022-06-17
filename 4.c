#include<stdio.h>
#include<stdlib.h>

#define MAX 100
typedef struct
{
char item[MAX];
int top;
}stack;
int prcd(char op)
{
if(op=='^')
return 4;
else if(op=='*' || op=='/' || op=='%')
return 3;
else if(op=='+' || op=='-')
return 2;
else if(op=='(')
return 1;
else if(op=='#')
return 0;
else
return -1;
}
void push(stack *s,char op)
{
if(s->top==MAX-1)
printf("stack overflow\n");
else{
s->top++;
s->item[s->top]=op;
}
}
char pop(stack *s)
{
if(s->top==-1)
{
printf("Invalid Expression\n");
exit(0);
}
else
return s->item[s->top--];
}
void conversion(stack *s, char infix[30],char postfix[30])
{
int i=0,j=0;
char token;
for(i=0;infix[i]!='\0';i++)
{
token=infix[i];
if(isalnum(token))
{
postfix[j++]=token;
}
else if(token=='(')
push(s,token);
else if (token==')')
{
while(s->item[s->top]!='(')
{
postfix[j++]=pop(s);
}
pop(s);
}
else
{
while(prcd(s->item[s->top])>=prcd(token))
{
postfix[j++]=pop(s);
}
push(s,token);
}
}
while(s->item[s->top]!='#')
{
postfix[j++]=pop(s);

postfix[j++]='\0';
}
}
void main()
{
stack s;
char infix[100],postfix[100];
s.top=-1;
s.item[++s.top]='#';
printf("Enter a valid infix expression\n");
scanf("%s",infix);
conversion(&s,infix,postfix);
printf("Postfix expression is %s\n",postfix);
}
