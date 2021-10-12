// Write a C++ program to convert the infix expression into postfix expression using stack 
 
#include<iostream>
#include<string.h>
using namespace std;
 
struct stack 
{
  int size;
  int top;
  char *arr;
};

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

void push(struct stack * ptr, char value)
{
    if (isFull(ptr))
    {
        cout<<"Stack Overflow ! cannot push element to the stack"<<endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

char pop(struct stack * ptr)
{
    if (isEmpty(ptr))
    {
        cout<<"Stack Underflow ! cannot poped element from the stack"<<endl;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

char stackTop(struct stack* ptr)
{
   return ptr->arr[ptr->top];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }    
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' )
    {
        return 1;
    }
    else
    {
        return 0;
    }       
}

char * infixToPostfix(char * infix)
{
  struct stack * sp = new struct stack();
  sp->size = 100;
  sp->top = -1;
  sp->arr = new char[sp->size];
  char * postfix = new char[strlen(infix)+1];
  int i = 0; // To track the infix traversal
  int j = 0; // To track the addition in postfix
  while (infix[i] != '\0')
  {
      if (!isOperator(infix[i]))
      {
          postfix[j] = infix[i];
          i++;
          j++;
      }
      else
      {
          if (precedence(infix[i]) > precedence(stackTop(sp)))
          {
              push(sp, infix[i]);
              i++;
          }
          else
          {
              postfix[j] = pop(sp);
              j++;
          }
      }      
  }
  
  while (!isEmpty(sp))
  {
      postfix[j] = pop(sp);
      j++;
  }
  postfix[j] = '\0';
  return postfix;
}

int main()
{
    char infix[] = "p-q-r/a";
    cout<<"The Postfix expression of "<<infix<<" is : "<<infixToPostfix(infix);         
  return 0;
}