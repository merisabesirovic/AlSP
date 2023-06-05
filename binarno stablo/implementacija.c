#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node {
int data;
NODE *left;
NODE *right;
};
NODE *newNode(int data){
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
}
void preorder(NODE *tree){
    if(tree){
        printf("%d\n", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void inorder(NODE *tree){
    if(tree){
        inorder(tree->left);
        printf("%d\n", tree->data);
        inorder(tree->right);
    }
}
void postorder(NODE *tree){
    if(tree){
        postorder(tree->left);
        postorder(tree->right);
        printf("%d\n", tree->data);
    }
}
void deleteTree(NODE *tree){
    if(tree){
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}
int main(){
    NODE *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    root->left->right->left=newNode(6);
    root->left->right->right=newNode(7);
    printf("preorder\n");
    preorder(root);
    printf("inorder\n");
    inorder(root);
    printf("postorder\n");
    postorder(root);


}