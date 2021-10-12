// Write a C++ program to calculate the fibonacci series nth term
// 1 1 2 3 5 8 13 21......

#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return (fib(n - 1) + fib(n - 2));
    }
}

int main()
{
    int n;
    cout << "Enter the nth term of fibonacci series : ";
    cin >> n;
    //loop for printing the fibonacci series upto nth term
    for (int i = 1; i <= n; i++)
    {
        cout << "" << fib(i) << ",";
    }
    //   cout<<"Value of "<<n<<"th term of fibonacci series is : "<<fib(n)<<endl;
    return 0;
}