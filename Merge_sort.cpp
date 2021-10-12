// Write a C++ program to implement the Merge Sort Algorithm

#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int *B = new int[high - low + 1];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            B[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            B[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        B[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        B[k] = arr[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = B[i];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    int n;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements in array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);
    printArray(arr, n);
    return 0;
}