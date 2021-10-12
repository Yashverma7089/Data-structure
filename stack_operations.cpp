// Write a C++ program to perform the push and pop operations on a stack

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

void display(struct stack *ptr)
{
    for (int i = 0; i < ptr->top + 1; i++)
    {
        cout << ptr->arr[i] << " ";
    }
    cout << endl;
}

void Push(struct stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overfloaw ! Cannot push " << value << " in the stack." << endl;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}

int Pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underfloaw ! Cannot pop from the stack." << endl;
        return -1;
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
    }
}

int peek(struct stack *ptr, int i)
{
    int arrIn = ptr->top - i + 1;
    if (arrIn < 0)
    {
        cout << "Position is not valid" << endl;
        return -1;
    }
    else
    {
        return ptr->arr[arrIn];
    }
}

int stackTop(struct stack * ptr)
{
    return ptr-> arr[ptr->top];
}

int stackBottom(struct stack * ptr)
{
    return ptr->arr[0];
}

int main()
{
    struct stack *s = new struct stack();
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];

    Push(s, 4);
    Push(s, 5);
    Push(s, 6);
    Push(s, 7);
    Push(s, 8);
    Push(s, 3);
    Push(s, 7);
    Push(s, 6);
    //   Push(s,4);
    //   display(s);
    //   for (int i = 1; i <= s->top+1 ; i++)
    //   {
    //     cout<<"The value at "<<i<<" position is : "<<peek(s,i)<<endl;
    //   }
    //   peek(s,1);
    // display(s);
    // Pop(s);
    // display(s);
    cout<<"The top most element of the stack is : "<<stackTop(s)<<endl;
    cout<<"The bottom most element of the stack is : "<<stackBottom(s)<<endl;
    // //   cout<<Pop(s)<<" is poped from the stack"<<endl;
    //   cout<<Pop(s)<<" is poped from the stack"<<endl;
    //   cout<<Pop(s)<<" is poped from the stack"<<endl;
    return 0;
}