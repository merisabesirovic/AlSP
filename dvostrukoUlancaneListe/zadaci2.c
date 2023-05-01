#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
    int data;
    NODE *next;
    NODE *prev;
};
NODE *createNewNode(){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}
void insertAtHead(int data, NODE **first){
NODE *newNode = createNewNode();
newNode->data = data;
if(*first == NULL){
    *first = newNode;
}
else {
    (*first)->prev= newNode;
    newNode->next = *first;
    *first = newNode;
}
}
void insertAtTail(int data, NODE **first){
    NODE *newNode = createNewNode();
    newNode->data = data;
    if(*first == NULL){
        *first = newNode;
    }
    else{
        NODE *temp = *first;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void print(NODE *first){
    NODE *temp = first;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void invert(NODE **first){
NODE* temp = NULL;
NODE* current = *first;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
        *first = temp->prev;
}
NODE *concat(NODE *first, NODE *first1){
    if(first == NULL) return first1;
    else if(first1 == NULL) return first;
    else {
        NODE *temp = first;
        while(temp->next != NULL){
            temp= temp->next;
        }
        temp->next = first1;
        first1->prev = temp;
        return first;
    }
}
NODE *presek(NODE *first1, NODE *first2){
    NODE *temp = first1;
    NODE *temp2 = first2;
    NODE *first3 = NULL;
    while(temp != NULL){
        temp2 = first2;
    while(temp2!=NULL){
        if(temp->data == temp2->data){
            insertAtTail(temp->data, &first3);
        }
        temp2 = temp2->next;
    }
        temp = temp->next;
    }
    return first3;
}
NODE *unija(NODE *first1, NODE *first2){
    NODE *temp = first1;
    NODE *temp2 = first2;
    NODE *first3 = NULL;
    while(temp!=NULL){
        insertAtTail(temp->data, &first3);
        temp = temp->next;
    }
    while(temp2 != NULL){
        temp = first3;
        int found = 0;
        while(temp != NULL){
            if(temp->data == temp2->data){
                found = 1;
                break;
            }
            temp = temp->next;
        }
        if(!found)
            insertAtTail(temp2->data, &first3);
        temp2 = temp2->next;
    }
    return first3;
}
int findNode(NODE *first,int v){
    NODE *temp = first;
    while(temp!=NULL){
        if(temp->data == v)
        return 1;
        temp = temp->next;
    }
    return 0;
}
NODE *razlika(NODE *first1, NODE *first2){
    NODE *temp1 = first1;
    NODE *temp2 = first2;
    NODE *first3 = NULL;
    while(temp1!=NULL){
        if(!(findNode(first2, temp1->data)))
        insertAtTail(temp1->data, &first3);
        temp1=temp1->next;
    }
    return first3;

}
int main(){
    NODE *first1 = NULL;
    insertAtHead(6,&first1);    
    insertAtHead(2,&first1);    
    insertAtHead(1,&first1);   
    print(first1);
    NODE *first2 = NULL;
    insertAtHead(5,&first2);
    insertAtTail(2,&first2);
    insertAtTail(1,&first2); 
    print(first2);
    // invert(&first1);
    // print(first1);
    // print(concat(first1,first2));
    // print(presek(first1,first2));
    // print(unija(first1, first2));
    print(razlika(first1,first2));
    
}