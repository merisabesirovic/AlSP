#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int a[], int n){
    int pom;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j <n-i-1; j++){
            if(a[j]>a[j+1]){
                pom=a[j];
                a[j] = a[j+1];
                a[j+1] = pom;
            }
        }
    }
}
void print(int a[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    int a[]={1,9,5,3,4};
    print(a,5);
    bubbleSort(a,5);
    print(a,5);
}