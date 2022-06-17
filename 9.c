#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node
{
 int coef;
 int x,y,z;
 struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
 NODE x;
 x=(NODE)malloc(sizeof(struct node));
 return x;
}

NODE readpoly()
{
 NODE temp,head,cur;
 char ch[1];
 head=getnode();
 head->coef=-1;
 head->x=-1;
 head->y=-1;
 head->z=-1;
 head->link=head;
 do
 {
  temp=getnode();
  printf("\nEnter the coefficient and exponent in decreasing order\n");
  scanf("%d%d%d%d",&temp->coef,&temp->x,&temp->y,&temp->z);
  cur=head;
  while(cur->link!=head)
   cur=cur->link;
  cur->link=temp;
  temp->link=head;
  printf("\nDo you want to enter more terms(y/n) : ");
  scanf("%s",ch);
 }while(ch[0]=='y'|| ch[0]=='Y');
 return head;
}                 

int compare(NODE a,NODE b)
{
 if(a->x > b->x)
   return 1;
 else if(a->x < b->x)
       return -1;
 else if(a->y > b->y)
       return 1;
 else if(a->y < b->y)
       return -1;
 else if(a->z > b->z)
       return 1;
 else if(a->z < b->z)
       return -1;
 return 0;
}

void attach(int cf,int x1,int y1,int z1,NODE *ptr)
{
 NODE temp;
 temp=getnode();
 temp->coef=cf;
 temp->x=x1;
 temp->y=y1;
 temp->z=z1;
 (*ptr)->link=temp;
 *ptr=temp;
}

NODE addpoly(NODE a,NODE b)
{
 NODE starta,c,lastc;
 int sum,done=0;
 starta=a;
 a=a->link;
 b=b->link;
 c=getnode();
 c->coef=-1;
 c->x=-1;
 c->y=-1;
 c->z=-1;
 lastc=c;
 do
 {
  switch(compare(a,b))
  {
   case -1:attach(b->coef,b->x,b->y,b->z,&lastc);
           b=b->link;
           break;
   case 0:if(starta==a)
            done=1;
          else
          {
           sum=a->coef+b->coef;
           if(sum)
            attach(sum,a->x,a->y,a->z,&lastc);
           a=a->link;
           b=b->link;
          }
          break;
   case 1:attach(a->coef,a->x,a->y,a->z,&lastc);
          a=a->link;
          break;
  }
 }while(!done);
 lastc->link=c;
 return c;
}

void print(NODE ptr)
{
 NODE cur;
 cur=ptr->link;
 while(cur!=ptr)
 {
  printf("%d*x^%d*y^%d*z^%d",cur->coef,cur->x,cur->y,cur->z);
  cur=cur->link;
  if(cur!=ptr)
   printf(" + ");
 }
}

void evaluate(NODE ptr)
{
 int res=0,x,y,z,ex,ey,ez,cof;
 NODE cur;
 printf("\nEnter the values of x,y,z\n");
 scanf("%d%d%d",&x,&y,&z);
 cur=ptr->link;
 while(cur!=ptr)
 {
  ex=cur->x;
  ey=cur->y;
  ez=cur->z;
  cof=cur->coef;
  printf("%d*x^%d*y^%d*z^%d",cur->coef,cur->x,cur->y,cur->z);
  res=res+(cof*pow(x,ex)*pow(y,ey)*pow(z,ez));
  cur=cur->link;
  if(cur!=ptr)
   printf(" + ");
 }
 printf("\nResult : %d",res);
}

void main()
{
 int i,ch;
 NODE a=NULL,b,c;
 while(1)
 {
  printf("\n1.Enter FIRST Polynomial A\n");
  printf("2.Enter SECOND Polynomial B\n");
  printf("3.Display the Polynomial A\n");
  printf("4.Display the Polynomial B\n");
  printf("5.ADD A and B Polynomials\n");
  printf("6.EVALUATE Polynomial C\n");
  printf("7.EXIT\n");
  printf("Enter Your Choice : ");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:printf("\nEnter the elements of Polynomial A");
   	  a=readpoly();
   	  break;
   case 2:printf("\nEnter the elements of Polynomial B");
   	  b=readpoly();
   	  break;
   case 3:print(a);
          break;
   case 4:print(b);
          break;
   case 5:c=addpoly(a,b);
          printf("\nThe Sum of Two Polynomialis : ");
          print(c);
          printf("\n");
          break;
   case 6:evaluate(c);
          break;
   case 7:return;
   default:printf("\nInvalid Choice\n");
  }
 }
}
 
