#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct data DATA;
 struct data{
    int key;
    int value;
};
typedef struct item   HashITEM;
struct item{
    int flag;
    DATA *item;
};

HashITEM *arr;
int max = SIZE;
int size = 0;

int hashFunction1(int key){
    return (key % max);
}
int hashFunction2(int key){
    return (2+key%3);
}

void insert(int key, int value){
    int hash1 = hashFunction1(key);
    int hash2 = hashFunction2(key);
    int index = hash1;
    DATA *item = (DATA *)malloc(sizeof(DATA));
    item->key = key;
    item->value = value;
    if(size == max){
        printf("ERROR hashtable is full");
        return;
    }
    while(arr[index].flag == 1){
        if(arr[index].item->key == key){
            printf("key already exists, updating it\n");
            arr[index].item->value = value;
            return;
        }
        index = (index + hash2)%SIZE;
        if(index == hash1){
            printf("error");
            return;
        }
    }
    arr[index].item = item;
    arr[index].flag = 1;
    size++;
}
void remove(int key){
    int hash1 = hashFunction1(key);
    int hash2 = hashFunction2(key);
    int index = hash1;
    if(size == 0) {
        printf("ERROR hashtable is empty");
        return;
    }
    while(arr[index].flag !=0){
        if(arr[index].flag == 1 && arr[index].item->key==key){
            arr[index].flag = 2;
            arr[index].item = NULL;
            size--;
            return;
        }
         index = (index + hash2)%max;
         if(index == hash1) break;
        
    }
   
}
int sizeOFtable(){
    return size;
}
void display(){
    for(int i = 0; i < max; i++){
        if(arr[i].flag == 1){
            printf("\n Array[%d] has no elements \n", i);

        }
        else {
            printf("\n Array[%d] has elements \n Key (%d) and Value (%d) \n", i, arr[i].item->key, arr[i].item->value);
        }
    }
}
void initializeArr(){
    for(int i = 0; i < max; i++){
        arr[i].item = NULL;
        arr[i].flag = 0;
    }
}
int main() {
    arr = (HashITEM*)malloc(max * sizeof(HashITEM));
    init_array();

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display();

    remove_element(37);

    display();

    return 0;
}
