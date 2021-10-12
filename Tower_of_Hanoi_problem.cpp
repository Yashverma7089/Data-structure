// Write a C++ program to solve the problem of Tower of Hanoi 
 
#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char A, char B , char C)
{
    if (n >= 1)
    {
        TowerOfHanoi(n-1, A, C, B);
        // cout<<"Disc moves from "<<A<<" to "<<C<<endl;
        cout<<"("<<A<<" -> "<<C<<"),\t";
        TowerOfHanoi(n-1, B, A, C);
    }
}

int main()
{
  int n;
  cout<<"Enter the number of discs you want : ";
  cin>>n;
  TowerOfHanoi(n, 'A', 'B', 'C');
  return 0;
}