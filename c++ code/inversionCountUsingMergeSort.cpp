#include <iostream>
using namespace std;

// Merges two sorted halves and counts inversions
long long mergeAndCount(int arr[], int s, int mid, int e) {
    int n1 = mid - s + 1;
    int n2 = e - mid;

    // Create temporary arrays
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) left[i] = arr[s + i];
    for (int i = 0; i < n2; i++) right[i] = arr[mid + 1 + i];

    long long invCount = 0;
    int i = 0, j = 0, k = s;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            invCount += (n1 - i); // All remaining elements in left are > right[j]
        }
    }

    // Copy remaining elements
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];

    return invCount;
}

long long mergeSortAndCount(int arr[], int s, int e) {
    long long invCount = 0;
    if (s < e) {
        int mid = s + (e - s) / 2;

        // Count inversions in left and right halves
        invCount += mergeSortAndCount(arr, s, mid);
        invCount += mergeSortAndCount(arr, mid + 1, e);

        // Count split inversions
        invCount += mergeAndCount(arr, s, mid, e);
    }
    return invCount;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    long long inversionCount = mergeSortAndCount(arr, 0, size - 1);

    cout << "Number of inversions: " << inversionCount << endl;

    cout << "Sorted Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
