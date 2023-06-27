#include <stdio.h>
#include <stdlib.h>
#define SIZE 15

int red[SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if ((front == 0 && rear == SIZE - 1) || front == rear + 1) {
        return 1;
    } else {
        return 0;
    }
}

int isEmpty() {
    if (front == -1) {
        return 1;
    } else {
        return 0;
    }
}

void enqueue(int el, int el2) {
    if (isFull()) {
        printf("Red je pun!");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        red[rear] = el;
        rear = (rear + 1) % SIZE;
        red[rear] = el2;
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Red je prazan");
    } else if (front == rear) {
        printf("Izbacen element: %d\n", red[front]);
        front = rear = -1;
    } else {
        printf("Izbaceni elementi: %d %d\n", red[front], red[front + 1]);
        front = (front + 2) % SIZE;
    }
}

void brisiSaPozicije(int poz) {
    int flag=0;
    int i;
    if (isEmpty()) {
        printf("Red je prazan");
    } else if (poz < front || poz > rear) {
        printf("Nema elementa na toj poziciji\n");
    } else {
        for (i = front; i!=rear; i=(i+1)%SIZE) {
            if(poz == i){
                flag=1;
            red[i] = red[i + 1];
        }
        if(flag){
            red[i] = red[i + 1];
        }

    };
    red[i]=red[i + 1];
}}

void display() {
    int i;
    if (isEmpty()) {
        printf("Red je prazan\n");
    } else {
        printf("Sadrzaj reda: ");
        for (i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ", red[i]);
        }
        printf("%d\n", red[i]);
    }
}

int main() {
    enqueue(5, 5);
    enqueue(9, 9);
    enqueue(10, 10);
    enqueue(5, 5);
    enqueue(9, 9);
    enqueue(10, 10);
    // enqueue(5, 5);
    // enqueue(9, 9);
    // enqueue(10, 10);
    display();
    dequeue();
    display();
    brisiSaPozicije(4);
    // brisiSaPozicije(2);
    // brisiSaPozicije(14);
    // display();

    return 0;
}
