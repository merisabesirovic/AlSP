// Zadatak 5. Napisati potprogram kojim se proverava da li su dve lančane liste L1 i L2 jednake.
// Zadatak 6. Napisati rekurzivni potprogram koji nalazi:
// (a) maksimalni element lančane liste,
// (b) sumu svih elemenata lančane liste
// (c) ispituje da li se zadati element nalazi u listi
// (d) zamenjuje svako pojavljivanje elementa el1 elementom el2
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct node NODE;
struct  node {
int data;
NODE *next;
};
NODE *temp = NULL;
void create(int data, NODE **first, NODE **last){
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    if(*first==NULL){
        *first = temp;
        *last = temp;
    }
    else{
        (*last)->next = temp;
        *last = temp;
    }
}
void display(NODE *first){
    temp = first;
    while(temp!=NULL){  
    printf("%d ", temp->data);
    temp = temp->next;}
    printf("\n");
}
bool jednakeListe(NODE *first1, NODE *first2){
    NODE *temp2 = first2;
    temp = first1;
    while(temp!=NULL && temp2!=NULL){
            if(temp2->data==temp->data)
            {
                temp2 = temp2->next;
                temp = temp->next;
            }
            else return false;
        }
        return true;
    }
int maxEl(NODE *first){
    if(first == NULL){
    printf("Lista je prazna!\n");
    return -1;
    }
    int max = first->data;
    if(first->next == NULL){
    return max;
    }
    else{
    int nextMax = maxEl(first->next);
    if(nextMax>max)
    max = nextMax;
    }
    return max;
}
bool isInList(NODE *first, int el){
    if(first == NULL){
        return false;
    }
    else if(el!=first->data){
        return isInList(first->next,el);
    }else 
    return true;
    }
void zamena(NODE *first, int el1, int el2){
    if(first==NULL){
        printf("Lista je prazna!\n");
    }
    else if(first->data!=el1){
        zamena(first->next,el1,el2);
    }
    else {
        first->data = el2;
    }
}
int suma(NODE *first){
    int s = 0;
    if(first == NULL)
    return 0;
    else{
         s = first->data + suma(first->next);;
        }
    return s;
    }
int main(){
NODE *first1, *last1;
first1 = NULL;
last1 = NULL;
create(1, &first1, &last1);
create(2, &first1, &last1);
create(3, &first1, &last1);
display(first1);
NODE *first2, *last2;
first2 = NULL;
last2 = NULL;
create(1, &first2, &last2);
create(2, &first2, &last2);
create(3, &first2, &last2);
display(first2);
printf("%d\n", jednakeListe(first1, first2));
printf("%d\n", suma(first1));
printf("%d\n", isInList(first2, 0));
zamena(first1, 1, 2);
display(first1);

}

