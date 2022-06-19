#include <assert.h>
#include <stdlib.h>

#include "sort.h"


void mergeSortSlice(int arr[], int start, int end, int * temp) {
	if (start >= end) {
		return;
    }

	int mid = (start + end) / 2;
	mergeSortSlice(arr, start, mid, temp);
	mergeSortSlice(arr, mid + 1, end, temp);
 
	int length = 0;
	int i_start = start;
	int i_end = mid;
	int j_start = mid + 1;
	int j_end = end;
	while (i_start <= i_end && j_start <= j_end) {
		if (arr[i_start] < arr[j_start]) {
			temp[length] = arr[i_start]; 
			length++;
			i_start++;
		} else {
			temp[length] = arr[j_start];
			length++;
			j_start++;
		}
	}

	while (i_start <= i_end) {
		temp[length] = arr[i_start];
		i_start++;
		length++;
	}

	while (j_start <= j_end) {
		temp[length] = arr[j_start];
		length++;
		j_start++;
	}

	for (int i = 0; i < length; i++) {
		arr[start + i] = temp[i];
	}
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
		return;
    }

    int* tmp = (int*) malloc(sizeof(int)*(end+1));
    assert(tmp);
    mergeSortSlice(arr, start, end, tmp);
    free(tmp);
}