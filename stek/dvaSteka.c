#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int s[SIZE];
int top[3]={0,-1,SIZE};
int isFull(){
    if(top[1]==top[2]-1) return 1;
    else return 0;
}
int isEmpty(int stno){
switch (stno)
{
case 1: if(top[1]==-1) return 1; else return 0;
    break;
case 2: if(top[2]==SIZE) return 1;else return 0;
}
}
void push(int stno, int el){
    int pos;
    if(isFull()) {printf("stack owerflow!");}
    else{
        if(stno==1)
        pos=++top[stno];
        else 
        pos =--top[stno];
        }
        s[pos]=el;
    }
int pop(int stno){
    int pos;
    int el;
    if(isEmpty(stno)) {printf("Stack underflow!"); return -1;}
    else{
        pos = top[stno];
        el = s[pos];
        if(stno==1)
        top[stno]--;
        else top[stno]++;
        return el;
    }
}
void display(int stno){
    if(isEmpty(stno)) printf("stack-underflow");
    else{
        if(stno==1){
            for(int i=0; i<=top[stno]; i++)
            printf("%d",s[i]);
        }
        else {
            for(int i=SIZE-1; i>=top[stno]; i--){
                printf("%d", s[i]);
            }
        }
    }
}
int main(){
    push(1,2);
    push(1,2);
    push(1,2);
    push(2,3);
    push(2,3);
    display(1);
    display(2);



}