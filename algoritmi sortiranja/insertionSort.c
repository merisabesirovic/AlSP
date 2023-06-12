#include <stdio.h>
#include <stdlib.h>
void insertionSort(int a[], int n){
    for(int i=1; i<n; i++){
        int value = a[i];
        int hole = i;
        while(value < a[hole-1] && hole >0){
            a[hole]= a[hole-1];
            hole--;
        }
        a[hole] = value;
    }
}
void print(int a[], int n){
    for(int  i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    int a[] = {2,7,8,5,0};
    print(a,5);
    insertionSort(a,5);
    print(a,5);
}