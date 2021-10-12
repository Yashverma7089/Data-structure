// write a C++ program to sort the array using quick sort algorithm

#include<iostream>
using namespace std;

// this function will swap the values
void swap(int arr[], int i, int j)
{
	int temp = arr[i];
	    arr[i] = arr[j];
        arr[j] = temp;
}

// this function will give the index of pivot element 
int partition(int arr[], int l, int r)
{
	int pivot = arr[r];
	int i = l - 1;
	
	for(int j = l; j < r; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(arr, i, j);
		}
	} 
	swap(arr, i + 1, r);
	return i + 1;
}

// main quick sort function
void quickSort(int arr[], int l, int r)
{
	if(l < r)
	{
		int pi = partition(arr, l, r);
		
		quickSort(arr, l, pi - 1);
		quickSort(arr, pi + 1, r);
	}
}

int main()
{
    int n;
	cout << "Enter the size of array: ";
	cin>>n;
	int arr[n];
	cout << "Enter the elements in array: ";
	for(int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}
	
	quickSort(arr, 0, n - 1);
	cout << "Quick sort." << endl;
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<"\t";
	}	
	return 0;
}
