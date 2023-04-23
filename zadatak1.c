// Zadatak 1. Napisati potprogram koji na osnovu zadate vrednosti elementa:
// (a)vraća 1 ako se elementa nalazi u lančanoj listi, u suprotnom vraća 0
// (b) vraća element ako je nađen u listi
// (c) vraća presek dve lančane liste
#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
    int data;
    struct node *next;
};
NODE *first1, *last1, *temp1;
NODE *first2, *last2, *temp2;
NODE *first3, *last3, *temp3;


void *create(NODE **first, NODE **last, int data){
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    temp->next = NULL;
    if(*first == NULL){
        *first = temp;
        *last = temp;
    }
    else{
        (*last)->next = temp;
        *last = temp;
    }
}
void display(NODE *first){
    NODE *temp = first;
    while(temp != NULL){
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int findElement(int data, NODE *first){
    NODE *temp = first;
    while(temp != NULL){
        if(temp->data == data){
        return 1;
        break;}
        temp = temp->next;
}
return 0;
}
int findElementAndReturn(int data, NODE *first){
    NODE *temp = first;
    while(temp != NULL){
        if(temp->data == data){
            return temp->data;
            break;
        }
        temp= temp->next;
    }
    return 0;
}
void presek(NODE *first1, NODE *first2){ 
    temp1 = first1;
    temp2 = first2;
    first3 = last3 = NULL;
    if(first1 == NULL || first2 == NULL) printf("Nema preseka");
    while(temp1 != NULL){
        temp2 = first2;
        while(temp2 != NULL){
        if (temp1->data ==temp2->data)
        {
            create(&first3, &last3, temp1->data);
        }
        temp2= temp2->next;
            }  
            temp1 = temp1->next;  }
}
int main(){
    first1 = NULL;
    last1 = NULL;
    create(&first1, &last1, 1);
    create(&first1, &last1, 2);
    create(&first1, &last1, 3);
    create(&first1, &last1, 4);
    create(&first1, &last1, 5);
    display(first1);
printf("%d\n", findElement(5,first1)); 
printf("%d\n",findElementAndReturn(5,first1));
printf("%d\n",findElementAndReturn(0,first1));
    first2 = last2 = NULL;
    create(&first2, &last2,3);
    create(&first2, &last2,4);
    create(&first2, &last2,5);
presek(first1, first2);
display(first3);



}