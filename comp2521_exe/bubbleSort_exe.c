// 对输入的n个数进行排序并输出。
// 输入的第一行包括一个整数n(1<=n<=100)。 接下来的一行包括n个整数。
// 可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。
// 每组测试数据的结果占一行。

// i.e 
// 5
// 5 4 3 1 2

// output: 1 2 3 4 5
#include<stdio.h>

void bubbleSort(int a[], int n);
void swap(int *a, int *b);

// exchange two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // if the first num is greater than the sec,
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    
    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    
    bubbleSort(numbers, n);
    
    for (int j = 0; j < n; j++) {
        printf("%d ", numbers[j]);
    }
    
    return 0;
}