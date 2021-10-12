// Write a Program to demonstrate the working of Bubble Sort

#include<iostream>

using namespace std;

int main()
{
	int n;
	cout<<"Enter the size of array: ";	
	cin>>n;
	int arr[n];
	cout<<"Enter the elements in array: ";
    for(int i=0; i<n; i++)
    {
    	cin>>arr[i];
	}
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{                                                 
			if(arr[j]>arr[j+1])                          
			{
			int temp = arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	cout<<"Bubble sorting "<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}

 return 0;
}
