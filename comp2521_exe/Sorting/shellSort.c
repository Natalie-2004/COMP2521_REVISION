#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

bool isLessThan(int x1, int x2);
void moveValue(int array[], int fromInd, int toInd);

void shellSort(int array[], int low, int high) {
    int gapValues[8] = {701, 301, 132, 57, 23, 10, 4, 1};

    for (int gapIndex = 0; gapIndex < 8; gapIndex++) {
        int gap = gapValues[gapIndex];
        int startInd = low + gap;
        for (int currentIndex = startInd; currentIndex < high; currentIndex++) {
            int currentValue = array[currentIndex];
            int targetIndex;
            for (targetIndex = currentIndex; targetIndex >= startInd && isLessThan(currentValue, array[targetIndex - gap]); targetIndex -= gap) {
                moveValue(array, targetIndex - gap, targetIndex);
            }
            array[targetIndex] = currentValue;
        }
    }
}

bool isLessThan(int x1, int x2) {
    return x1 < x2;
}

void moveValue(int array[], int fromInd, int toInd) {
    array[toInd] = array[fromInd];
}

int main() {
    // Example array to be sorted
    int testArray[] = {5, 3, 1, 2, 4, 6};
    int arraySize = sizeof(testArray) / sizeof(testArray[0]);

    shellSort(testArray, 0, arraySize);

    printf("Sorted array: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", testArray[i]);
    }
    printf("\n");

    return 0;
}