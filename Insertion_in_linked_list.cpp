// Write a C++ program to perform the insertion at the different positions in the linked list

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
        cout << ptr->data << "->";
        ptr = ptr->link;
    }
    cout << "NULL" << endl;
}

// case 1 : Insertion at the beginning 
struct node* insertionAtBeginning(struct node* head, int data)
{
    struct node* ptr = new struct node();
    ptr->data = data;
    ptr->link = head;
    head = ptr;
    return head;
}

// case 2 : Insertion in betweem the linked list  
struct node* insertionAtIndex(struct node* head, int data, int index)
{
    struct node* ptr = new struct node();
    ptr->data = data;
    struct node* p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->link;
        i++;    
    }
    ptr->link = p->link;
    p->link = ptr;
    return head;
}

// case 3 : Insertion at the end
struct node* insertionAtEnd(struct  node* head, int data)
{
    struct node* ptr = new struct node();
    ptr->data = data;
    struct node* p = head;

    while (p->link != NULL)
    {
        p = p->link;
    }
    
    p->link = ptr;
    ptr->link = NULL;
    return head;
}

// case 4 : Insertion after the node 
struct node* insertionAfterNode(struct node* head, struct node* prevNode, int data)
{
    struct node* ptr = new struct node();
    ptr->data = data;
    ptr->link = prevNode->link;
    prevNode->link = ptr;
    return head;
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
    // head = insertionAtBeginning(head, 56);
    // head = insertionAtIndex(head, 56, 1);
    // head = insertionAtEnd(head, 56);
    head = insertionAfterNode(head, third, 56);
    linkedListTraversal(head);
    return 0;
}