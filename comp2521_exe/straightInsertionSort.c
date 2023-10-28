#include<stdio.h>

// void swap(int *a, int *b);
void insertSort(int a[], int n);

// void swap(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

void insertSort(int a[], int n) {
    int i,j;
    for (i = 1; i < n; i++) {
        int temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--) {
        a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

int main(void) {
    int a[8]= {70,50,30,20,10,70,40,60};
    int n = 7;
    insertSort(a,n);
    for(int i = 0; i <= n; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
