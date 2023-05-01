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
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
} 
void inversePrint(){
    NODE *temp = first;
    while(temp->next!=NULL){
        temp=temp->next;
    };
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->prev;
    }
}
void deleteAfter(NODE *pom){
    NODE *temp = pom->next;
    if(temp==NULL) printf("Dosli ste do poslednjeg");
    else {
    pom->next = temp->next;
    (pom->next)->prev = pom;
    free(temp);}
    
}
void deleteBefore(NODE *pom){
    if(pom==first) printf("Nema prethodnog cvora");
    else if(pom->prev == first){
        NODE *temp = pom->prev;
        first = pom;
        free (temp);
    }
    else{
    NODE *temp = pom->prev;
    (temp->prev)->next = pom;
    pom->prev = temp->prev;
    free (temp);}
}
void delete(NODE *pom){
    if(pom==first) {
        first = pom->next;
        pom->prev = NULL;
        free (pom);
    }
    else{
    (pom->prev)->next = pom->next;
    (pom->next)->prev = pom->prev;
    free(pom);
    }
}
void deleteOnPosition(int position){
    int i=1;
    NODE *temp = first;
    while(temp!=NULL){
        if(position!=i){
        temp = temp->next;
        i++;}
        else break;
    }
    delete(temp);
}
void deleteByValue(int value){
    NODE *temp = first;
    while(temp!=NULL){
        if(temp->data == value){
        delete(temp);
        break;}
        else temp = temp->next;
    }
}
int main(){
    insertAtTail(8);
    insertAtTail(5);
    insertAtTail(7);
    insertAtTail(3);
    print();
    insertAtHead(0);
    print();
    deleteBefore(first->next);
    print();
    deleteOnPosition(2);
    print();
    deleteOnPosition(1);
    print();
    insertAtTail(4);
    insertAtTail(9);
    print();
    delete(first);
    print();
    deleteBefore(first->next);
    print();
    deleteByValue(4);
    print();
}