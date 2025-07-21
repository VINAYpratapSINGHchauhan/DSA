#include <iostream>
#include <vector>
using namespace std;
int countPrime(int n)
{
    int ans = 0;
    if (n == 0 || n == 1)
    {
        return 0;
    }
    //  step -1 : make an array from 2 to n-1 and mark them as prime true
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    // step -2 : start from 2 till end mark all the numbers flase comes in table of 2 as non prime
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            ans++;
            int j = 2 * i;
            while (j < n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }
    return ans;
}

int GCD(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return (a == 0) ? b : a;
}

int main()
{
    // // solving number of prime numbers from zero to n through sieve of erathothenis theorem getting time complexity of O(nlog(log(n)))
    // int n;
    // cout <<"enter n : ";
    // cin >>n;
    // cout <<"count of prime numbers from 0 to n is : "<<countPrime(n)<<endl;

    // gettign GCD(a,b) where GCD=greatest common divisor and a, b are intergr
    // GCD(a,b)=GCD(a-b,b) when a>b
    // GDCD(a,b=GDC(b-a,a) when b>a
    // apply this formula till one of them become zero
    // GCD(a,0)=a
    int a, b;
    cin >> a;
    cin >>b;
    cout << "GCD of a and  b is : " << GCD(a, b) << endl;
}