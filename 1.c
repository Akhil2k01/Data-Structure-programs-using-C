#include<stdio.h>

int a[20];
int n,elem,i,pos;
void create();
void display();
void insert();
void delete();

void main()
{
 int choice;
 while(1)
     {
       printf("\nMENU\n");
       printf("1.CREATE\n");
       printf("2.DISPLAY\n");
       printf("3.INSERT\n");
       printf("4.DELETE\n");
       printf("5.EXIT\n");
       printf("Enter your choice\n");
       scanf("%d",&choice);

       switch(choice)
       {
         case 1:create();
                break;

         case 2:display();
                break;

         case 3:insert();
                 break;

         case 4:delete();
                 break;

         case 5:return;

         default:printf("\nInvalid choice\n");
       }
     }
}

void create()
{
 printf("\nEnter the size of the array elements\n");
 scanf("%d",&n);
 printf("\nEnter the elements of the array\n");
 for(i=0;i<n;i++)
    scanf("%d",&a[i]);
}

void display()
{
 printf("\nThe array elements are:\n");
 for(i=0;i<n;i++)
      printf("a[%d] = %d\n",i, a[i]);
}

void insert()
{
 printf("\nEnter the position for the new element\n");
 scanf("%d",&pos);
 if(pos>=n+1|| pos<0)
  printf("Insertion not possible\n");
 else
    {
     printf("\nEnter the element to be inserted:\t");
     scanf("%d",&elem);
     for(i=n-1;i>=pos;i--)
           a[i+1]=a[i];
     a[pos]=elem;
    n++;
    }
}

void delete()
{
 printf("\nEnter the position of the element to be deleted\n");
 scanf("%d",&pos);
 if(pos>=n || pos<0)
  printf("Deletion not possible");
 else
    {
     printf("\nThe deleted element is %d",a[pos]);
     for(i=pos;i<n-1;i++)
           a[i]=a[i+1];
     n--;
    }
}
