#include<stdio.h>
int main()
{ int x[10],i,size,item,pos;
  //clrscr();
  printf("\nEnter the size of an array: ");
  scanf("%d",&size);
  printf("\nEnter elements in an array: ");
  for(i=0;i<size;i++)
  {
   scanf("%d",&x[i]);
   }
   printf("\nEnter the position where u want to insert element: ");
   scanf("%d",&pos);
   printf("\nEnter the element which u want to insert: ");
   scanf("%d",&item);
   for(i=size;i>=pos;i--)
   {
       x[i+1]=x[i];
       }
   x[pos]=item;
   //size=size+0;
   printf("\nFinal answer of array: ");
   printf("\n");
   for(i=0;i<=size;i++)
   {
      printf("%d\t",x[i]);
      }
   //getch();
   }

