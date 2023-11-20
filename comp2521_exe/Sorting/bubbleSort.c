#include <stdio.h>

void swap(int *a, int *b);
void bubble_sort(int a[], int n);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(&a[j], &a[j + 1]);
            }
        }
    }
}

int main() {
    int a[8] = {70, 50, 30, 20, 10, 70, 40, 60};
    int n = 7;
    bubble_sort(a, n);
    for (int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
