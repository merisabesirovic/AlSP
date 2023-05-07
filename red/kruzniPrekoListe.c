#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node {
    int data;
    NODE* next;
};
NODE *f=NULL;
NODE *r=NULL;
int isEmpty(){
    if(r==NULL){
    return 1;
    }
    else return 0;
}
void enqueue(int x){
    NODE *temp = (NODE*) malloc(sizeof(NODE));
    temp->data = x;
    temp->next = NULL;
    if(isEmpty()) r=f=temp;
    else{
        r->next=temp;
        r=temp;
    }
}
int dequeue(){
    NODE *pom;
    int info;
    if(isEmpty()){
        printf("RED je prazan");
        return -1;
    }
    else{
        pom= f;
        f=f->next;
        return info = pom->data;
        free(pom);
    }
}
void display(){
    NODE *temp = f;
    while(temp!=NULL){
        printf("%d", temp->data);
        temp= temp->next;
    }
    printf("\n");
}
int main(){
    enqueue(0);
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(0);
    display();
    dequeue();
    dequeue();
    dequeue();
    display();




}