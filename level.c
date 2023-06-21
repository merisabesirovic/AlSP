#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
int data;
NODE*left;
NODE*right;
};
NODE *createNewNode(int data){
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
int suma(NODE *tree, int level){
    int s=0;
    if(tree && level>0){
        s+=tree->data+(suma(tree->left,level-1)+(suma(tree->right,level-1)));
    } 
    return s;
}
int sumaLevel(NODE *tree, int level) {
    if (tree == NULL) return 0;
    if (level == 1) return tree->data;

    int sumLeft = sumaLevel(tree->left, level - 1);
    int sumRight = sumaLevel(tree->right, level - 1);

    return sumLeft + sumRight;
}

int main(){
     NODE *tree=createNewNode(1);
    tree->left=createNewNode(3);
    tree->left->left=createNewNode(4);
    tree->left->right=createNewNode(6);
    tree->left->left->left=createNewNode(5);
    tree->right=createNewNode(7);
    tree->right->left=createNewNode(8);
    tree->right->right=createNewNode(9);
    printf("%d\n",suma(tree,4));
    printf("%d\n", sumaLevel(tree,2));
}