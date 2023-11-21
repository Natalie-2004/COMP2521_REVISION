#include <stdio.h>

// Function to merge two sorted sub-arrays
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    // 左边长度
    int left_size = mid - left + 1;
    // 右边长度
    int right_size = right - mid;

    // Create temporary arrays
    int Left[left_size];
    int Right[right_size];

    // Copy data to temporary arrays Left[] and Right[]
    for (i = 0; i < left_size; i++) {
        // copy左半部分到Left[]
        Left[i] = arr[left + i];
    }

    for (j = 0; j < right_size; j++) {
        // copy右半部分到Right[]
        Right[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // Merge the temporary arrays back into arr[]
    while (i < left_size && j < right_size) {
        // 比较两个数组的元素，按顺序合并回原数组
        if (Left[i] <= Right[j]) {
            arr[k] = Left[i];
            i++;
        } else {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }

    // 拷贝L[]的剩余元素
    while (i < left_size) {
        arr[k] = Left[i];
        i++;
        k++;
    }

    // 拷贝R[]的剩余元素
    while (j < right_size) {
        arr[k] = Right[j];
        j++;
        k++;
    }
}

// Function to perform merge sort on an array
void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        // 找到中间点
        int mid = left + (right - left) / 2;

        // 分别排序两半
        // 递归排序左半部分
        merge_sort(arr, left, mid);
        // 递归排序右半部分
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
