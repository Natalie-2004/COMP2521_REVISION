#include<stdio.h>

void select_sort(int a[],int n);
void swap(int *a, int *b);

// exchange two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void select_sort(int a[],int n) {
    int temp;
    for(int i = 0; i < n - 1; i++){
        temp = i;      //利用一个中间变量temp来记录需要交换元素的位置
        for(int j = i + 1; j < n; j++){
            if(a[temp] > a[j]){   //选出待排数据中的最小值
                temp = j;  
            }
        }
        swap(&a[i], &a[temp]); //交换函数
    }
} 

int main(){
    int a[8] = { 2,10,9,4,8,1,6,5 };
    int n = 8;
    select_sort(a,n);
    for(int i = 0; i < n ; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}