#include<stdio.h>
#include<stdlib.h>

struct node
{
 int info;
 struct node *lchild;
 struct node *rchild;
};

typedef struct node* NODE;
NODE getnode()
{
 NODE x;
 x=(NODE) malloc (sizeof(struct node));
 x->lchild=NULL;
 x->rchild=NULL;
 return x;
}

NODE insert(int item, NODE root)
{
 NODE temp,cur,prev;
 temp=getnode();
 temp->info=item;
 if(root==NULL)
 {
  root=temp;
  return root;
 }
 else
 {
  prev=NULL;
  cur=root;
  while (cur!=NULL)
  {
   prev=cur;
   cur=(temp->info<cur->info)?cur->lchild:cur->rchild;
  }
  if(temp->info<prev->info)
     prev->lchild=temp;
  else if(temp->info>prev->info)
     prev->rchild=temp;
 }
 return root;
}

void inorder(NODE ptr1)
{
 if(ptr1!=NULL)
 {
  inorder(ptr1->lchild);
  printf("%d\t",ptr1->info);
  inorder(ptr1->rchild);
 }
}

void preorder(NODE ptr2)
{
 if(ptr2!=NULL)
 {
  printf("%d\t",ptr2->info);
  preorder(ptr2->lchild);
  preorder(ptr2->rchild);
 }
}

void postorder(NODE ptr3)
{
 if(ptr3!=NULL)
 {
  postorder(ptr3->lchild);
  postorder(ptr3->rchild);
  printf("%d\t",ptr3->info);
 }
}

void search(NODE root)
{
 int item,found=0;
 NODE cur;
 printf("Enter the element to be searched : ");
 scanf("%d",&item);
 if(root==NULL)
 {
   printf("Tree is empty\n");
   return;
 }
 cur=root;
 while(cur!=NULL)
 {
  if(item==cur->info)
  {
   found=1;
   printf("Found key %d in Tree\n",cur->info);
  }
 if(item<cur->info)
   cur=cur->lchild;
 else
   cur=cur->rchild;
 }
 if(found==0)
  printf("Key not found\n");
}

void main()
{
 int choice,item,n,i;
 NODE root=NULL;
 while(1)
 {
  printf("\n1. Create BST of N Integers");
  printf("\n2. BST Traversal");
  printf("\n3. Binary Search");
  printf("\n4. Exit");
  printf("\nEnter Your Choice: ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: printf("Enter number of elements : ");
           scanf("%d",&n);
           for (i =0; i<n; i++)
           {
	    printf("Enter the item to be inserted : ");
	    scanf("%d",&item);
	    root=insert(item,root);
	   }
	   break;
   case 2: if(root==NULL)
	     printf("Tree is empty\n");
	   else
	   {
	    printf("\n\nINORDER traversal\n");
	    inorder(root);
            printf("\n\nPREORDER traversal\n");
            preorder(root);
            printf("\n\nPOSTORDER traversal\n");
            postorder(root);
           }
           break;
   case 3:search(root);
           break;
   case 4:return;
   default:printf("\n Invalid Choice\n");
  }
 }
}
