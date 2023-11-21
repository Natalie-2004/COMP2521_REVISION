#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void quickSort(int *a, int low, int high); 

void quickSort(int *a, int low, int high) {
    int i = low;
    int j = high;
    int key = a[low];

    // if yes，排序结束
    if (low >= high) {
        return;
    }

    // 该while循环结束一次表示比较了一轮
    while (low < high) {
        while (low < high && key <= a[high]) {
            // 向前寻找
            --high;
        }

        if (key > a[high]) {
            // = 交换
            a[low] = a[high];
            // Swap(&a[low], &a[high]);
            ++low;
        }

        while (low < high && key >= a[low]) {
            ++low;
        }

        if (key < a[low]) {
            // = 交换
            a[high] = a[low];
            // Swap(&a[low], &a[high]);
            --high;
        }
    }

    // 查找完一轮后key值归位, 不用比较一次就互换一次。此时key值将序列分成左右两部分
    a[low] = key;
    // recursion
    quickSort(a, i, low-1);
    quickSort(a, low+1, j);
}

int main(void)
{
    int i;  //循环变量
    int a[] = {900, 2, -58, 3, 34, 5, 76, 7, 32, 4, 43, 9, 1, 56, 8,-70, 635, -234, 532, 543, 2500};
    quickSort(a, 0, 20);  /*引用起来很简单, 0为第一个元素的下标, 20为最后一个元素的下标*/
    printf("The Sorted Result is:\n");

    for (i = 0; i < 21; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
