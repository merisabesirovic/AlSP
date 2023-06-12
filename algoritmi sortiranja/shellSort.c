#include <stdio.h>
#include <stdlib.h>
void shellSort(int a[], int n){
    for(int gap=n/2; gap>=1; gap/=2 ){
        for(int j=gap; j<n; j++){
            for(int i=j-gap; i>=0; i-gap){
                if(a[i]<a[i+gap])
                break; 
                else 
                {
                    int pom;
                    pom=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=pom;
                }
        }
    }
}}
void print(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(){
    int a[] = {5,8,2,1,6};
    print(a, 5);
    shellSort(a, 5);
    print(a, 5);


}