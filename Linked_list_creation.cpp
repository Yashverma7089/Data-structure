#include<stdio.h>
#include<malloc.h>
typedef struct  linklist
{ int info;
  struct linklist *next;
 }NODE;
NODE *insert(NODE *start,int info)
{ NODE *temp,*t;
  temp=(NODE*)malloc(sizeof(NODE));
  // -> referential operator(value at address)
  temp->info=info;
  temp->next=NULL;
  if(start==NULL)
  {start=temp;
   return(start);}
  else
  { t=start;
    while(t->next!=NULL)
    {t=t->next;}
    t->next=temp;
    return(start);
    }
}

void display(NODE *start)
{ NODE *t;
  if(start==NULL)
  {printf("List is EMPTY...");
  }
  else
  { t=start;
  while(t)
  {
   printf("%d,",t->info);
   t=t->next;
  }
}
}
void main()
{  NODE *start=NULL;
   start=insert(start,55);
   start=insert(start,66);
   start=insert(start,77);
   start=insert(start,88);
   display(start);
}