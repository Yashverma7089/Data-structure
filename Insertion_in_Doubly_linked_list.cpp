// Write a C++ program to create and perform the insertion in doubly linked list  
/* 
    1. Insertion the first node 
    2. Insertion of node in between
    3. Insertion of node at last 
    4. Insertion of node with a given node
*/

#include<iostream>
using namespace std;

struct node
{
   int data;
   struct node * prev;
   struct node * next;
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

// case 1 : Insertion at the beginning
struct node * insertionAtFirst(struct node * head , int data)
{
  struct node* ptr = new struct node();
  ptr->data = data;
  ptr->next = head;
  ptr->prev = head->prev;
  head->prev = ptr;
  head = ptr;
  return head;
}

// case 2 : Insertion in betweem the linked list
struct node* insertionAtIndex(struct node* head, int index, int data)
{
  struct node* ptr = new struct node();
  ptr->data = data;
  struct node* p = new struct node();
  p = head;
  for (int i = 0; i < index - 1; i++)
  {
    p = p->next;
  }
  ptr->next = p->next;
  p->next->prev = ptr;
  p->next = ptr;
  ptr->prev = p;
  return head;
}

// case 3 : Insertion at the end
struct node * insertionAtLast(struct node* head, int data)
{
  struct node * ptr = new struct node();
  ptr->data = data;
  struct node* p = head;
  while (p->next != NULL)
  {
    p = p->next; 
  }
  ptr->next = p->next;
  p->next = ptr;
  ptr->prev = p;
  return head;
}

// case 4 : Insertion after the node
struct node* insertionAfterNode(struct node * head, struct node * prevNode, int data)
{
  struct node * ptr = new struct node();
  ptr->data = data;
  ptr->next = prevNode->next;
  prevNode->next->prev = ptr;
  prevNode->next = ptr;
  ptr->prev = prevNode;
  return head;
}

int main()
{
  struct node * head;
  struct node * second;   
  struct node * third;   
  struct node * fourth; 

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
  // head = insertionAtFirst(head, 3);
  // head = insertionAtIndex(head, 2, 3);
  // head = insertionAtLast(head, 3);
  head = insertionAfterNode(head, second, 3);
  linkedListTraversal(head);

  return 0;
}