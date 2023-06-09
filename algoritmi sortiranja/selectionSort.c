#include <stdio.h>
#include <stdlib.h>
void selectionSort(int A[], int n){
    for(int i = 0; i < n-1; i++){
        int iMin = i;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[iMin])
            iMin=j;
        }
        int temp = A[iMin];
        A[iMin] = A[i];
        A[i]=temp;
    }
}
void print(int A[], int n){
    for(int i =0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main(){
    int A[]={5,2,0,4,3};
    print(A,5);
    selectionSort(A,5);
    print(A,5);

    
}