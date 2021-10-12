//Write a C++ Program to implement BST.

#include<iostream>
#include<stdlib.h>

using namespace std;

struct treeNode
{
    int data;
    treeNode *left;
    treeNode *right;
};
treeNode* FindMin(treeNode *node)
{
    if(node==NULL)
    {
        return NULL;
    }
    if(node->left) 
        return FindMin(node->left);
    else
        return node;
}
treeNode *Insert(treeNode *node,int data)
{
    if(node==NULL)
    {
        treeNode *temp;
        temp=new treeNode;
        temp -> data = data;
        temp -> left = temp -> right = NULL;
        return temp;
    }
    if(data >(node->data))
    {
        node->right = Insert(node->right,data);
    }
    else if(data < (node->data))
    {
        node->left = Insert(node->left,data);
    }
    return node;
}
treeNode * Delet(treeNode *node, int data)
{
    treeNode *temp;
    if(node==NULL)
    {
        cout<<"Element Not Found";
    }
    else if(data < node->data)
    {
        node->left = Delet(node->left, data);
    }
    else if(data > node->data)
    {
        node->right = Delet(node->right, data);
    }
    else
    {
        if(node->right && node->left)
        {
            temp = FindMin(node->right);
            node -> data = temp->data;
            node -> right = Delet(node->right,temp->data);
        }
        else
        {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); 
        }
    }
    return node;
}
void Inorder(treeNode *node)
{
    if(node==NULL)
    {
        return;
    }
    Inorder(node->left);
    cout<<node->data<<" ";
    Inorder(node->right);
}

int main()
{
  struct treeNode* root = new struct treeNode();
  root = NULL;
  root = Insert(root, 8); 
  root = Insert(root, 3); 
  root = Insert(root, 1); 
  root = Insert(root, 6); 
  root = Insert(root, 7); 
  root = Insert(root, 10); 
  root = Insert(root, 14); 
  root = Insert(root, 4); 

  cout<<"Inorder Traversal"<<endl;
  Inorder(root);

  cout<<"\nAfter deleting "<<endl;
  root = Delet(root, 10); 

  cout<<"Inorder Traversal"<<endl;
  Inorder(root);
  return 0;
}