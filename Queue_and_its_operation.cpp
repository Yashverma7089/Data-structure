// Write a C++ program to implement the Queue and its properties 
 
#include<iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
 
void display(struct queue* q)
{
    cout<<"Displaying the elements in queue"<<endl;
    for (int i = q->front+1; i <= q->rear; i++)
    {
        cout<<q->arr[i]<<"\t";
    }
    cout<<endl;
}

int isFull(struct queue * q)
{
    if (q->rear == q->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue* q)
{
    if (q->rear == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue * q, int value)
{
    if (isFull(q))
    {
        cout<<"The Queue is full"<<endl;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
        cout<<"The enqueued element is : "<<value<<endl;
    }    
}

int dequeue(struct queue * q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout<<"The Queue is empty"<<endl;

    }
    else
    {
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}

int main()
{
 struct queue q;
 q.size = 100;
 q.front = -1;
 q.rear = -1;
 q.arr = new int[q.size];

//  if (isEmpty(&q))
//  {
//      cout<<"Queue is Empty"<<endl;
//  }
    enqueue(&q, 16);
    enqueue(&q, 15);
    enqueue(&q, 14);
    enqueue(&q, 13);
    enqueue(&q, 12);

    display(&q);
    cout<<"The dequeued element is : "<<dequeue(&q)<<endl;
    display(&q);
    // cout<<"The dequeued element is : "<<dequeue(&q)<<endl;
    // cout<<"The dequeued element is : "<<dequeue(&q)<<endl;
    // cout<<"The dequeued element is : "<<dequeue(&q)<<endl;
    return 0;
}