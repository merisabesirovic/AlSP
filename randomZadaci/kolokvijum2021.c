#include <stdlib.h>
#include <stdio.h>
typedef struct node NODE;
struct node{
    int data;
    NODE *next;
};
NODE *front=NULL;
NODE *rear=NULL;
void create(int x){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;
    temp->next = NULL;
    if(front==NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next=temp;
        rear = temp;
    }
    rear->next = front;
}
void display(){
    NODE *temp = front;
    while(temp!=rear){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
int brojPojava(int el){
    int br = 0;
    NODE *temp = front;
    do{
        if(temp->data==el) br++;
        temp = temp->next;
    }
    while(temp!=front);
    return br;
}
int main(){
    create(100);
    create(20);
    create(800);
    create(400);
    display();
    printf("%d\n",brojPojava(100));
    printf("%d\n",brojPojava(400));
    create(800);
    create(400);
    create(400);
     printf("%d\n",brojPojava(400));

}
