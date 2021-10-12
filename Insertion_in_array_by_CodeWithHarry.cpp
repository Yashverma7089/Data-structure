// Write a C++ program to insert an element after the given position in array  
 
#include<iostream>
using namespace std;

// this function will traverse the array
void display(int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// this function will insert the array
int indInsertion(int arr[], int size, int element, int index, int capacity)
{
   if(size >= capacity)
   {
       return -1;
   }
   
   for (int  i = size-1; i >= index; i--)
   {
       arr[i+1] = arr[i];
   }
   arr[index] = element;
   return 1;
}

int main()
{
    int arr[100];
    int size, index, element;
    cout<<"Enter the size of array: ";
    cin>>size;
    cout<<"Enter the elements in array: "<<endl;
    for (int  i = 0; i < size; i++)
    { 
       cin>>arr[i];
    }
    
    display(arr, size);

    cout<<"Enter the index after which you want to insert element: ";
    cin>>index;

    cout<<"Enter the element you want to insert : ";
    cin>>element;

    if (indInsertion(arr,size,element, index, 100) == 1)
    {
        size += 1;
        display(arr, size);
    }
  return 0;
}