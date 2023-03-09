#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

typedef struct bstnode_t {
    int key;
      struct bstnode_t *left, *right;
}     BSTNode;

typedef struct bst_t {
      BSTNode *_root;
      unsigned int _size;
} BST;

BSTNode* _bst_createNode(int value) {
  BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
  newNode->key = value;
  newNode->left = newNode->right = NULL;
  return newNode;
}
BSTNode* _bst_insert(BSTNode *root, int value) {
  if (root == NULL)
      return _bst_createNode(value);

  if (value < root->key)
    root->left = _bst_insert(root->left, value);
  
  else if (value > root->key)
      root->right = _bst_insert(root->right, value);
  
  return root;
}

BSTNode* _bst_search(BSTNode *root, int value) {
  while (root != NULL) {
    if (value < root->key)
      root = root->left;
    else if (value > root->key)
      root = root->right;
    else
      return root;
  }
  return root;
}

BSTNode* _bst_findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* _bst_remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key)
        root->right = _bst_remove(root->right, value);
    else if (value < root->key)
        root->left = _bst_remove(root->left, value);
    else {
        
        if (root->left == NULL) {
            BSTNode *rightChild = root->right;
            free(root);
            return rightChild;
        }
        else if (root->right == NULL) {
            BSTNode *leftChild = root->left;
            free(root);
            return leftChild;
        }

        BSTNode *temp = _bst_findMinNode(root->right);
        root->key     = temp->key;
        root->right   = _bst_remove(root->right, temp->key);
    }
    return root;
}

bool bst_find(BST *bst, int value) {
      BSTNode *temp = _bst_search(bst->_root, value);
      if (temp == NULL)
        return false;
  
      if (temp->key == value)
        return true;
      else
        return false;
}
 
void bst_Parent(BSTNode *root, int num, int prnt){
    
    if(root == NULL)
        
        return;
    
    if(root->key == num){
        
        printf("%d ", prnt);
    }
    
    else {
        bst_Parent(root->left, num, root->key);
        bst_Parent(root->right, num,root->key);
    }
    
}

void bst_fndprnt (BST *bst, int X){
    
    bst_Parent(bst->_root, X, -1);
}


void bst_fndchld(BST *bst, int num){
    if (!bst_find(bst, num)){
        
        printf("404 Not Found\n");
    }
    
    else {
        
        BSTNode *temp =  _bst_search(bst->_root, num);
     
        if(temp != NULL){
            if(temp->left != NULL)
            printf("%d ", temp->left->key);
            
            if(temp->right != NULL)
            printf("%d ", temp->right->key);
        
            printf("\n");
        }
        else
            
            return;
    }
}

void bst_init(BST *bst) {
    
      bst->_root = NULL;
      bst->_size = 0;
    
}


bool bst_isEmpty(BST *bst) {
    
      return bst->_root == NULL;
}
void bst_insert(BST *bst, int value) {
    
      if (!bst_find(bst, value)) 
      {
            bst->_root = _bst_insert(bst->_root, value);
            bst->_size++;
          
  }
    
}

int main()
{
    BST tree;
    bst_init(&tree);
    
    int N, K, X, M;
    scanf("%d", &K);
    
    for (int c = 0; c < K; c++) 
    {
        scanf("%d", &N);
        bst_insert(&tree, N);
    }
    
    scanf("%d", &M);
    
    
    for (int c = 0; c < M; c++) 
    {
        scanf("%d", &X);
        
        bst_fndprnt(&tree, X);
        bst_fndchld(&tree, X);
    }
    
  return 0;
    
}