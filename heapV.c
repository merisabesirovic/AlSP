#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if (largest != i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr, n, largest);
    }
}

void deleteRoot(int arr[], int n){
    int lastEl = arr[n - 1];
    arr[0] = lastEl;
    n--;
    heapify(arr, n, 0);
}

void printArr(int arr[], int n){
    for (int i = 0; i < n; ++i){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertEl(int arr[], int *n, int el){
    arr[*n] = el;
    (*n)++;
    heapify(arr, *n, 0);
}

int main(){
    int arr[] = {5, 7, 6, 3, 2};
    int n = 5;
    
    printArr(arr, n);
    heapify(arr, n, 0);
    
    insertEl(arr, &n, 8); 
    
    printArr(arr, n);
    
    return 0;
}
