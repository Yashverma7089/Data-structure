// Write a C++ program to implement the Quick Sort Algorithm

#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    cout << "Elements in array are : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high, int n)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        // printArray(arr, n);
        quickSort(arr, low, partitionIndex - 1, n);
        quickSort(arr, partitionIndex + 1, high, n);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, n);
    quickSort(arr, 0, n - 1,n);
    printArray(arr, n);
    return 0;
}