#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int s[SIZE];
int top=-1;
void push(int el){
    if(top==SIZE-1) printf("stack overflow");
    else{
        s[++top]=el;
    }
}
int pop(){
    int el;
    if(top==-1) printf("stack underflow");
    else{
    el=s[top];
        --top;
    }
    return el;
}
void display(){
    for(int i=0; i<=top; i++){
        printf("%d",s[i]);
    }
    printf("\n");
}
int main(){
    push(4);
    push(4);
    push(6);
    push(5);
    push(4);
    push(5);
display();
pop();
pop();
display();


}
