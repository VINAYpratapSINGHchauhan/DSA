#include <iostream>
using namespace std;
void merge(int arr[], int s, int e)
{
    int mid = s + (e - s) / 2;

    // full array(jo hme array mila h uska left aur right part sorted hai but bo pura arry sorted ni h ex: left=[4,5,7] and right=[1,2,3] array that is given=[4,5,6,1,2,3] here we can see that left and right are sorted but they both are not sorted with each other )

    // full array ka left wala array part nikalo

    int leftArraySize = mid - s + 1;         // left array ka size from index[s] to index[mid]
    int *leftArray = new int[leftArraySize]; // dynamically made left part
    int k = s;
    for (int i = 0; i < leftArraySize; i++)
    {
        leftArray[i] = arr[k]; // copying values
        k++;
    }

    // full array ka right wala array part nikalo

    int rightArraySize = e - (mid + 1) + 1;    // right array ka size from index[mid+1] to index[e]
    int *rightArray = new int[rightArraySize]; // dynamically made right part
    int l = mid + 1;
    for (int i = 0; i < rightArraySize; i++)
    {
        rightArray[i] = arr[l]; // copying values
        l++;
    }

    // indexing for each array so that we can use in while loop
    int leftArrayIndex = 0;
    int rightArrayIndex = 0;
    int mainArrayIndex = s;
    // merging them so that they become sorted with each other also
    while (leftArrayIndex < leftArraySize && rightArrayIndex < rightArraySize)
    {
        int leftElement = leftArray[leftArrayIndex];
        int rightElement = rightArray[rightArrayIndex];
        if (leftElement < rightElement)
        {
            arr[mainArrayIndex] = leftElement;
            leftArrayIndex++;
        }
        else
        {
            arr[mainArrayIndex] = rightElement;
            rightArrayIndex++;
        }
        mainArrayIndex++;
    }

    // Copy any remaining elements from left array
    while (leftArrayIndex < leftArraySize)
    {
        arr[mainArrayIndex++] = leftArray[leftArrayIndex++];
    }

    // Copy any remaining elements from right array
    while (rightArrayIndex < rightArraySize)
    {
        arr[mainArrayIndex++] = rightArray[rightArrayIndex++];
    }

    // Free dynamically allocated memory
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
        return;
    // step -1 : break the array in two part left and right
    int mid = s + (e - s) / 2;
    // step -2 : recurion se sort kro left and right ko;
    mergeSort(arr, s, mid);     // left wala part
    mergeSort(arr, mid + 1, e); // right wala part
    // step -3 : merge the left and rigth sorted arrays
    merge(arr, s, e);
}
int main()
{
    // sorting the array through merge sort
    // MERGE SORT
    int arr[] = {11, 4342, 7767, 544, 35, 366, 3, 224, 500, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int start = 0;
    int end = size - 1;

    mergeSort(arr, start, end);
    // printing the sorted array
    for (auto e : arr)
    {
        cout << e << " ";
    }


    //Code for in-place merger sort
    //code for inversion count
}