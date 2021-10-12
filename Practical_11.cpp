// Write a C++ program to implement Tree Traversals on Binary Trees.

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = new struct node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct node* root)
{
    if (root != NULL)
    {
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
  struct node * p = new struct node();
  struct node * p1 = new struct node();
  struct node * p2 = new struct node();
  struct node * p3 = new struct node();
  struct node * p4 = new struct node();

  p = createNode(4);
   p1 = createNode(1);
   p2 = createNode(6);
   p3 = createNode(5);
   p4 = createNode(2);

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  cout<<"Tree traversal on binary tree is ";
  preOrder(p);
    return 0;
}