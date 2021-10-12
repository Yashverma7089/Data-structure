// Write a C++ program to implement QUEUE using arrays that performs following operations
// (a) INSERT
// (b) DELETE
// (c) DISPLAY

#include <iostream>
using namespace std;

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

void display(struct queue *q)
{
    cout << "Displaying the elements in queue" << endl;
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        cout << q->arr[i] << "\t";
    }
    cout << endl;
}

int isFull(struct queue *q)
{
    if (q->rear == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct queue *q)
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

void insert(struct queue *q, int value)
{
    if (isFull(q))
    {
        cout << "The Queue is full" << endl;
    }
    else
    {
        q->rear++;
        q->arr[q->rear] = value;
        cout << "The inserted element is : " << value << endl;
    }
}

int deletion(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "The Queue is empty" << endl;
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

    int ch;
    cout << "1) Insert element to queue." << endl;
    cout << "1) Delete element from queue." << endl;
    cout << "1) Display element of queue." << endl;
    cout << "1) Exit." << endl;
    do
    {
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            int value, total;
            cout << "Enter how many element you want to insert in queue : ";
            cin >> total;
            cout << endl;
            for (int i = 0; i < total; i++)
            {
                cout << "Enter the element you want to insert in queue : ";
                cin >> value;
                insert(&q, value);
                cout << endl;
            }
            break;

        case 2:
            cout << "Element deleted from the queue is : " << deletion(&q) << endl;
            cout << endl;
            break;

        case 3:
            display(&q);
            cout << endl;
            break;

        case 4:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;

            break;
        }
    } while (ch != 4);

    return 0;
}