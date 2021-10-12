// Write a C++ program to perform the deletion in doubly linked list
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
    struct node *prev;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

//   case 1. Deletion at the first node 
struct node *deletionAtFirst(struct node *head)
{
    struct node *ptr = head;
    head->next->prev = ptr->prev;
    head = head->next;
    delete ptr;
    return head;
}

// case 2. Deletion of node in between
struct node *deletionAtIndex(struct node *head, int index)
{
    struct node *ptr = head;
    struct node *ptr1 = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }

    if (ptr1->next != NULL)
    {
        ptr->next = ptr1->next;
        ptr1->next->prev = ptr;
    }
    else
    {
        ptr->next = ptr1->next;
    }
    delete ptr1;
    return head;
}

// case 3. Deletion of node at last 
struct node *deletionAtLast(struct node *head)
{
    struct node *ptr = head;
    struct node *ptr1 = head->next;
    while (ptr1->next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }

    ptr->next = ptr1->next;
    delete ptr1;
    return head;
}

// case 4. Deletion of node with a given node
struct node * deletionAtKey(struct node* head, int key)
{
   struct node* ptr = head;
   struct node* ptr1 = head->next;
   while (ptr1->data != key && ptr1->next != NULL)
   {
       ptr = ptr->next;
       ptr1 = ptr1->next;
   }

   if(ptr1->data == key && ptr1->next != NULL)
   {
       ptr->next = ptr1->next;
       ptr1->next->prev = ptr;
   }  
   else
   {
       ptr->next = ptr1->next;
   }
   delete ptr1;
   return head;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = new struct node();
    second = new struct node();
    third = new struct node();
    fourth = new struct node();

    head->prev = NULL;
    head->data = 4;
    head->next = second;

    second->prev = head;
    second->data = 5;
    second->next = third;

    third->prev = second;
    third->data = 6;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 7;
    fourth->next = NULL;

    linkedListTraversal(head);
    //   head = deletionAtFirst(head);
    //   head = deletionAtIndex(head, 2);
    // head = deletionAtLast(head);
      head = deletionAtKey(head, 7);
    linkedListTraversal(head);

    return 0;
}