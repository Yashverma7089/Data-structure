// write a C++ program to sort the array using merge sort

#include <iostream>
using namespace std;

// this function will merge the sorted array
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int a[n1], b[n2];

	for (int i = 0; i < n1; i++)
		a[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		b[j] = arr[m + 1 + j];

	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2)
	{
		if (a[i] <= b[j])
		{
			arr[k] = a[i];
			i++;
		}
		else
		{
			arr[k] = b[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = a[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = b[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r)
{
	if (l >= r)
	{
		return;
	}
	int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

void print(int arr[], int n)
{
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
	mergeSort(arr, 0, n - 1);
	cout << "Merge sort." << endl;
	print(arr, n);
	return 0;
}
