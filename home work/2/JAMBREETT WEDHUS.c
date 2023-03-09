#include <stdio.h>
#include <stdlib.h>

typedef struct __node{
    long long data;
    struct __node *left, *right, *parent;
} Node;

typedef struct {
    Node *root;
    unsigned __size;
} Bst;

// Membuat node baru
Node *createNode(long long data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> parent = NULL;
    return newNode;
}

// Inisialisasi BST
void bst_init(Bst* bst){
    bst->root = NULL;
    bst->__size = 0;
}

// Fungsi rekursif untuk memasukkan data ke BST
Node *__rec_bst_insert(Node* root, long long data){
    if(root==NULL) 
        return createNode(data);
		
	//Jika data yang akan dimasukkan lebih kecil dari data pada root, maka fungsi akan dipanggil rekursif pada subtree kiri
    if(data < root->data){
        root -> left = __rec_bst_insert(root->left, data);
        root -> left -> parent = root;
    }
	//Jika data yang akan dimasukkan lebih besar dari data pada root, maka fungsi akan dipanggil rekursif pada subtree kanan.
    else if(data > root->data){
        root -> right = __rec_bst_insert(root->right, data);
        root -> right -> parent = root;
    } 
    return root;
}

// Memasukkan data ke BST
void bst_insert(Bst* bst, long long data){
    bst->root = __rec_bst_insert(bst->root, data);
    bst->__size++;
}

long long isFound,yz;
// Fungsi untuk mencari apakah terdapat tiga node pada BST yang jumlah datanya sama dengan yz
void cari(Node* node){
    // Jika sudah ditemukan, keluar dari fungsi
    if(isFound){
        return;
    } else {
		// Jika node memiliki anak kiri dan kanan, dan jumlah data tiga node tersebut sama dengan yz, maka ditemukan
        if(node->left && node->right &&
            (node->data + node->right->data + node->left->data == yz) ){
            isFound=1; 
            return;
        }
        if(node->parent){
            long long temp = node->parent->data + node->data;
			 // Jika nilai yang dicari lebih besar dari data di node saat ini, dan node memiliki anak kanan
            if(yz-temp > node->data && node->right){
				// Jika jumlah data dari node saat ini dan anak kanan sama dengan yz, maka ditemukan
                if(temp + node->right->data == yz){
                    isFound=1;
                    return;
                } else
					// Pencarian dilanjutkan ke anak kanan
                    cari(node->right);
            } else if(node -> left){
				// Jika jumlah data dari node saat ini dan anak kiri sama dengan yz, maka ditemukan
                if(temp + node->left->data == yz){
                    isFound=1;
                    return;
                } else
				// Pencarian dilanjutkan ke anak kiri
                    cari(node->left);
            }
        } else {
			 // Jika node tidak memiliki orang tua, maka pencarian dilakukan pada kedua anaknya
            if(node->left)
                cari(node->left);
            if(node->right)
                cari(node->right);
        }
    }
}

int main(){
    Bst bst;
    bst_init(&bst);
    int n,x;
    isFound=0;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&x);
        bst_insert(&bst,x);
    }
    scanf("%lld",&yz);
    cari(bst.root);
    cari(bst.root->right);
    cari(bst.root->left);
    if(isFound) puts("ManTap");
    else puts("HAiiyyaAhh SalAhh");
    return 0;
}