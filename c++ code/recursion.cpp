#include <iostream>
#include <vector>
using namespace std;
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

void backCounting(int n)
{
    if (n == 0)
        return;
    cout << n << " ";
    backCounting(n - 1);
}

void frontCounting(int n)
{
    if (n == 0)
        return;
    frontCounting(n - 1);
    cout << n << " ";
}

int fib(int n)
{
    if (n == 1)
        return 1;
    if (n == 0)
        return 0;
    return (fib(n - 1) + fib(n - 2));
}
int main()
{
    // recurison means function  k andr function

    int n;

    // 1. factorial using recursion
    cout << "enter n : ";
    cin >> n;
    cout << "factorail of n is : " << factorial(n) << endl;

    // 2. printing back counting  --tail rrecursion
    backCounting(n);
    cout << endl;

    // 3. printing front counting --head recursion
    frontCounting(n);
    cout << endl;

    // 4. printing nth term of fibonacci series
    cout << "nth term of fibonacci series is : " << fib(n) << endl;

    
}