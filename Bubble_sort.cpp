// Write a C++ program to implement the bubble sort algorithm

#include <iostream>
using namespace std;

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t ";
    }
    cout << endl;
}

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++) // for the number of passes in the array
    {
        cout << "Pass no = " << i + 1 << endl;
        for (int j = 0; j < n - 1 - i; j++) // for the comparision in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                ;
            }
        }
    }
}

void bubbleSortAdaptive(int *arr, int n)
{
    int isSorted;
    for (int i = 0; i < n - 1; i++) // for the number of passes in the array
    {
        cout << "Pass no = " << i + 1 << endl;
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // for the comparision in each pass
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Elements befor sorting" << endl;
    printArray(arr, n);
    // bubbleSort(arr, n);
    bubbleSortAdaptive(arr, n);
    cout << "Elements after sorting" << endl;
    printArray(arr, n);
    return 0;
}