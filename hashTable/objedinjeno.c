#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct data DATA;
struct data {
    int value;
    int key;
};

typedef struct itemData ITEMDATA;
struct itemData {
    DATA* data;
    int flag;
};

DATA* createData(int key, int value) {
    DATA* data = (DATA*)malloc(sizeof(DATA));
    data->value = value;
    data->key = key;
    return data;  // Return the allocated data pointer
}

ITEMDATA* arr[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = NULL;  
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int value, int key) {
    ITEMDATA* temp = (ITEMDATA*)malloc(sizeof(ITEMDATA));
    temp->data = createData(key, value);
    temp->flag = -1;  
    int index = hashFunction(key);
    if (arr[index] == NULL) {
        arr[index] = temp;  
    } else {
        int freeIndex = index;
        while (arr[freeIndex] != NULL) {
            freeIndex = (freeIndex + 1) % SIZE;  // Find the next available free slot
        }
        arr[freeIndex] = temp;  // Insert at the free slot
        if (freeIndex != index) {
            arr[index]->flag = freeIndex;  // Update the flag if there is a collision
        }
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] != NULL && arr[i]->data != NULL) {
            printf("[%d, %d, %d] ", arr[i]->data->key, arr[i]->data->value, arr[i]->flag);
        } else {
            printf("NULL ");
        }
    }
    printf("\n");
}

int main() {
    initialize();
    insert(1, 1);
    insert(2, 2);
    insert(4, 22);
    insert(2, 8);
    insert(66,28);
    display();

    return 0;
}
