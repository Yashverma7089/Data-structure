// Write a C++ program to perform the deletion in the different cases in linked list
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

void linkedListTraversal(struct node *ptr)
{
  while (ptr != NULL)
  {
    cout << ptr->data << " -> ";
    ptr = ptr->link;
  }
  cout << "NULL" << endl;
}

//   case 1. Deletion at the first node 
struct node* deletionAtBeginning(struct node* head)
{ 
    struct node * ptr = head;
    head = head->link;
    delete ptr;
    return head;
}

// case 2. Deletion of node in between
struct node* deletionAtIndex(struct node* head, int index)
{
    struct node* ptr = head;
    struct node* ptr1 = head->link;
    int i = 0;
    while(i < index - 1)
    {
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }
    ptr->link = ptr1->link;
    delete ptr1;
    return head;
}

// case 3. Deletion of node at last 
struct node* deletionAtLast(struct node* head)
{
    struct node* ptr = head;
    struct node* ptr1 = head->link;
    
    while (ptr1->link != NULL)
    {
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }
    
    ptr->link = NULL;
    delete ptr1;
    return head;
}

// case 4. Deletion of node with a given node
struct node* deletionOfKey(struct node* head, int key)
{
    struct node* ptr = head;
    struct node* ptr1 = head->link;
    
    while (ptr1->data != key && ptr1->link != NULL)
    {
        ptr = ptr->link;
        ptr1 = ptr1->link;
    }

    if (ptr1->data == key)
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
  head->data = 7;
  head->link = second;

  //   linking second and third node
  second->data = 11;
  second->link = third;

  //   linking third and fourth node
  third->data = 23;
  third->link = fourth;

  //   terminating the fourth node
  fourth->data = 35;
  fourth->link = NULL;
  
  cout<<"Displaying the linked list before deletion"<<endl;
  linkedListTraversal(head);
  // head = deletionAtBeginning(head);
  head = deletionAtIndex(head, 1);
//   head = deletionAtLast(head);
  // head = deletionOfKey(head, 23);
  cout<<"Displaying the linked list after deletion"<<endl;
  linkedListTraversal(head);

  return 0;
}