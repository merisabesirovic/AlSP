#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

typedef struct student S;
struct student {
    int brIndeksa;
    char ime[20];
};

S* arr[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        arr[i] = NULL;
}

int hashFunction(int br) {
    return br % SIZE;
}

void insert(int key, char i[20]) {
    S* temp = (S*)malloc(sizeof(S));
    temp->brIndeksa = key;
    strcpy(temp->ime, i);
    int index = hashFunction(key);
    while (arr[index] != NULL) {
        index++;
        index = hashFunction(index);
    }
    arr[index] = temp;
}

void ispis() {
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] != NULL) {
            printf("[%d, [%s, %d]] ", i, arr[i]->ime, arr[i]->brIndeksa);
        } else {
            printf("[NULL] ");
        }
    }
    printf("\n");
}

void unesi() {
    int index;
    char ime[20];
    for (int i = 0; i < 5; i++) {
        printf("Unesi %d. studenta: ", i);
        scanf("%d", &index);
        scanf("%19s", ime);
        insert(index, ime);
    }
}

int main() {
    init();
    unesi();
    ispis();

    return 0;
}
