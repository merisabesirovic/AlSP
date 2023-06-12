#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i < j)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void quicksort(int arr[], int low, int high) {
    if (low >= high)
        return;

    int partition_index = partition(arr, low, high);

    quicksort(arr, low, partition_index - 1);
    quicksort(arr, partition_index + 1, high);
}

int main() {
    int arr[] = {7, 2, 1, 6, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    quicksort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
