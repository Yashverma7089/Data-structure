// Write a C++ program to print all the permutations of a given string 
 
#include<iostream>
using namespace std;

void swap(char *x, char *y)
{
    char ch;
    ch = *x;
    *x = *y;
    *y = ch;
}

void permutation(string s, int i, int n)
{
    static int count;
    int j;
    if (i==n)
    {
        count++;
        cout<<"("<<count<<") "<<s<<endl;
    }
    else
    {
        for ( j = i; j <= n ; j++)
        {
            swap(s[i], s[j]);
            permutation(s,i+1,n);
            swap(s[i], s[j]);
        }
    }
}

int main()
{
  string s;
  cout<<"Enter the string : ";
  getline(cin, s);
  permutation(s,0,s.length()-1); 
  return 0;
}