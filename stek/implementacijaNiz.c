#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int s[SIZE];
int top=-1;
int isFull(){
    if(top==SIZE-1)return 1;
    else return 0;
}
int isEmpty(){
    if(top==-1)return 1;
    else return 0;
}
void push(int x){
    if(!isFull()){
    top++;
    s[top] = x;}
    else printf("Owerflow");
}
int pop(){
    if(!isEmpty()){
        int el = s[top];
        top--;
        return el;
    }
    else{ printf("Underflow"); 
    return -1;}
}
void display(){
    if(!isEmpty()){
        for(int i=0; i<=top; i++){
            printf("%d ", s[i]);
        }
    }
    else printf("Underflow");
}
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    printf("%d\n",pop());
    display();



}