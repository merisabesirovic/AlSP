#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
int data;
NODE *next;
};
NODE *front=NULL;
NODE *rear=NULL;
NODE *temp=NULL;
void create(int data){
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    if(front == NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
        rear->next = front;
}
void display(){
temp = front;
while(temp !=rear){
    printf("%d ",temp->data);
    temp = temp->next;
}
printf("%d",temp->data);
printf("\n");

};
// brisanje prvog elementa
void deleteFirst(){
    temp = front;
    if(front == NULL) printf("lista je prazna");
    else if (front==rear)
    {
        front = rear = NULL;
    }
    else{
        front = front->next;
        rear->next = front;
    }
    temp->next = NULL;
    free(temp);
    
}
int main(){
    create(100);
    create(2);
    create(4);
    create(8);
    display();
    deleteFirst();
    display();
}