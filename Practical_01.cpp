// Write a Program to demonstrate the working of Traversing, Insertion at specified Location and deletion in an Array.

#include <iostream>

using namespace std;

void traversal(int arr[], int size)
{
	cout << "Elements in array are:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}

int Insertion(int arr[], int size, int element, int index, int capacity)
{
	if (size >= capacity)
	{
		return -1;
	}

	for (int i = size - 1; i >= index; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[index] = element;
	return 1;
}

int Deletion(int arr[], int size, int index)
{
	for (int i = index; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
}

int main()
{
	int arr[100];
	int n, size, item, pos;
	cout << "Enter the size of array: ";
	cin >> size;
	cout << "Enter the elements in array: ";
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	do
	{
		int ch;
		cout << "\nMenu of operations can be perfomed on array :-" << endl;
		cout << "1. Traversal of array" << endl;
		cout << "2. Insertion at specified location" << endl;
		cout << "3. Deletion in an array" << endl;
		cout << "\n Enter your choice: ";
		cin >> ch;

		switch (ch)
		{
		case 1:
			traversal(arr, size);
			break;

		case 2:
			cout << "Enter the position where you want to insert element: ";
			cin >> pos;
			cout << "Enter the element which you want to insert: ";
			cin >> item;
			if (Insertion(arr, size, item, pos, 100) == 1)
			{
				size += 1;
				traversal(arr, size);
			}
			break;

		case 3:
			cout << "Enter the position where you want to perform deletion: ";
			cin >> pos;
			Deletion(arr, size, pos);
			size -= 1;
			traversal(arr, size);
			break;

		default:
			cout << "Wrong choice" << endl;
		}
		cout << "\nDo you want to continue press (1/0): ";
		cin >> n;
	} while (n >= 1 && n <= 9);

	return 0;
}
