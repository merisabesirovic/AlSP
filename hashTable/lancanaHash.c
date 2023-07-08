#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct item ITEM;
struct item {
    ITEM* next;
    int key;
    int value;
};

ITEM* createItem(int value, int key) {
    ITEM* temp = (ITEM*)malloc(sizeof(ITEM));
    temp->next = NULL;
    temp->key = key;
    temp->value = value;
    return temp;
}

ITEM* arr[SIZE];

int hashFunction(int key) {
    return (key % SIZE);
}

void insert(int data, int key) {
    ITEM* item = createItem(data, key);
    int index = hashFunction(key);

    if (arr[index] == NULL) {
        arr[index] = item;
    } else {
        ITEM* temp = arr[index];
        while (temp->next != NULL) {
            if (temp->key == key) {
                temp->value = data;
                free(item);  
                return;
            }
            temp = temp->next;
        }
        if (temp->key == key) {
            temp->value = data;
            free(item);  
            return;
        }
        temp->next = item;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        ITEM* temp = arr[i];
        printf("arr[%d]: ", i);
        if (temp != NULL) {
            while (temp != NULL) {
                printf("(%d, %d) ", temp->key, temp->value);
                temp = temp->next;
            }
        } else {
            printf("NULL");
        }
        printf("\n");
    }
}

void initialize() {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = NULL;
    }
}

int main() {
    initialize();
    insert(0, 0);
    insert(1, 1);
    insert(6, 4);
    insert(26, 24);
    insert(7, 50);
    display();

    return 0;
}
