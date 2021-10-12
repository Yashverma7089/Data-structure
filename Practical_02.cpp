// Write a Program to search an element in the array using Linear Search

#include<iostream>

using namespace std;

int linearSearch(int array[],int n, int key)
{
	for(int i=0; i<n; i++)
	{
		if(array[i]==key)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
  int n;
  cout<<"Enter the size of an array: ";
  cin>>n;
  
  int array[n],key;
  
  cout<<"Enter the elements in array: ";
  for(int i=0; i<n; i++)
  {
  	cin>>array[i];
  }
  
  cout<<"Enter the element you want to search: ";
  cin>>key;
  
  cout<<"Element found at the "<<linearSearch(array,n,key)<<" position"<<endl;
  
 return 0;
}

