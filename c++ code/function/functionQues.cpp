#include <iostream>
using namespace std;
void factorial(int n)
{
    int fac = 1;
    int i = 0;
    while ((n - i) > 0)
    {
        fac *= (n - i);
        i++;
    }
    cout << fac << endl;
}
#include <iostream>
using namespace std;

void printPrimeUpToN(int n)
{
    if (n < 2)
    {
        cout << "Invalid input" << endl;
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        bool isPrime = true;
        // check if i is divisible by any number from 2 to sqrt(i)
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            cout << i << " ";
        }
    }

    cout << endl;
}
void printDigits(int n)
{
    if (n == 0)
    {
        cout << 0 << endl;
        return;
    }
    if (n < 0)
    {
        cout << "- ";
        n = -n;
    }
    // reverse the number
    int reverse = 0;
    int temp = n;
    while (temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp = temp / 10;
    }
    // print digits
    while (reverse > 0)
    {
        cout << reverse % 10 << " ";
        reverse = reverse / 10;
    }
    cout << endl;
}
void countSetBit(int n)
{
    int count = 0;
    while (n > 0)
    {
        int bit = n & 1;
        if (bit == 1)
        {
            count++;
        }
        n = n >> 1;
    }
    cout << "total set bit are : " << count<<endl;;
}
void printNumber(){
    cout<<"Enter number of digits : ";
    int n;
    cin>>n;
    int digit;
    int number=0;
    for(int i=1;i<=n;i++){
        cout<<"Enter Digit "<<i<<" : ";
        cin>>digit;
        if(digit<0||digit>9){
            cout<<"invalid input";
            return;
        }
        number=number*10+digit;
    }
    cout<<"Number formed : "<<number<<endl;;
}
int main()
{
    factorial(10);
    printPrimeUpToN(17);
    printDigits(-1024);
    printNumber();
    countSetBit(11);
}