#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
int data;
NODE *next;
};
NODE *top=NULL;
void push(int el){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if(temp==NULL) printf("stack overflow!");
    else{
    temp->data = el;
    temp->next = top;
    top=temp;
    }}
int pop(){
    int info;
    NODE *temp;
    if(top==NULL){ printf("stack underflow");
    return -1;}
    else{
        temp=top;
        info=top->data;
        top=top->next;
        temp->next = NULL;
        free(temp);
        return info;
    }
}
void display(){
    NODE *temp=top;
    while(temp){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(){
    push(5);
    push(8);
    push(4);
    push(0);
    display();
}