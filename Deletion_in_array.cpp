// Write a C++ program to delete an element at the given position in array

#include <iostream>
using namespace std;

// this function will traverse the array
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// this function will delete the array
int indDeletion(int arr[], int size, int index)
{
    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[100];
    int size, index;
    cout << "Enter the size of array: ";
    cin >> size;
    cout << "Enter the elements in array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    display(arr, size);

    cout << "Enter the index at which you want to delete element: ";
    cin >> index;

    indDeletion(arr, size, index);
    size -= 1;
    display(arr, size);
    return 0;
}