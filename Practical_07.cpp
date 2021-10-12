// Write a Program to add two Polynomials using Linked List

#include <iostream>
#include <malloc.h>
using namespace std;
struct node
{
  int coeff, expo;
  struct node *link;
};

char ch;
struct node *poly1, *new1, *p1, *poly2, *new2, *p2;

// Create first polynomial
void create()
{
  cout << "\nenter first polynomial\n";
  do
  {
    new1 = (struct node *)malloc(sizeof(struct node));
    cout << "enter the coefficient and exponential\n";
    cin >> new1->coeff;
    cin >> new1->expo;
    new1->link = NULL;

    if (poly1 == NULL)
    {
      poly1 = new1;
      p1 = new1;
    }
    else
    {
      p1->link = new1;
      p1 = new1;
    }

    cout << "do you want to add a new node press (y/n)";
    cin >> ch;
  } while (ch == 'y');
}

// Create second polynomial
void create1()
{
  cout << "\nenter second polynomial\n\n";
  do
  {
    new2 = (struct node *)malloc(sizeof(struct node));
    cout << "enter the coefficient and exponential\n";
    cin >> new2->coeff;
    cin >> new2->expo;
    new2->link = NULL;

    if (poly2 == NULL)
    {
      poly2 = new2;
      p2 = new2;
    }
    else
    {
      p2->link = new2;
      p2 = new2;
    }

    cout << "do you want to add a new node press (y/n)";
    cin >> ch;
  } while (ch == 'y');
}

// Display first polynomial
void display()
{
  cout << "\n\npolynomials are displaying\n\n";
  p1 = poly1;
  cout << "first polynomial is: \n";

  while (p1 != NULL)
  {
    cout << p1->coeff << "x^" << p1->expo;

    p1 = p1->link;
    if (p1 != NULL)
    {
      cout << "+";
    }
  }
}

// Display second polynomial
void display1()
{
  p2 = poly2;
  cout << "\n\nsecond polynomial is: \n";

  while (p2 != NULL)
  {
    cout << p2->coeff << "x^" << p2->expo;

    p2 = p2->link;
    if (p2 != NULL)
    {
      cout << "+";
    }
  }
}

// Addition of two polynomials
void addition()
{
  cout << "\n\naddition of polynomial is\n\n";
  p1 = poly1;
  p2 = poly2;

  while (p1 != NULL && p2 != NULL)
  {
    if (p1->expo == p2->expo)
    {
      cout << p1->coeff + p2->coeff << "x^" << p1->expo;
      p1 = p1->link;
      p2 = p2->link;
    }
    else if (p1->expo > p2->expo)
    {
      cout << p1->coeff << "x^" << p1->expo;
      p1 = p1->link;
    }
    else
    {
      cout << p2->coeff << "x^" << p2->expo;
      p2 = p2->link;
    }

    if (p1 != NULL || p2 != NULL)
    {
      cout << "+";
    }
  }

  while (p1 != NULL)
  {
    cout << p1->coeff << "x^" << p1->expo;
    p1 = p1->link;
    if (p1 != NULL)
    {
      cout << "+";
    }
  }

  while (p2 != NULL)
  {
    cout << p2->coeff << "x^" << p2->expo;
    p2 = p2->link;
    if (p2 != NULL)
    {
      cout << "+";
    }
  }
}

int main()
{
  create();
  create1();
  display();
  display1();
  addition();
  return 0;
}
