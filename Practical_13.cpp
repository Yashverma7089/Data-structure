// Write a Program to demonstrate the working of Selection Sort

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << "Selection Sort" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}

int main()
{
	int n;
	cout << "Enter the size of array: ";
	cin >> n;
	int arr[n];
	cout << "Enter the elements in array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
 selectionSort(arr,n);
	return 0;
}
