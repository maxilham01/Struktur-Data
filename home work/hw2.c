#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// definisi struct untuk BST node
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

// fungsi untuk membuat node baru pada BST
struct Node* newNode(int val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// fungsi untuk memasukkan node ke BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        return newNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// fungsi untuk menghitung jumlah node pada suatu level pada BST
int countNodes(struct Node* root, int level) {
    if (root == NULL) {
        return 0;
    }
    if (level == 0) {
        return 1;
    }
    return countNodes(root->left, level-1) + countNodes(root->right, level-1);
}

// fungsi untuk menghitung rata-rata harga pada suatu level pada BST
float averagePrice(struct Node* root, int level) {
    int count = countNodes(root, level);
    if (count == 0) {
        return 0;
    }
    int sum = 0;
    if (level == 0) {
        sum = root->val;
    } else {
        if (root->left != NULL) {
            sum += countNodes(root->left, level-1) * root->left->val;
        }
        if (root->right != NULL) {
            sum += countNodes(root->right, level-1) * root->right->val;
        }
    }
    return (float)sum/count;
}

// fungsi untuk menghitung tinggi BST
int height(struct Node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
    int T;
    scanf("%d", &T);
    struct Node* root = NULL;

    // memasukkan harga-harga ke BST
    while (1) {
        int price;
        scanf("%d", &price);
        if (price == -1) {
            break;
        }
        root = insert(root, price);
    }

    // menghitung dan mencetak rata-rata harga untuk setiap level pada BST
    int treeHeight = height(root);
    for (int i = 0; i <= treeHeight; i++) {
        printf("Level %d = %.2f\n", i, averagePrice(root, i));
    }
    return 0;
}
