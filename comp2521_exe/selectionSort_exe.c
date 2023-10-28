// Use selection to sort 10 integers from smallest to largest.
// Input: 4 85 3 234 45 345 345 122 30 12
// Output:
// 3
// 4
// 12
// 30
// 45
// 85
// 122
// 234
// 345
// 345

#include<stdio.h>

void swap(int *a, int *b);
void selectionSort(int a[]);

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int a[]) {
    int temp;
    for (int i = 0; i < 10; i++) {
        // to record the pos needed to be exchanged
        temp = i;
        for (int j = i + 1; j < 10; j++) {
            // select the smallest value in the array
            if(a[temp] > a[j]) {
                // swap position
                temp = j;
            }
        }
        // swap value
        swap(&a[i], &a[temp]);
    }
}
int main()
{
    int numbers[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &numbers[i]);
    }
    
    selectionSort(numbers);
    
    for (int j = 0; j < 10; j++) {
        printf("%d\n", numbers[j]);
    }
    
    return 0;
}