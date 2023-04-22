#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;

struct node {
    int data;
    NODE *next;
};

NODE *first1, *last1, *temp1;
NODE *first2, *last2, *temp2;

void create(NODE **first, NODE **last, int data){
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
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
NODE *invert(NODE *first){
    NODE *p, *q, *r;
    p=first;
    q= NULL;
    while (p!=NULL)
    {
    r=q;
    q=p;
    p=p->next;
    q->next=r;
    }
    first = q;
    return first;
}
NODE *concat(NODE *first1, NODE *first2){
    if(first1 == NULL){
        return first2;
    }
    else if(first2 == NULL){
        return first1;
    }
    else{
     NODE *temp = first1;
     while(temp->next != NULL){
        temp = temp->next;
     }
     temp->next = first2;
     return first1;
    }
}

int main(){
    first1 = NULL;
    last1 = NULL;
    create(&first1, &last1, 1);
    create(&first1, &last1, 2);
    create(&first1, &last1, 3);
    display(first1);

  
    first2 = NULL;
    last2 = NULL;
    create(&first2, &last2, 4);
    create(&first2, &last2, 5);
    create(&first2, &last2, 6);
    display(first2);
    first1 =invert(first1);
    display(first1);
    first1 = concat(first1, first2);
    display(first1);

    return 0;
}
