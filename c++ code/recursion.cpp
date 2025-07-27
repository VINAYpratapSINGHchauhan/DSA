#include <iostream>
#include <vector>
#include<limits.h>
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

int climbStair(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return (climbStair(n - 1) + climbStair(n - 2));
}

bool elementFound(int arr[], int size, int index, int search)
{
    if (index >= size)
    {
        return false;
    }
    if (arr[index] == search)
    {
        return true;
    }
    elementFound(arr, size, index + 1, search);
}

void mapEven(vector<int> &v, int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    };
    if (arr[index] % 2 == 0)
    {
        v.push_back(arr[index]);
    }
    mapEven(v, arr, size, index + 1);
}

void doubleElement(int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    };
    arr[index] *= 2;
    doubleElement(arr, size, index + 1);
}

bool checkSort(int arr[], int size, int index)
{
    if (index >= size)
    {
        return true;
    }
    if (arr[index] < arr[index - 1])
    {
        return false;
    }
    return checkSort(arr, size, index + 1);
}

bool findElement(int arr[], int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    if (s > e)
    {
        return false;
    }
    else if (arr[mid] == target)
    {
        return true;
    }
    else if (arr[mid] > target)
    {
        return findElement(arr, s, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        return findElement(arr, mid + 1, e, target);
    }
}

void printSubsequences(string str, string output, int index)
{
    if (index >= str.length())
    {
        // print the output string and return
        cout << "->" << output << endl;
        return;
    }
    char ch = str[index];
    // exclude the char
    printSubsequences(str, output, index + 1);
    // include
    output.push_back(ch);
    printSubsequences(str, output, index + 1);
}

int maximiseTheCuts(int n , int x, int y , int z){
    if(n==0)return 0;
    if(n<0)return INT_MIN;
    int option1 =1+maximiseTheCuts(n-x,x,y,z);
    int option2 =1+maximiseTheCuts(n-y,x,y,z);
    int option3 =1+maximiseTheCuts(n-z,x,y,z);
    return max(option1,max(option2,option3));
}

int main()
{
    // recurison means function  k andr function

    // int n;
    // cout << "Enter Element : ";
    // cin >> n;

    // // 1. factorial using recursion
    // cout << "factorail of n is : " << factorial(n) << endl;

    // // 2. printing back counting  --tail rrecursion
    // backCounting(n);
    // cout << endl;

    // // 3. printing front counting --head recursion
    // frontCounting(n);
    // cout << endl;

    // // 4. printing nth term of fibonacci series
    // cout << "nth term of fibonacci series is : " << fib(n) << endl;

    // //quetion 1- climbing stairs : get all ways to reach nth stair by only taking 1 or 2 steps at once
    // cout<<"total number of ways to reach nth stair : "<<climbStair(n)<<endl;

    // // linear search in array through recursion
    // int arr[] = {10, 20, 30, 40, 200};
    // int size = 5;
    // int index = 0;
    // cout << "Element found : " << (elementFound(arr, size, index, n) ? "successfully" : "not found");

    // // store the even element of the array in to the passed vector
    // vector<int> v;
    // int arr[]={1,2,3,5,4,8,7,6,0};
    // mapEven(v,arr,9,0);
    // //printing the vector
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }

    // // array is given double evry element of the array
    // int arr[]={10, 20, 30, 40, 50};
    // doubleElement(arr, 5, 0);
    // // printing the array
    // for (auto e : arr)
    // {
    //     cout << e << " ";
    // }

    // // checking sorting of array using recursion
    // int arr[] = {10, 90, 30, 40, 50, 60};
    // cout << "array is sorted : " << (checkSort(arr, 6, 1) ? "true" : "false") << endl;

    // // binary search using recursion
    // int arr[] = {10, 20, 40, 50, 70, 80, 90};
    // int start = 0;
    // int end = 6;
    // int target = 50;
    // cout << "element is found : " << (findElement(arr, start, end, target) ? "true" : "false") << endl;

    // //include exclude method -print all the substring sequences of the original string by maintaining the order
    // string str="abc";
    // string output=" ";
    // int index=0;
    // printSubsequences(str , output,index);

    // // question - maximise the cut segements
    // int m=9, x = 4, y = 2, z = 3;
    // cout << "maximun cut segments are : " << maximiseTheCuts(m, x, y, z)<<endl;

    
}