// Write a C++ program to implememt the selection Sort Algorithm

#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int *arr, int n)
{
    cout << "Sorting the array using Selection Sort Algorithm " << endl;
    int min_index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}