// Write a C++ program to perform the insertion at different positions in circular linked list.
/* 
    1. Insertion the first node 
    2. Insertion of node in between
    3. Insertion of node at last 
    4. Insertion of node with a given node
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

// case 1 : Insertion at the beginning
struct node *insertionAtFirst(struct node *head, int data)
{
    struct node *ptr = new struct node();
    ptr->data = data;

    struct node *p = head;

    do
    {
        p = p->link;
    }while (p->link != head);

    p->link = ptr;
    ptr->link = head;
    head = ptr;
    return head;
}

// case 2 : Insertion in betweem the linked list
struct node *insertionAtIndex(struct node *head, int data, int index)
{
    struct node *ptr = new struct node();
    ptr->data = data;

    struct node *p = head;

    for (int i = 0; i < index - 1; i++)
    {
        p = p->link;
    }

    ptr->link = p->link;
    p->link = ptr;
    return head;
}

// case 3 : Insertion at the end
struct node *insertionAtLast(struct node *head, int data)
{
    struct node *ptr = new struct node();
    ptr->data = data;

    struct node *p = head;

    do
    {
        p = p->link;
    } while (p->link != head);

    ptr->link = p->link;
    p->link = ptr;
    return head;
}

// case 4 : Insertion after the node
struct node *insertionAfterNode(struct node *head, struct node *prevNode, int data)
{
    struct node *ptr = new struct node();
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
    //   head = insertionAtFirst(head, 10);
    //   head = insertionAtIndex(head, 10, 2);
    // head = insertionAtLast(head, 10);
    head = insertionAfterNode(head, third, 10);
    linkedListTraversal(head);
    return 0;
}