#include <stdio.h>

void merge(int arr[], int left[], int leftLen, int right[], int rightLen) {
    int i = 0, j = 0, k = 0;

    while (i < leftLen && j < rightLen) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftLen) {
        arr[k++] = left[i++];
    }

    while (j < rightLen) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int len) {
    if (len < 2) {
        return;
    }

    int mid = len / 2;
    int left[mid], right[len - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < len; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, len - mid);

    merge(arr, left, mid, right, len - mid);
}

int main() {
    int arr[] = { 3, 1, 4, 2, 5 };
    int len = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, len);

    printf("Sorted array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


