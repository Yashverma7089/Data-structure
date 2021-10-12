// Write a C++ program to implement the stack using linked list. 
 
#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

// it will print the elements in stack
void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout<<ptr->data<<" -> ";
        ptr = ptr->next; 
    }
    cout<<"NULL"<<endl;
}

// to check whether stack is empty or not 
int isEmpty(struct node * top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// to check whether stack is full or not 
int isFull(struct node * top)
{
    struct node * ptr = new struct node();
    if (ptr == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// will push the element to stack
struct node * push(struct node * top, int value)
{
    if (isFull(top))
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
        struct node *ptr = new struct node();
        ptr->data = value;
        ptr->next = top;
        top = ptr;
        return top;
    }
}

// will pop the element from stack
int pop(struct node **top)
{
    if (isEmpty(*top))
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        struct node *ptr = *top;
        *top = (*top)->next;
        int x = ptr->data;
        delete ptr;
        return x;
    }
}

// will return the value at given position
int peek(struct node * top, int pos)
{
    struct node * ptr = top;
    for (int i = 0; (i < pos-1 && ptr != NULL) ; i++)
    {
        ptr = ptr->next;
    }
    
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

// will give the topmost element of stack
int stackTop(struct node* top)
{
    return top->data;
}

// will give the bottommost element of stack
int stackBottom(struct node* top)
{
    struct node * ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
  struct node *top = NULL; 
//   isEmpty(top);
//   isFull(top);
  top = push(top, 10);
  top = push(top, 11);
  top = push(top, 12);
  top = push(top, 13);
  top = push(top, 14);
  linkedListTraversal(top);

  for (int  i = 1; i <= 5; i++)
  {
    cout<<"Element at " <<i<<" position is : "<<peek(top, i)<<endl;
  }

  cout<<"Top most element in the stack is : "<<stackTop(top)<<endl;  
  cout<<"Bottom most element in the stack is : "<<stackBottom(top)<<endl;  
//   int element = pop(&top);
//   cout<<"Poped element is : "<<element<<endl;
//   linkedListTraversal(top);
  return 0;
}