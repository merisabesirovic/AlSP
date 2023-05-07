#include <stdio.h>
#include<conio.h>
#define SIZE 100
int dek[SIZE];
int F=-1;
int R=-1;

int isEmpty(){
    if(F==R && F==-1){
        printf("Deque is empty\n");
        return 1;
    }
    else return 0;
}

int isFull(){
    if((F==0 && R==SIZE-1) || (F==R+1))
        return 1;
    else
        return 0;
}

void insertR(int x){
    if(isFull())
        printf("Deque is full\n");
    else if(isEmpty()){
        R=F=0;
        dek[R]=x;
    }
    else{
        R=(R+1)%SIZE;
        dek[R]=x;
    }
}

void insertF(int x){
    if(isFull())
        printf("Deque is full\n");
    else if(isEmpty()){
        F=R=0;
        dek[F]=x;
    }
    else{
        F=(F+SIZE-1)%SIZE;
        dek[F]=x;
    }
}

void deleteF(){
    if(isEmpty())
        printf("Deque is empty\n");
    else{
        if(F==R)
            R=F=-1;
        else
            F=(F+1)%SIZE;
    }
}

void deleteR(){
    if(isEmpty())
        printf("Deque is empty\n");
    else{
        if(F==R)
            R=F=-1;
        else
            R=(R+SIZE-1)%SIZE;
    }
}

void display(){
    if(isEmpty())
        return;
    int i;
    for(i=F; i!=R; i=(i+1)%SIZE){
        printf("%d ", dek[i]);
    }
    printf("%d\n", dek[i]);
}

int main(){
    insertR(2);
    insertR(1);
    insertR(3);
    insertF(7);
    insertF(5);
    insertF(0);
    display();
    deleteF();
    deleteF();
    display();
    deleteR();
    deleteR();
    display();
    return 0;
}
