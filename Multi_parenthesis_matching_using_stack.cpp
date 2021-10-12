// Write a C++ program to implement the multi parentheses matching problem using stack 
 
#include<iostream>
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

int match(char a, char b)
{
    if (a=='(' && b==')')
    {
        return 1;
    }
    if (a=='{' && b=='}')
    {
        return 1;
    }
    if (a=='[' && b==']')
    {
        return 1;
    }
    return 0;
}

int multiParenthesisMatching(char * exp)
{
    struct stack *sp = new struct stack();
    sp->size = 100;
    sp->top = -1;
    sp->arr = new char[sp->size];
    char poped_ch;

    for (int i = 0; exp[i] != '\0' ; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']' )
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            poped_ch = pop(sp);
            if (match(poped_ch, exp[i]) != 1)
            {
                return 0;
            }
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
    char exp[] = "[ 4 + 3 ] { 4 * ( 3 + 4 ) / 2 }";

    if (multiParenthesisMatching(exp))
    {
        cout<<"The Parenthesis is matching"<<endl;
    }
    else
    {
        cout<<"The Parenthesis is not matching"<<endl;
    }
         
  return 0;
}