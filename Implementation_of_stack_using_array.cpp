// Write a C++ program to implement the stack using array

#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *arr;
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

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
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
    struct stack *s = new struct stack();
    //    s->size = 80;
    s->size = 90;
    s->top = -1;
    s->arr = new int[s->size];

    if (isEmpty(s))
    {
        cout << "The Stack is empty." << endl;
    }
    else
    {
        cout << "The Stack is not empty." << endl;
    }

    if (isFull(s))
    {
        cout << "The stack is full" << endl;
    }
    else
    {
        cout << "The stack is not full" << endl;
    }
    return 0;
}