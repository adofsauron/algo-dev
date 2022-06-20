
#include "sort.h"

void quickSort(int arr[], int start, int end) {
	if (start >= end) {
		return;
    }

	int i = start;
	int j = end;

	int arr_start = arr[start];
	while (i < j) {
		while (i < j && arr[j] >= arr_start) {
			j--;
		}

		if (i < j) {
			arr[i] = arr[j];
			i++;
		}

		while (i < j && arr[i] < arr_start) {
			i++;
		}

		if (i < j) {
			arr[j] = arr[i];
			j--;
		}
	}

	arr[i] = arr_start;
	quickSort(arr, start, i - 1);
	quickSort(arr, i + 1, end);
}
