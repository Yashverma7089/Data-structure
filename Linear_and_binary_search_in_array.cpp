// Write a C++ program for linear and binary search in array

#include <iostream>
using namespace std;

// The time complexity of Linear Search is O(n)
int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

// The time complexity of Binary Search is O(logn)
int binarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }

        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int size, element;
    cout << "Enter the size of array : ";
    cin >> size;
    int arr[size];
    cout << "Enter the elements in array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element you want to search : ";
    cin >> element;
    // int searchIndex = linearSearch(arr, size, element);
    int searchIndex = binarySearch(arr, size, element);

    if (searchIndex != -1)
    {
        cout << "The element " << element << " is found at " << searchIndex << " index in the array." << endl;
    }
    else
    {
        cout << "The element " << element << " is not found in the array." << endl;
    }
    return 0;
}