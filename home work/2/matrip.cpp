#include <iostream>
using namespace std;

// struktur node BST
struct Node {
    int key;
    int distance;
    Node* left;
    Node* right;
};

// fungsi untuk menambah node pada BST
Node* insert(Node* root, int key, int distance) {
    if (root == NULL) {
        Node* node = new Node;
        node->key = key;
        node->distance = distance;
        node->left = node->right = NULL;
        return node;
    }
    if (key < root->key)
        root->left = insert(root->left, key, distance);
    else if (key > root->key)
        root->right = insert(root->right, key, distance);
    return root;
}

// fungsi untuk mencari jarak minimal dari suatu node ke root pada BST
int findDistance(Node* root, int key) {
    if (root == NULL)
        return -1;
    if (root->key == key)
        return root->distance;
    if (key < root->key)
        return findDistance(root->left, key) + root->distance;
    else
        return findDistance(root->right, key) + root->distance;
}

int main() {
    int n, r;
    cin >> n >> r;

    // membuat BST berdasarkan input
    Node* root = NULL;
    for (int i = 0; i < n-1; i++) {
        int a, w;
        cin >> a >> w;
        root = insert(root, a, w);
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int b;
        cin >> b;
        cout << findDistance(root, b) << " ";
    }

    return 0;
}
