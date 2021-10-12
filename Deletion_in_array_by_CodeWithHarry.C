#include<stdio.h>
#include<conio.h>
int main()
{ int x[10],i,j,size,item,pos;
  
  printf("\nEnter the size of an array: ");
  scanf("%d",&size);
  printf("\nEnter elements in an array\n: ");
  for(i=0;i<size;i++)
  {
   scanf("%d",&x[i]);
   }
//   for(j=0;j<3;j++)
 printf("\nEnter the position where u want to delete element: ");
   scanf("%d",&pos);
//   printf("\nEnter the element which u want to delete: ");
//   scanf("%d",&item);
//   item=x[pos];
   for(i=pos;i<=size-1;i++)
   {
       x[i]=x[i+1];
       }
  size=size-1;
   printf("\nFinal answer of array: ");
   printf("\n");
   for(i=0;i<size;i++)
   {
      printf("%d\t",x[i]);
      }
   getch();
   }
