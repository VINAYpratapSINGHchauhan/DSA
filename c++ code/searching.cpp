#include <iostream>
#include <vector>
using namespace std;
void binarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            cout << "element found at index : " << mid << endl;
            return;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    cout << "Element is not found" << endl;
    return;
}
void findMissingNumber(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == mid + 1)
        {
            s = mid + 1;
        }
        else if (arr[mid] == mid + 2)
        {
            e = mid - 1;
        }
    }
    cout << "Missing Number : " << s + 1 << endl;
}
void findPeakElementIndex(vector<int> &v)
{
    int s = 0;
    int e = v.size() - 1;
    int mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (v[mid] > v[mid + 1])
        {
            // left mei jao
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << "peak element index : " << s << endl;
}
int findPivotElementIndex(vector<int> &arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (s == e)
        {
            return s;
        }
        if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        else if (mid + 1 < (arr.size()) && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if (arr[s] > arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}
void binarySearchInSortedRotatedArray(vector<int> &arr, int s, int e, int target)
{
    int start = s;
    int end = e;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (arr[mid] == target)
        {
            cout << "element found at index : " << mid << endl;
            return;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
    }
    cout << "Element is not found" << endl;
    return;
}
void findTargetinSortedRotatedArray(vector<int> &arr, int target)
{
    int pivot = findPivotElementIndex(arr);
    if (target >= arr[0])
    {
        // search in first part
        binarySearchInSortedRotatedArray(arr, 0, pivot, target);
    }
    else
    {
        // search in second part
        binarySearchInSortedRotatedArray(arr, pivot + 1, arr.size() - 1, target);
    }
}

int divideByBinary(int dividend, int divisor)
{
    int s = 0;
    int e = dividend;
    int ans = -1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;

        int quoteint = mid;
        if (quoteint * divisor == dividend)
        {
            return quoteint;
        }
        if (quoteint * divisor < dividend)
        {
            ans = quoteint;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int BsearchInNearly(vector<int> &v,int target){
    int s=0;
    int e=v.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(v[mid]==target){
            return mid;
        }else if(mid-1>=0 && v[mid-1]==target){
            return mid-1;
        }else if (mid+1<v.size() && v[mid+1]==target){
            return mid+1;
        }else if(v[mid]<target){
            s=mid+2;
        }else{
            e=mid-2;
        }
    }
    return -1;
}

int findOddOccurenceNumber(vector<int> &nums){
    int s=0;
    int e=nums.size()-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(s==e){
            return nums[s];
        }
        if(mid&1){ //true means number is odd
            if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }else{//means number is even
            if(mid+1<nums.size() && nums[mid]==nums[mid+1]){
                s=mid+2;
            }else{
                e=mid;
            }
        }
    }
    return -1;
}
int main()
{
    // binary search
    // vector<int> arr= {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    // int target = 10;
    // binarySearch(arr, target);

    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    // int size = sizeof(arr) / sizeof(arr[0]);
    // findMissingNumber(arr, size);

    // vector<int> v = {10, 30, 40, 70, 90, 40, 30};
    // findPeakElementIndex(v);

    // vector<int> num = {12, 13, 14, 15, 16, 2, 4, 6, 8, 10};
    // vector<int> num = { 2, 4, 6,8,10};
    // int p = findPivotElementIndex(num);
    // cout<<p;
    // int target = 8;
    // findTargetinSortedRotatedArray(num, target);

    // int dividend = -35;
    // int divisor = 10;
    // // sent only positive value in the parameter
    // int result = divideByBinary(abs(dividend), abs(divisor));
    // // here we need to handle the result sign as per the divisor and dividend sign
    // if (dividend < 0 ^ divisor < 0)
    // {
    //     result = -result;
    // }
    // cout << "result is : " << result << endl;

    // binary search in nearly sorted array
    // vector<int> arr={20,10,30,50,40,70,60};
    // int target=10;
    // int index =BsearchInNearly(arr,target);
    // cout<<"element found at index : "<<index<<endl;

    // find the odd occuring element 
    // vector<int> nums={1,1,2,3,3,4,4};
    // int oddOccurenceNumber=findOddOccurenceNumber(nums);
    // cout<<"odd occurence number : "<<oddOccurenceNumber<<endl;
    cout<<"hello world";

    
}
