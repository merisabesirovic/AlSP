#include <stdio.h>
#include <stdlib.h>
typedef struct node NODE;
struct node{
int data;
NODE *left, *right;
};

NODE *newNode(int data){
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
void inorder(NODE *tree){
    if(tree){
        inorder(tree->left);
        printf("%d\n", tree->data);
        inorder(tree->right);
    }
}
NODE *search(NODE *tree, int data){
    if(tree ==NULL || tree->data==data){
        return tree;
    }
    else if(tree->data>data){
        return search(tree->left, data);
    }
    else return search(tree->right,data);
}
NODE *minValNode(NODE *root){
    NODE *temp = root;
    while(temp != NULL && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
NODE *deleteNode(NODE *root, int data){
    if(root == NULL) return root;
    if(data< root->data)
    root->left=deleteNode(root->left, data);
    else if(data > root->data)
    root->right=deleteNode(root->right,data);
    else{
        if(root->left==NULL){
            NODE *temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL)
        {
            NODE *temp=root->left;
            free(root);
            return temp;
        }
        NODE *temp=minValNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
    }
void insert(NODE **tree, int data){
    if (*tree == NULL) {
        *tree = newNode(data);
    } else if (data < (*tree)->data) {
        insert(&((*tree)->left), data);
    } else {
        insert(&((*tree)->right), data);
    }
}

int main() {
    NODE *root = NULL;

 
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    
    int searchData = 40;
    NODE *searchResult = search(root, searchData);
    if (searchResult) {
        printf("Node with data %d found.\n", searchData);
    } else {
        printf("Node with data %d not found.\n", searchData);
    }

 
    int deleteData = 30;
    root = deleteNode(root, deleteData);
    printf("Inorder traversal after deleting node with data %d: ", deleteData);
    inorder(root);
    printf("\n");


    return 0;
}
