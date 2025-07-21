#include <iostream>
#include <vector>
#include <cmath>
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
    for (int i = 2; i < n; i++) // optimization 2 : as our loop from to i*i it can be out of our array so that use (i=1;i<=sqrt(n);i++) for better uproach this should be done when counting the prime that is ans++ is in another loop
    {
        if (prime[i])
        {
            ans++;
            int j = 2 * i; // optimization 1 : for optimization replce this line with - " int j= i*i ; " as j till (i-1)*2 are already marked
            while (j < n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }
    return ans;
}
int fastCountPrime2(int n) // with  optimization 1
{
    int ans = 0;
    if (n == 0 || n == 1)
    {
        return 0;
    }

    // Step 1: Mark all numbers as prime
    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;

    // Step 2: Sieve - mark non-primes
    int N = sqrt(n);
    for (int i = 2; i <= N; i++)
    {
        if (prime[i])
        {
            int j = i * i;
            while (j < n)
            {
                prime[j] = false;
                j += i;
            }
        }
    }
    // Step 3: Count primes
    for (int i = 2; i < n; i++)
    {
        if (prime[i])
        {
            ans++;
        }
    }

    return ans;
}
int fastCountPrime(int n) // with  optimazation 2
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
    for (int i = 2; i<n; i++)
    {
        if (prime[i])
        {
            ans++;
            int j = i * i; 
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
    int n;
    cout <<"enter n : ";
    cin >>n;
    cout <<"count of prime numbers from 0 to n is : "<<countPrime(n)<<endl;
    cout <<"count of prime numbers from 0 to n through fast method  is : "<<fastCountPrime2(n)<<endl;

    // // gettign GCD(a,b) where GCD=greatest common divisor and a, b are intergr
    // // GCD(a,b)=GCD(a-b,b) when a>b
    // // GDCD(a,b=GDC(b-a,a) when b>a
    // // apply this formula till one of them become zero
    // // GCD(a,0)=a
    // int a, b;
    // cin >> a;
    // cin >> b;
    // cout << "GCD of a and  b is : " << GCD(a, b) << endl;
}