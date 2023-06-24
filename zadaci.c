#include <stdio.h>
#include <stdlib.h>

void unos(int **a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
        printf("unesite element matrice [%d][%d]\n", i, j);
        scanf("%d", &a[i][j]);}
    }
}
void pretvori(int **a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            if(a[i][j]!=0){
                a[i][j]=1;
            }
        }
    }
}
void ispis(int **a, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int n=3;
    int **a=malloc(n*sizeof(int));
    for(int i = 0; i < n; i++){
        a[i]=malloc(sizeof(int));
    }
    unos(a, n);
    ispis(a, n);
    pretvori(a, n);
    ispis(a, n);
}
