#include <stdio.h>
#include <stdlib.h>

// Struktur node BST
typedef struct Node {
    int security; // data pada node
   // int ram; // jumlah value node pada level tersebut
    struct Node* left;
    struct Node* right;
} Node;

// Fungsi untuk membuat node baru
Node* newNode(int security) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->security = security;
    //node->ram = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fungsi untuk menambahkan node ke dalam BST
Node* insert(Node* root, int security) {
    // Jika root kosong, buat node baru dengan data security dan ram 
    if (root == NULL) {
        return newNode(security);
    }
    // Jika security kurang dari data pada root, masukkan ke subtree kiri
    if (security < root->security) {
        root->left = insert(root->left, security);
    } 
    // Jika security lebih dari data pada root, masukkan ke subtree kanan
    else if (security > root->security) {
        root->right = insert(root->right, security);
    }
    return root;
}

// Fungsi rekursif untuk menghitung total value node pada suatu level
int sumLevel(Node* root, int level) {
    if (root == NULL) { // Jika root kosong, return 0
        return 0;
    }
    if (level == 0) { // Jika level = 0, maka jumlahkan value node pada level tersebut
        return root->security;
    }
    // Panggil fungsi sumLevel rekursif untuk subtree kiri dan kanan dengan level-1
    return sumLevel(root->left, level - 1) + sumLevel(root->right, level - 1);
}

// Fungsi untuk menampilkan hasil output
void printResult(int level, int ram) {
    printf("Level %d: %d\n", level, ram);
}

int main() {
    int Q, type, arg; // Deklarasi variabel untuk input Q, tipe query, dan argumen query
    Node* root = NULL;
    scanf("%d", &Q); // Input banyaknya query
    for (int i = 0; i < Q; i++) { // Loop untuk menerima input dan menjalankan query sejumlah Q
        scanf("%d %d", &type, &arg); // Input tipe query dan argumen query
        if (type == 1) { // Jika tipe query 1, tambahkan node dengan nilai security argumen
            root = insert(root, arg);
        } else if (type == 2) { // Jika tipe query 2, hitung jumlah value node pada level argumen
            int level = arg;
            int ram = sumLevel(root, level);
            if (ram == 0) {  // Jika jumlah value pada level tersebut = 0, print "GG EZ"
                printf("GG EZ\n");
            } else { // Jika jumlah value pada level tersebut > 0, tampilkan hasil output menggunakan fungsi printResult
                printResult(level, ram);
            }
        }
    }
    return 0;
}
