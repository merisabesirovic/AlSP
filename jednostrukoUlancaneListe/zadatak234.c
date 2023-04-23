// Zadatak 2. Napisati program kojim se svako pojavljivanje elementa el1 u listi zamenjuje elementom el2.
// Zadatak 3. Napisati potprogram kojim se dodaje element na početak lančane liste.
// Zadatak 4. Napisati program kojim se briše  element s početka lančane liste.
#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
    int data;
    struct node* next;
};
NODE *first=NULL;
NODE *last=NULL;
NODE *temp = NULL;

void create(int data){
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    if(first==NULL){
        first = temp;
        last = temp;
    }
    else{
        last->next = temp;
        last = temp;
    }
}
void display(){
    temp = first;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void zameni(int el1, int el2){
    temp = first;
    while(temp!=NULL){
        if(temp->data==el1)
        temp->data = el2;
         temp=temp->next;
    }
}
void dodajNaPocetak(int el){
    temp = (NODE*)malloc(sizeof(NODE));
    temp->data = el;
    temp->next = first;
    first = temp;
}
void izbrisiPocetak(){
    temp = first;
    first = temp->next;
    free(temp);
}
int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    create(2);
    create(2);
    display();
    zameni(2,3);
    display();
    dodajNaPocetak(2);
    display();
    izbrisiPocetak();
    display();
}