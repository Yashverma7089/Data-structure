// Write a C++ program to implement the Double Ended Queue (DEQueue) using arrays 
 
#include<iostream>
using namespace std;
 
struct DEQueue
{
  int size;
  int front;
  int rear;
  int *arr;
};

int isEmpty(struct DEQueue* ptr)
{
    if (ptr->front == ptr->rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct DEQueue* ptr)
{
    if (ptr->rear == ptr->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//  enqueueFront
//  enqueueRear
//  dequeueFront
//  dequeueRear
 
void enqueueRear(struct DEQueue* ptr , int value)
{
    if (isFull(ptr))
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        ptr->rear++;
        ptr->arr[ptr->rear] = value;
        cout<<"The enqueued element is : "<<value<<endl;
    }
}

void enqueueFront(struct DEQueue* ptr , int value)
{
    if (isFull(ptr))
    {
        cout<<"Queue is full"<<endl;
    }
    else
    {
        ptr->arr[ptr->front] = value;
        ptr->front--;
        cout<<"The enqueued element is : "<<value<<endl;
    }
}

int dequeueFront(struct DEQueue* ptr)
{
    int value = -1;
    if (isEmpty(ptr))
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        ptr->front++;
        value = ptr->arr[ptr->front];
    }
    return value;
}

int dequeueRear(struct DEQueue* ptr)
{
    int value = -1;
    if (isEmpty(ptr))
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        value = ptr->arr[ptr->rear];
        ptr->rear--;
    }
    return value;
}

void display(struct DEQueue *ptr)
{
    cout << "Displaying the element of queue" << endl;
    for (int i = ptr->front+1; i <= ptr->rear; i++)
    {
        cout<<ptr->arr[i]<<"\t";
    }
    cout << endl;
}

int main()
{
  struct DEQueue q;
  q.size = 100;
  q.front = -1;
  q.rear = -1;
  q.arr = new int[q.size];

//   if (isEmpty(&q))
//   {
//       cout<<"Queue is empty"<<endl;
//   }

  enqueueRear(&q, 4);   
  enqueueRear(&q, 5);   
  enqueueRear(&q, 6);   
  enqueueRear(&q, 7);
  display(&q);
  dequeueFront(&q);
  dequeueFront(&q);
  dequeueFront(&q);
  display(&q);
  enqueueFront(&q, 8);
  enqueueFront(&q, 9);
  enqueueFront(&q, 10);
  display(&q);
  dequeueRear(&q);
  dequeueRear(&q);
  display(&q);
//   if (isFull(&q))
//   {
//       cout<<"Queue is full"<<endl;
//   }
  return 0;
}