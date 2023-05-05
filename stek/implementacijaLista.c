#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node {
    int data;
    NODE *next;
};
NODE *top;
void push(int data) {
    NODE *temp= (NODE*)malloc(sizeof(NODE));
    if(temp == NULL) printf("ERROR");
    else{
    temp->data= data;
    temp->next= top;
    top = temp;
    }
}
int pop(){
int info;
NODE *t;
if(top == NULL){ 
    printf("Underflow");
    return -1;}
else{
    t=top;
    info = top->data;
    top=top->next;
    t->next= NULL;
    free(t);
    return info;
}
};
void display(){
    if(top == NULL){
        printf("Underflow");
    }else{
    NODE *temp = top;
    while(temp){
        printf("%d ", temp->data);
        temp = temp->next;
    }
            printf("Null\n");

    }
}
int main(){
    push(1);
    push(2);
    push(3);
    push(8);
    push(7);
    display();
    pop();
    pop();
    display();

}