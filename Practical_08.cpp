// Write a C++ program to demonstrate stack that performs following operations using array.
// (a)PUSH
// (b) POP

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

void push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow ! cannot push " << value << " to the stack" << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        cout << "The element " << value << " is pushed to the stack" << endl;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow ! cannot pop element from the stack" << endl;
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

void display(struct stack *ptr)
{
    cout<<"\nDisplaying the elements in the stack"<<endl;
    for (int i = 0; i < ptr->top + 1; i++)
    {
        cout << ptr->arr[i] << "\t";
    }
    cout << endl<<endl;
}

int main()
{
    struct stack *s = new struct stack();
    s->size = 100;
    s->top = -1;
    s->arr = new int[s->size];
    cout<<endl;
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    display(s);

    cout << pop(s) << " is poped from the stack" << endl;
    cout << pop(s) << " is poped from the stack" << endl;
    cout<<endl;
    return 0;
}