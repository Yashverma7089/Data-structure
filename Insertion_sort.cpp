// Write a C++ program to implememt the Insertion Sort Algorithm
 
#include<iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int *arr, int n)
{
    int key;
    for (int i = 1; i <= n-1; i++)
    {
        key = arr[i];
        int j = i-1;
        while (arr[j] > key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main()
{
  int n;
  cout<<"Enter the size of the array : ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements in array : ";
  for (int i = 0; i < n; i++)
  {
      cin>>arr[i];
  }
  printArray(arr,n);
  insertionSort(arr,n);
  printArray(arr,n);
  return 0;
}