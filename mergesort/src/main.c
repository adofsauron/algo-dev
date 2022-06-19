#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

#include "sort.h"

void dumpArr(int arr[], int arr_len) {
    for(int i=0; i < arr_len; ++i) {
        printf("i: %d value: %d\n", i, arr[i]);
    }
}

void insertArrRandom(int arr[], int arr_len) {
    for(int i=0; i < arr_len; ++i) {
        arr[i] = rand() % 100;
    }
}

int	main(int argc, char **argv) {
    srand((unsigned)time(NULL));

    int arr[10] = {0};

    insertArrRandom(arr, 10);
    dumpArr(arr, 10);

    printf("------------------------------\n");

    mergeSort(arr, 0, 9);
    dumpArr(arr, 10);

    return 0;
}
