#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node {
    int data;
    NODE *next;
    NODE *prev;
};
NODE *first = NULL;
NODE *createNewNode() {
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insertAtHead(int data){
    NODE *newNode = createNewNode();
    newNode->data = data;
    if(first == NULL) {
    first = newNode;
    }
    else{
    first->prev = newNode;
    newNode->next = first;
    first = newNode;
    }
}
void insertAtTail(int data){
    NODE *newNode = createNewNode();
    NODE *temp = first;
    newNode->data = data;
    if(first == NULL) {
        first = newNode;
    }
    else{
        while(temp->next!=NULL){
            temp = temp->next;
        }
    temp->next = newNode;
    newNode->prev = temp;
    }
}
void print(){
    NODE *temp = first;
    if(first == NULL) {printf("Lista je prazna");};
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
float srednjaV(){
float s=0.0;
int br=0;
NODE *temp=first;
while(temp!=NULL){
    s+=temp->data;
    br++;
    temp=temp->next;
}
return s/br;
};
int nadjiEl(int data){
NODE *temp=first;
int flag=0;
while(temp!=NULL){
    if(temp->data==data) {
        flag=1;
        break;
    };
    temp=temp->next;
}
return flag;
}

int main(){
    // insertAtTail(6);
    // insertAtTail(8);
    // insertAtTail(10);
    // insertAtTail(4);
    // print();
    // insertAtHead(2);
    //     insertAtHead(13);

    print();
    printf("srednja vrednost liste je %f", srednjaV());
    int el = 7;
    if(nadjiEl(el)){
        printf("\nu listi se nalazi broj %d", el);
    }
    else printf("\nu listi se ne nalazi broj %d", el);


}