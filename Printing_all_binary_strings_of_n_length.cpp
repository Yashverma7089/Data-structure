// Write a C++ program to print all the binary strings of n length

#include <iostream>
using namespace std;

void bin(int n, char arr[])
{
    if (n < 1)
    {
        cout << arr << endl;
    }
    else
    {
        arr[n - 1] = '0';
        bin(n - 1, arr);
        arr[n - 1] = '1';
        bin(n - 1, arr);
    }
}

int main()
{
    char arr[4];
    arr[4] = '\0';
    bin(3, arr);
    return 0;
}