/*Zadatak 1. Brisanje elementa u dvostruko ulančanoj listi:
S početka liste
S kraja liste
Pre zadatog elementa
Nakon zadatog elementa itd. (kao za jednostruko povezanu).
Zadatak 2. Pretvaranje jednostruko ulančane liste u kružno ulančanu i obrnuto.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
int data;
NODE *next;
};
void create(int data, NODE **front, NODE **rear){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    if(*front==NULL){
        *front = temp;
        *rear = temp;
    }
    else{
        (*rear)->next = temp;
        *rear = temp;
    }
    (*rear)->next = *front;
}
void display(NODE *front, NODE *rear){
    NODE *temp = front;
    while(temp!=rear){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d", temp->data);
    printf("\n");
}
void brisiPocetak(NODE **front, NODE **rear){
    NODE *temp = *front;
    if(*front==NULL) printf("Lista je prazna");
    else if(*front == *rear){
        front = rear = NULL;
    }
    else {
        *front = (*front)->next;
        (*rear)->next = *front;
    }
    temp->next = NULL;
    free(temp);
}
void brisiKraj(NODE **front, NODE **rear){
    if(*front==NULL) printf("Lista je prazna");
    else if(*front == *rear){
        front = rear = NULL;
    }
    else{ NODE *temp = *front;
        while(temp->next!=*rear){
            temp = temp->next;
        }
        free(*rear);
        temp->next = *front;
        *rear = temp;
        
    }
}
void deleteBefore(NODE **front, NODE **rear, NODE *pom){
if(pom==*front)printf("greska");
else{
    NODE *temp = *front;
    while(temp->next!=pom)
    temp = temp->next;
    temp->data = pom->data;
    temp->next = pom->next;
    if(pom == *rear){
        temp= *rear;
    }
    pom->next = NULL;
    free(pom);
}
}
void deleteAfter(NODE **front, NODE **rear, NODE *pom){
    if(pom == *rear) printf("greska");
    else{
        NODE *temp = pom->next;
        pom->next = temp->next;
        free(temp);
    }
}
void transform(NODE **front, NODE **rear){
NODE *temp = *front;
while(temp!=*rear) temp = temp->next;
temp->next = NULL;
(*rear)->next = NULL;
}
void displaySinglyList(NODE **front){
    NODE *temp = *front;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
void convert(NODE **front, NODE **rear){
    NODE *temp = *front;
    while(temp->next!=NULL)
    temp = temp->next;
    temp->next = *front;
    *rear = temp;


}
int main(){
    NODE *front = NULL;
    NODE *rear = NULL;
    create(0, &front, &rear);
    create(1, &front, &rear);
    create(2, &front, &rear);
    display(front, rear);
    brisiPocetak(&front, &rear);
    display(front, rear);
    brisiKraj(&front, &rear);
    display(front, rear);
    create(3,&front, &rear);
    create(4,&front, &rear);
    create(4,&front, &rear);
    display(front, rear);
    deleteBefore(&front, &rear, front->next->next);
    display(front, rear);
    deleteAfter(&front,&rear,front);
    display(front, rear);
    create(5,&front, &rear);
    create(0,&front, &rear);
    display(front, rear);
    transform(&front, &rear);
    displaySinglyList(&front);


}