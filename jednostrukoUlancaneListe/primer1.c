#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node {
int data;
NODE *next;
};
NODE *first = NULL;
NODE *last = NULL;
NODE *temp = NULL;
void create(int data){
temp = (NODE *)malloc(sizeof(NODE));
temp->data = data;
temp->next = NULL;
if(first == NULL){
    first = temp;
    last = temp;
}
else {
    last->next = temp;
    last = temp;
}
}
void print(){
    temp = first;
    while(temp!= NULL){
        printf("%d", temp->data);
        temp = temp->next;}
        printf("\n");
}
void insertAfter(NODE *pom, int data){
    temp = (NODE *)malloc(sizeof(NODE));
    temp->data = data;
    if(pom == last){
        last->next = temp;
        last = temp;
    }
    else{
        temp->next = pom->next;
        pom->next = temp;

    }
}
void insertBefore(NODE *pom, int data){
    temp = (NODE *)malloc(sizeof(NODE)); 
    temp->data = data;
    if(pom == first){
        temp->next = pom;
        first = temp;
    }
    else{
        temp->next = pom->next;
        pom->next = temp;
        temp->data = pom->data;
        pom->data = data;
    }
}
void deleteAfter(NODE *pom){
    if(pom == last){
        printf("poslednji cvor");
    }
    else {
        temp = pom->next;
        if(temp == last){
            last = pom;
        }
        pom->next = temp->next;
        free(temp);
    }
}
void delete(NODE *pom){
    if(pom == first && first == last){
        free(pom);
        first = last = NULL;
    }
    else if(pom == first){
        first = pom->next;
        free(pom);
    }
    else if(pom == last){
        NODE *prev = first;
        while (prev->next != last) {
            prev = prev->next;
        }
        last = prev;
        last->next = NULL;
        free(pom);
    }
    else {
        temp = pom->next;
        pom->data = temp->data;
        pom->next = temp->next;
        free(temp);
    }
}
void deleteOnPosition(int position){
    int count = 1;
    NODE *p = first;
    NODE *q= NULL;
    p = first;
    if(position ==1){
        first = p->next;
        free(p);
    }
    else{
    while(count != position){
        q = p;
        p = p->next;
        count++;
    }
    deleteAfter(q);}
}
void deleteByValue(int value){
   NODE *p = first;
   NODE *q = NULL;
    while(p!=NULL){
    if(p->data == value) break; 
    else{
        q= p;
        p = p->next;
    }
    }
    if(p == first && first == last){
        free(p);
        free(q);
        first = last = NULL;
    }
    else if(p == first){
        delete(p);
    }
    else if(p == last){
        q->next = NULL;
        free(p);
        last = q;
    }
    else {
        q->next = p->next;
        free(p);
    }
}


int main(){
    create(1);
    create(2);
    create(3);
    create(4);
    create(8);
    print();
    delete(first);
    print();
    deleteOnPosition(1);
    print();
    deleteByValue(8);
    print();

}

