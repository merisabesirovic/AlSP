#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
    int data;
    NODE *left, *right;
};
NODE *createNODE(int data){
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}
void insert(NODE **tree,int data){
    if(*tree==NULL) *tree=createNODE(data);
    else if((*tree)->data>data){
        insert(&(*tree)->left, data);
    }
    else insert(&(*tree)->right, data);
}
NODE *search(NODE *tree,int data){
    if(tree==NULL || tree->data==data) return tree;
    if(tree->data>data){
        search(tree->left, data);
    }
    else search(tree->right, data);
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
void inorder(NODE *tree){
    if(tree){
        inorder(tree->left);
        printf("%d\n",tree->data);
        inorder(tree->right);
    }
}
NODE *deleteNODE(NODE *tree, int data){
    if(tree==NULL)return tree;
    if(tree->data>data){
        deleteNODE(tree->left, data);
    }
    else if(tree->data<data){
        deleteNODE(tree->right, data);
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
        tree->right=deleteNODE(tree->right, data);
    }
    return tree;
}
int main(){
    NODE *tree=NULL;
    insert(&tree,6);
    insert(&tree,3);
    insert(&tree,2);
    insert(&tree,8);
    insert(&tree,4);
    inorder(tree);
    

}