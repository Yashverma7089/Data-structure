// Write a C++ program to create a linked list and perform traversal of linked list

#include <iostream>
#include <stdlib.h>
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

int main()
{
  struct node *head;
  struct node *second;
  struct node *third;
  struct node *fourth;

  //  allocating the memory to the node dynamically
  head = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));
  fourth = (struct node *)malloc(sizeof(struct node));

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

  linkedListTraversal(head);
  return 0;
}