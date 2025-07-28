#include <iostream>
using namespace std;

// Merge two sorted subarrays within arr[]
// arr[s..mid] and arr[mid+1..e] are sorted
void merge(int arr[], int s, int mid, int e) {
    int start1 = s;
    int start2 = mid + 1;

    while (start1 <= mid && start2 <= e) {
        if (arr[start1] <= arr[start2]) {
            start1++;
        } else {
            // arr[start2] is smaller, shift elements to the right
            int value = arr[start2];
            int index = start2;

            //shifting elements to make that arr[start2] element fit at its place
            while (index > start1) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start1] = value;

            // Update all pointers
            start1++;
            mid++;
            start2++;
        }
    }
}

// In-place Merge Sort
void mergeSort(int arr[], int s, int e) {
    if (s >= e)
        return;

    int mid = s + (e - s) / 2;

    // Sort left and right halves
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    // Merge the sorted halves in-place
    merge(arr, s, mid, e);
}

int main() {
    int arr[] = {11, 4342, 7767, 544, 35, 366, 3, 224, 500, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
