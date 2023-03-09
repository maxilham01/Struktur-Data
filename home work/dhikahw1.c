#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct bstnode_t{
    struct bstnode_t *left;
    int data;
    struct bstnode_t *right;
}BSTNode;

typedef struct bst_t{
    BSTNode *root;
}BST;

BSTNode* createNode(int value){
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void init(BST *bst){
    bst->root = NULL;
}

bool isEmpty(BST *bst){
    return bst->root == NULL;
}

BSTNode* sorted_to_bst(int* arr, int start, int end){
    if(start>end) return NULL;
    float rata2 = (float)(start+end)/2;
    int mid = round(rata2);
    BSTNode* root = (BSTNode*) malloc(sizeof(BSTNode));
    root->data = arr[mid];
    root->left = sorted_to_bst(arr, start, mid - 1);
    root->right = sorted_to_bst(arr, mid+1, end);
    return root;
}

void inorder(BSTNode *root){
    if(root == NULL) return;
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
}

void preorder(BSTNode *root){
    if(root == NULL) return;
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
}

void postorder(BSTNode *root){
    if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
}

int main(){
    BST myBST;
    init(&myBST);
    int N, value;
    scanf("%d", &N);
    int* arr = (int*) malloc(N* sizeof(int));
    for(int i=0; i<N; i++){ //3 6 7 9 11  7 6 3 11 9
        scanf("%d", &arr[i]);
    }
    
    myBST.root = sorted_to_bst(arr, 0, N-1);
    
    preorder(myBST.root);
    printf("\n");
    inorder(myBST.root);
    printf("\n");
    postorder(myBST.root);
    printf("\n");

    return 0;
}