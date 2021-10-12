// Write a C++ program to implement the Circular Queue and its properties 
 
#include<iostream>
using namespace std;

struct circularQueue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isEmpty(struct circularQueue* q)
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

int isFull(struct circularQueue * q)
{
    if ((q->rear+1)%q->size == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct circularQueue* q, int value)
{
    if (isFull(q))
    {
        cout<<"The Queue is full "<<endl;
    }
    else
    {
        q->rear = (q->rear+1)%q->size;
        q->arr[q->rear] = value;
        cout<<"Enqueued element is : "<<value<<endl;
    }
}

int dequeue(struct circularQueue* q)
{
    int value = -1;
    if (isEmpty(q))
    {
        cout<<"The Queue is empty"<<endl;
    }
    else
    {
        q->front = (q->front+1) % q->size;
        value = q->arr[q->front];
    }
    return value;
}

int main()
{
  struct circularQueue q;
  q.size = 4;
  q.front = 0;
  q.rear = 0;
  q.arr = new int[q.size];

enqueue(&q,12);
enqueue(&q,13);
enqueue(&q,14);
// enqueue(&q,15); // will not be added to the queue because queue is full 

cout<<"The dequeued element is : "<<dequeue(&q)<<endl;
cout<<"The dequeued element is : "<<dequeue(&q)<<endl;
cout<<"The dequeued element is : "<<dequeue(&q)<<endl;
// cout<<"The dequeued element is : "<<dequeue(&q)<<endl; //// will not be added to the queue because queue is full 
enqueue(&q,41);
enqueue(&q,42);
enqueue(&q,43);
 

  if(isEmpty(&q))
  {
     cout<<"Queue is Empty"<<endl;
  } 
  else
  {
     cout<<"Queue is not Empty"<<endl;
  }

  if(isFull(&q))
  {
     cout<<"Queue is full"<<endl;
  } 
  else
  {
     cout<<"Queue is not full"<<endl;
  }

  return 0;
}