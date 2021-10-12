// Write a C++ program to perform the Deletion at different positions in circular linked list.
/* 
    1. Deletion the first node 
    2. Deletion of node in between
    3. Deletion of node at last 
    4. Deletion of node with a given node
*/
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

void linkedListTraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        cout << ptr->data;
        if (ptr->link != head)
        {
            cout << " -> ";
        }
        else
        {
            break;
        }

        ptr = ptr->link;
    } while (ptr != head);
    cout << endl;
}

//   case 1. Deletion at the first node
struct node * deletionAtFirst(struct node * head)
{
    struct node * current = head;
    struct node * previous = head;
    while (previous->link != current)
    {
        previous = previous->link;
    }
    previous->link = current->link;
    head = previous->link;
    delete current;
    return head;
}

// case 2. Deletion of node in between
struct node * deletionAtIndex(struct node * head, int index)
{
    struct node * ptr = head;
    struct node * ptr1 = head->link;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }
    ptr->link = ptr1->link;
    delete ptr1;
    return head;
}

// case 3. Deletion of node at last 
struct node * deletionAtLast(struct node * head)
{
    struct node * ptr = head;
    struct node * ptr1 = head->link;
    while(ptr1->link != head)
    {
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }
    ptr->link = ptr1->link;
    delete ptr1;
    return head;
}

// case 4. Deletion of node with a given node
struct node * deletionOfKey(struct node * head, int key)
{
   struct node * ptr = head;
   struct node * ptr1 = head->link;
   while (ptr1->data != key && ptr1->link != head)
   {
       ptr = ptr->link;
       ptr1 = ptr1->link;
   }

   if(ptr1->data == key)
   {
      ptr->link = ptr1->link;
      delete ptr1;
   }
   return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    //  allocating the memory to the node dynamically
    head = new struct node();
    second = new struct node();
    third = new struct node();
    fourth = new struct node();

    //   linking first and second node
    head->data = 4;
    head->link = second;

    //   linking second and third
    second->data = 5;
    second->link = third;

    //   linking third and fourth node
    third->data = 6;
    third->link = fourth;

    //   linking fourth and head node
    fourth->data = 7;
    fourth->link = head;

    linkedListTraversal(head);
    //   head = deletionAtFirst(head);
    //   head = deletionAtIndex(head, 2);
    // head = deletionAtLast(head);
    head = deletionOfKey(head, 6);
    linkedListTraversal(head);
    return 0;
}