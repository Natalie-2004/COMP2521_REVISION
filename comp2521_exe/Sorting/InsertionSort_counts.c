#include <stdio.h>
#include <stdlib.h>
#include <time.h>

  int main() {

    int array[] = {2, 4, 6, 8, 1, 3, 5, 7};
    int n = sizeof(array) / sizeof(array[0]);
    int i, j, temp, no_swap=0, comp=0;

      /* Sort */
    for (i = 1; i < n; i++) {
        j = i;
        while ((j > 0) && (array[j - 1] > array[j])) {
            comp++; // Increment comparison count
            printf("Comparing %d and %d\n", array[j - 1], array[j]);
            temp = array[j - 1];
            array[j - 1] = array[j];
            array[j] = temp;
            j--;
            no_swap++; // Increment swap count
        }
        comp++; // Increment comparison count for the final loop condition check
    }

    /* Print */
    printf("No of swaps = %d\n", no_swap);
    printf("No of comparisons  = %d\n", comp);
    printf("Sorted Array:\n");
    for (i = 0; i < n; i++)
        printf("%d\n", array[i]);
    
    return 0;
 } 
