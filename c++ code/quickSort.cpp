#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;
int partition(vector<int> &arr, int s, int e)
{
    int element = arr[s]; // taking the first element
    int count = 0;
    // counting number of element which are smaller than our element
    for (int i = s+1; i <= e; i++)
    {
        if (arr[i] < element)
        if (arr[i] <= element)
        {
            count++;
        }
    }
    // puting that element at its right place
    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);
    int pivotElement = arr[pivotIndex];
    // making left side element smller than our pivot element and rigth greater than our pivot element
    int i = s;
    int j = e;
    while (i<pivotIndex && j>pivotIndex)
    {
         if (arr[i] <= pivotElement) {
            i++;
        } else if (arr[j] > pivotElement) {
            j--;
        } else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void solve(vector<int> &arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }
    // partition
    int p = partition(arr, s, e);
    // recursive calls
    solve(arr, s, p - 1);
    solve(arr, p+1, e);
}
void quickSort(vector<int> &arr)
{
    solve(arr, 0, arr.size() - 1);
    return;
}
int main()
{
    vector<int> arr = { 5,6,3,5,666,2,4,2,55};
    quickSort(arr);
    for (int i =0;i<arr.size();i++)
    {
        cout <<arr[i] << " ";
    }
    cout << endl;
}
// 5,6,3,5,666,2,4,2,55