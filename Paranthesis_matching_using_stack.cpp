// Write a C++ program to solve the Paranthesis problem using stack in array
 
#include<iostream>
using namespace std;
 
struct stack 
{
   int size;
   int top;
   char * arr;
};

void display(struct stack* ptr)
{
    for (int i = 0; i < ptr->top+1; i++)
    {
        cout<<ptr->arr[i]<<" ";
    }
    cout<<endl;
}

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack * ptr)
{
    if (ptr->top == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        cout<<"Stack Overflow ! cannot push element to stack"<<endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}

char pop(struct stack * ptr)
{
    if (isEmpty(ptr))
    {
        cout<<"stack underflow ! cannot pop element from the stack"<<endl;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }    
}

int parenthesisMatching(char * exp)
{
    struct stack * sp = new struct stack();
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    
    if (isEmpty(sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
  char exp[] = "(3*2)+(4/5)";

  if (parenthesisMatching(exp))
  {
      cout<<"The parenthesis is matching"<<endl;
  }
  else
  {
      cout<<"The parenthesis is not matching"<<endl;
  }
  return 0;
}