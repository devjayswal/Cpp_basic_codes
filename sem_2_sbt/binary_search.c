#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the key is present at the middle element
        if (arr[mid] == key)
            return mid;

        // If the key is greater, ignore the left half
        if (arr[mid] < key)
            left = mid + 1;

        // If the key is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If the key is not found, return -1
    return -1;
}

// Driver program to test the Binary Search function
int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    int result = binarySearch(arr, 0, n - 1, key);
    if (result == -1)
        printf("Element not found in the array\n");
    else
        printf("Element found at index %d\n", result);

    return 0;
}
