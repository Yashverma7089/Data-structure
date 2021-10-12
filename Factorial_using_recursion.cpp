// Write a C++ program to calculate the factorial of a number using recursion

#include <iostream>
using namespace std;

long factorial(int n)
{
    if (n > 0)
    {
        return (n * factorial(n - 1));
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n;
    cout << "Enter the number : ";
    cin >> n;
    cout << "The factorial of " << n << " is : " << factorial(n) << endl;
    return 0;
}