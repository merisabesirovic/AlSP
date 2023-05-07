#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int s[SIZE];
int top[3]={0,-1,SIZE};
int isEmpty(int stno){
    switch (stno)
    {
    case 1: if(top[1]==-1) return 1; else return 0;
        break;
    case 2: if(top[2]==SIZE)return 1; else return 0;
        break;
    }
}
int isFull(){
    if(top[1]==top[2]-1) return 1;
    else return 0;
}
void push(int el, int stno){
    int pos;
    if(isFull()) printf("Stack overflow!!");
    else{
        if(stno==1)
        pos = ++top[stno];
        else pos=--top[stno];
        s[pos]=el;
    }
}
int pop(int stno){
    int pos;
    int info;
    if(isEmpty(stno))return -1; 
    else{
        pos=top[stno];
        info=s[pos];
        if(stno==1)
        top[stno]--;
        else
        top[stno]++;
        return info;
    }
}
void display(int stno){
    if(stno==1){
        for(int i=0; i<=top[stno]; i++){
            printf("%d", s[i]);
        }
        printf("\n");
    }
    else{
        for(int i=SIZE-1; i>=top[stno]; i--){
            printf("%d", s[i]);
        }
        printf("\n");
    }
}
int main(){
    push(4,1);
    push(5,1);
    push(5,1);

    push(2,2);
    push(3,2);
    push(2,2);
    push(1,2);
    display(1);
    display(2);
    pop(2);
    display(2);
    push(3,2);
    push(3,2);
    push(3,2);
    push(3,2);
    push(3,2);
    push(3,2);
    display(2);

}
