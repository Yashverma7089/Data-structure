// Write a C++ program to implement the Count Sort Algorithm

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

int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n)
{
    int i, j;
    int max = maximum(arr, n);
    int *count = new int[max + 1];
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    i = 0; // will traverse the count array
    j = 0; // will traverse the main array

    while (i < max + 1)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
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
    countSort(arr, n);
    printArray(arr, n);
    return 0;
}