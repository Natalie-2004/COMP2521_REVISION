#include <stdio.h>

// Function to merge two sorted sub-arrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int left_size = mid - left + 1;
    int right_size = right - mid;

    // Create temporary arrays
    int Left[left_size], Right[right_size];

    // Copy data to temporary arrays Left[] and Right[]
    for (i = 0; i < left_size; i++)
        Left[i] = arr[left + i];
    for (j = 0; j < right_size; j++)
        Right[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // Merge the temporary arrays back into arr[]
    while (i < left_size && j < right_size) {
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of Left[], if any
    while (i < left_size) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of Right[], if any
    while (j < right_size) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on an array
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively divide and sort sub-arrays
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted sub-arrays
        merge(arr, left, mid, right);
    }
}

int main() {
    int input_array[8] = {70, 50, 30, 20, 10, 70, 40, 60};
    int array_size = sizeof(input_array) / sizeof(input_array[0]);

    // Call merge_sort to sort the input array
    merge_sort(input_array, 0, array_size - 1);

    // Print the sorted array
    for (int i = 0; i < array_size; i++) {
        printf("%d ", input_array[i]);
    }

    return 0;
}
