#include <stdio.h>
#include <stdlib.h>

typedef struct node NODE;
struct node {
    int value;
    NODE* left;
    NODE* right;
    NODE* mid;
};

NODE* createNewNode(int key) {
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->value = key;
    temp->left = NULL;
    temp->right = NULL;
    temp->mid = NULL;
    return temp; // Add return statement to return the created node
}

void printInorder(NODE* tree) {
    if (tree) {
        printInorder(tree->left);
        printInorder(tree->mid);
        printf("%d\n", tree->value);
        printInorder(tree->right);
    }
}

int isCompleteTree(NODE* tree) {
    if (tree == NULL)
        return 1;
    
    if (tree->left == NULL && tree->right == NULL && tree->mid == NULL)
        return 1;
    
    if ((tree->left && tree->right) || (tree->left && tree->mid) || (tree->mid && tree->right))
        return isCompleteTree(tree->left) && isCompleteTree(tree->mid) && isCompleteTree(tree->right);
    
    return 0;
}

int main() {
    NODE* root = createNewNode(5);
    root->left = createNewNode(8);
    root->right = createNewNode(9);
    root->mid = createNewNode(1);
    root->mid->left = createNewNode(2);
    
    printf("Inorder Traversal:\n");
    printInorder(root);
    
    int isComplete = isCompleteTree(root);
    if (isComplete)
        printf("The tree is complete.\n");
    else
        printf("The tree is not complete.\n");
    
    return 0;
}
