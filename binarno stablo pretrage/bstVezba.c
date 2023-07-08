#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
    int data;
    NODE *left;
    NODE *right;
};
NODE *createNewNode(int data){
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
}
void insert(NODE **tree, int data){
    if(*tree==NULL){
        *tree = createNewNode(data);
    }
    else if((*tree)->data>data){
        insert(&(*tree)->left,data);
    }
    else insert(&(*tree)->right,data);
}
NODE *search(NODE *tree, int el){
    if(tree == NULL || tree->data==el){ return tree; }
    if(tree->data>el){
        search(tree->left,el);
    }
    else search(tree->right,el);
}
NODE *minValue(NODE *tree){
    if(tree){
        NODE *temp=tree->left;
        while(temp!=NULL && temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
}
NODE *deleteNODE(NODE *tree, int data){
    if(tree==NULL)return tree;
    if(tree->data>data){
        deleteNODE(tree->left,data);
    }
    else if(tree->data<data){
        deleteNODE(tree->right,data);
    }
    else{
        if(tree->left==NULL){
            NODE *temp=tree->right;
            free(tree);
            return temp;
        }
        if(tree->right==NULL){
            NODE *temp=tree->left;
            free(tree);
            return temp;
        }
        NODE *temp=minValue(tree->right);
        tree->data=temp->data;
        tree->right=deleteNODE(tree->right,data);
    }
    return tree;
}
NODE *maxEl(NODE *tree){
    if(tree){
        NODE *temp=tree->right;
        while(temp!=NULL && temp->right!=NULL){
            temp = temp->right;
        }
        return temp;
    }
}
int main(){
    NODE *tree=NULL;
    insert(&tree,5);
    insert(&tree,2);
    insert(&tree,3);
    insert(&tree,8);
    insert(&tree,9);
    insert(&tree,4);
    printf("%d\n",maxEl(tree)->data);
    



}