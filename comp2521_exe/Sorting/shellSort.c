#include<stdio.h>
#include<stdlib.h>
void shellSort(int arr[], int n) {
    // 初始化间隔gap为数组长度的一半，每次迭代后gap减半，直到gap为0
    for (int gap = n/2; gap > 0; gap /= 2) {
        // 从gap开始遍历数组，用于在各个子序列中进行插入排序
        for (int i = gap; i < n; i++) {
            // 将当前元素存储在temp中，用于后续插入
            int temp = arr[i];
            int j;
            // 在子序列中进行插入排序
            for (
                j = i; 
                j >= gap && arr[j - gap] > temp; 
                j -= gap
            ) {
                // 将较大的元素向后移动
                arr[j] = arr[j - gap];
            }
            // 将原始的arr[i]（即temp）插入到正确的位置
            arr[j] = temp;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    shellSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}