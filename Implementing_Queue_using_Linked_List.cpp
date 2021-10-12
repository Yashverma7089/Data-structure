// Write a C++ program to implement the queue using linked list

#include <iostream>
using namespace std;

struct node *front = NULL;
struct node *rear = NULL;

struct node
{
    int data;
    struct node *next;
};

int isEmpty(struct node *front)
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int value)
{
    struct node *ptr = new struct node();
    if (ptr == NULL)
    {
        cout << "The Queue is full" << endl;
    }
    else
    {
        ptr->data = value;
        ptr->next = NULL;
        if (front == NULL)
        {
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}

int dequeue()
{
    int value = -1;
    struct node *ptr = front;
    if (isEmpty(front))
    {
        cout << "The Queue is empty" << endl;
    }
    else
    {
        front = front->next;
        value = ptr->data;
        delete ptr;
    }
    return value;
}

void display(struct node *ptr)
{
    cout << "Displaying the element of queue" << endl;
    // ptr = front;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{ 

    cout << isEmpty(front) << endl;
    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    enqueue(16);
    display(front);
    dequeue();
    display(front);
    return 0;
}