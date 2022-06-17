#include<stdio.h>
#include<string.h>
char str[100],pat[100],rep[100],ans[100];
int i=0,m=0,c=0,j=0,k=0,found=0;

void stringmatch()
{
 while(str[c]!='\0')
 {
  if(str[i]==pat[j])
  {
   j++;
   i++;
   if(pat[j]=='\0')
   {
    j=0;
    found=1;
    for(k=0;rep[k]!='\0';k++,m++)
    {
     ans[m]=rep[k];
    }
    c=i;
   }
  }
  else
  {
   ans[m]=str[c];
   m++;
   c++;
   i=c;
   j=0;
  }
 }
}

void main()
{
 printf("Enter the main String\n");
 scanf("%s",str[100]);
 printf("\nEnter the pattern string\n");
 gets(pat);
 printf("\nEnter the replacement string\n");
 gets(rep);
 stringmatch();
 if(found==1)
  printf("\nThe Resultant String is %s\n",ans);
 else
  printf("\nThe Pattern is not found \n");
}

