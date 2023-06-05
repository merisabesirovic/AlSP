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
    return node;
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
void printLeaf(NODE *tree){
    if(tree){
        if(tree->left==NULL && tree->right==NULL){
            printf("%d\n", tree->data);
        }
        printLeaf(tree->left);
        printLeaf(tree->right);
    }
}
int suma(NODE *tree){
    int sum = 0;
    if(tree){
        sum += tree->data+ suma(tree->left)+suma(tree->right);
       
    }
    return sum;
}
int brojEl(NODE *tree){
    int broj = 0;
    if(tree){
        broj = 1 + brojEl(tree->left)+brojEl(tree->right);
    }
}
int postoji(NODE *tree, int el){
    if(tree) {
    if(tree->data == el){
        return 1;
    }
    else{
        if(postoji(tree->left, el)) return 1;
        else if(postoji(tree->right, el)) return 1;

    }}
    else return 0;
}
int maxDepth(NODE *tree){
    int levaDuzina = 0;
    int desnaDuzina = 0;
    if(tree == NULL) return 0;
    levaDuzina = maxDepth(tree->left);
    desnaDuzina = maxDepth(tree->right);
    return (levaDuzina>desnaDuzina ? levaDuzina : desnaDuzina)+1;
}
int countNodesAtLevel(NODE *tree, int level){
    if(tree == NULL) return 0;
    if(level == 0) return 1;
    int leftSide=countNodesAtLevel(tree->left, level-1);
    int rightSide=countNodesAtLevel(tree->right, level-1);
    return leftSide+rightSide;
}
void ispisiNivo(NODE *tree, int level){
    if(tree == NULL) return;
    if(level == 0) {printf("%d", tree->data); return; }
    ispisiNivo(tree->left, level-1);
    ispisiNivo(tree->right, level-1);

}
int zbirNivoa(NODE *tree, int level){
    int s=0;
    if(tree){
        if(level == 1) s=tree->data;
    s+=zbirNivoa(tree->right, level-1)+zbirNivoa(tree->left, level-1);
    }
    return s;
}
int sumOfLeaves(NODE *tree){
    int s=0;
    if(tree){
    if(tree->left == NULL && tree->right==NULL){
    s+=tree->data;}
    s+=sumOfLeaves(tree->left);
    s+=sumOfLeaves(tree->right);}
    return s;
}
int maxElement(NODE *tree){
    if(tree==NULL) return 0;
    int max=tree->data;
    int leftMax=maxElement(tree->left);
    int rightMax=maxElement(tree->right);
    if(leftMax>rightMax) max = leftMax;
    if(rightMax>leftMax) max = rightMax;
    return max;
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
    printf("just leaves\n");
    printLeaf(root);
    printf("suma svih elemenata u stablu je %d\n", suma(root));
    printf("broj svih elemenata u stablu je %d\n", brojEl(root));
    if(postoji(root, 1)) printf("element postoji\n");
    else printf("element NE postoji\n");
    if(postoji(root, 8)) printf("element postoji\n");
    else printf("element NE postoji\n");
    printf("dubina stabla %d\n", maxDepth(root)) ;
    printf("broj elemenata na datom nivou %d\n", countNodesAtLevel(root, 3));
ispisiNivo(root, 3);
printf("\nzbir nivoa %d\n", zbirNivoa(root,2));
printf("zbir svih listova je %d\n", sumOfLeaves(root));
printf("Najveci element %d", maxElement(root));



}