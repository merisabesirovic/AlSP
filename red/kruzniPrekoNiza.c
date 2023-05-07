#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int queue[SIZE];
int front=-1;
int rear=-1;
int isFull(){
    if((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    return 1;
    else return 0;
}
int isEmpty(){
    if(front==rear==-1) return 1; 
    else return 0;
}
void enqueue(int el){
   if(isFull())
    printf("Red je pun!");
    else{
         if(front==-1)
        front = 0;
        rear = (rear+1)%SIZE;
        queue[rear]=el;
}}
int dequeue(){
    int el;
    if(isEmpty()) printf("Red je prazan");
    else if(front==rear) {front=rear=-1;el=queue[front];
    return el;}
    else{
        el=queue[front];
        front=(front+1)%SIZE;
        return el;
    }
}
void display(){
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    int i;
    for(i=front; i!=rear; i=(i+1)%SIZE){
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[i]);
}

int main(){
enqueue(5);
enqueue(6);
enqueue(7);
display();
dequeue();
dequeue();
enqueue(9);
enqueue(9);
enqueue(9);
display();
}