// Write a C++ program to calculate the greatest common divisor using recursion

#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (a == b)
    {
        return a;
    }

    if (a % b == 0)
    {
        return b;
    }

    if (b % a == 0)
    {
        return a;
    }

    if (a > b)
    {
        return GCD(a % b, b);
    }
    else
    {
        return GCD(a, b % a);
    }
}

int main()
{
    int a, b;
    cout << "Enter the first number : ";
    cin >> a;
    cout << "Enter the second number : ";
    cin >> b;
    cout<<"GCD of "<<a<<" and "<<b<<" is : "<<GCD(a,b)<<endl;
    return 0;
}