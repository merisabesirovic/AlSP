#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct dataItem ITEM;
struct dataItem {
    int data;
    int key;
};

ITEM* hashArr[SIZE];
ITEM* dummyItem;
ITEM* item;

int hashCode(int key) {
    return (key % SIZE);
}

ITEM* search(int key) {
    int hashIndex = hashCode(key);
    while (hashArr[hashIndex] != NULL) {
        if (hashArr[hashIndex]->key == key) {
            return hashArr[hashIndex];
        }
        hashIndex++;
        hashIndex %= SIZE;
    }
    return NULL;
}
void insert(int key, int data)
{
ITEM *item = (ITEM*) malloc(sizeof(ITEM));
item->data = data;
item->key = key;
int hashIndex = hashCode(key);
while(hashArr[hashIndex] != NULL && hashArr[hashIndex]->key != -1) {
    ++hashIndex;
hashIndex %= SIZE;
}
hashArr[hashIndex] = item;
}
ITEM *delete(ITEM *item){
    int hashIndex = hashCode(item->key);
    while(hashArr[hashIndex] != NULL){
        if(hashArr[hashIndex]->key == item->key) {
            ITEM *temp = hashArr[hashIndex];
            hashArr[hashIndex] = dummyItem;
            return temp;
        }
        ++hashIndex;
        hashIndex%=SIZE;
    }
    return NULL;
}
void display(){
    for(int i = 0; i < SIZE; i++) {
        if(hashArr[i] != NULL){
            printf("(%d,%d) ", hashArr[i]->key, hashArr[i]->data);
        }
        else printf("~~~");
    }
    printf("\n");
}
int main() {
    dummyItem = (ITEM*)malloc(sizeof(ITEM));
    dummyItem->key = -1;
    dummyItem->data = -1;
    insert(1,20);
    insert(21, 3);
    insert(40, 21);
    insert(66, 23);
    display();
    return 0;
}
