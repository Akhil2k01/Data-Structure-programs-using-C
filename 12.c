#include<stdio.h>
#include<stdlib.h>
#define SIZE 10

struct Employee
{
	int employee_key;
	char employee_name[30];
};

struct Employee emp[SIZE];

int L;

int hash_function(int key)
{
 return (key % 10);
}

void linear_probing(int loc, struct Employee e)
{
 int count = 0, i, flag=0;
 printf("\nCollision Detected...!!!\n");
 for(i=loc+1; i<SIZE; i++)
 if(emp[i].employee_key == -1)
 {
  emp[i] = e;
  flag =1;
  break;
 }
 i=0;
 while((i<loc) && (flag==0))
 {
  if(emp[i].employee_key == -1)
  {
   emp[i] = e;
   flag =1;
   break;
  }
  i++;
 }
 if (flag==0)
   printf("HASH TABLE FULL\n");
 else
   printf("Collision avoided successfully\n");
}

void read_file()
{
 FILE *infile;
 int i, j;
 struct Employee E;
 infile = fopen("input.txt", "r");
 if(infile == NULL)
 {
  fprintf(stderr, "\nError opening input.txt\n\n");
  exit (1);
 }
 else
 {
  for (i=0; i<SIZE; i++)
  {
   emp[i].employee_key = -1;
  }
  while(fscanf(infile,"%d%s",&E.employee_key,E.employee_name)!=EOF)
  {
   L=hash_function(E.employee_key);
   if(emp[L].employee_key == -1 )
     emp[L] = E;
   else
     linear_probing(L, E);
  }
 }
}

void display_attached()
{
 int j;
 printf("\n\n******Hash Table for Attached Keys*****\n\n");
 for (j=0; j<SIZE; j++)
 {
  if(emp[j].employee_key != -1)
     printf("\nLOCATION[%d]--->KEY= %d \t EMP NAME = %s \n",j,emp[j].employee_key, emp[j].employee_name);
 }
}

void display_all()
{
 int j;
 printf("\n\n*******Hash Table*******\n");
 for (j=0; j<SIZE; j++)
 {
  if(emp[j].employee_key != -1)
    printf("LOCATION[%d]--->KEY= %d \t EMP NAME = %s \n",j,emp[j].employee_key, emp[j].employee_name);
  else
    printf("LOCATION[%d]--->EMPTY\n",j);
 }
}

void main()
{
    int ch;
    while (1)
    {
        printf("\n********** Hash function H: K L as H(K)=K mod m (remainder method)****\n\n");
		printf("1. Read Records from the Input file\n");
		printf("2. Display Key Attached Location of Hash Table\n");
		printf("3. Display All Location of Hash Table\n");
		printf("4. Exit\n");
		printf("Enter your choice:\n");
		scanf("%d", &ch);
		switch (ch)
		{
         case 1: read_file();
                 break;
		 case 2: display_attached();
                 break;
		 case 3: display_all();
                 break;
		 case 4: exit(0);
		 default: printf("Invalid Choice\n");
                  break;
		}
    }
}
