
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct bstnode_t {
    int key, distance, upval;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root, *_top;
    unsigned int _size;
} BST;

BSTNode* __bst__createNode(int value, int distance) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->distance = distance;
    newNode->upval = -1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value, int distance) {
    if (root == NULL)
        return __bst__createNode(value, distance);

    if (value < root->key)
    {
        root->left = __bst__insert(root->left, value, distance);
        root->left->upval = root->key; //cetak value parent node nya
	}
    else if (value > root->key)
    {
        root->right = __bst__insert(root->right, value, distance);
    	root->right->upval = root->key; //cetak value parent node nya
	}
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
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

BSTNode* __bst__findMinNode(BSTNode *node) {
    BSTNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    
    return currNode;
}

BSTNode* __bst__remove(BSTNode *root, int value) {
    if (root == NULL) return NULL;

    if (value > root->key) 
        root->right = __bst__remove(root->right, value);
    else if (value < root->key) 
        root->left = __bst__remove(root->left, value);
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

        BSTNode *temp = __bst__findMinNode(root->right);
        root->key     = temp->key;
        root->right   = __bst__remove(root->right, temp->key);
    }
    return root;
}


void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_top = NULL;
    bst->_size = 0u;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;

    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value, int distance) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value, distance);
        if(bst->_top == NULL) // kalo root pertama masih kosong diisi root yang paling pertama
        {
        	bst->_top = bst->_root;
		}
        bst->_size++;
    }
}



int bst_countLR(BST *bst, int value)
{
	// deklarasi total jarak tempuh pake -1 biar tahu pernah jalan atau nggak
	int temp1 = -1;
	int temp2 = -1;

	bst->_root = __bst__search(bst->_top, value);// pastikan node lokasinya bener

	if(bst->_root->left == NULL && bst->_root->right == NULL)// kalo nggak bisa ke kiri / kanan (ketemu jalan keluar)
	{
		return(0); // keluar (distancenya 0)
	}

	// kalo bisa ke kiri
	bst->_root = __bst__search(bst->_top, value);// pastikan node lokasinya bener
	if(bst->_root->left != NULL)
	{
		temp1 += bst->_root->left->distance;
		temp1 += bst_countLR(bst, bst->_root->left->key);
	}

	//kalo bisa ke kanan
	bst->_root = __bst__search(bst->_top, value);// pastikan node lokasinya bener
	if(bst->_root->right != NULL)
	{
		temp2 += bst->_root->right->distance;
		temp2 += bst_countLR(bst, bst->_root->right->key);
	}

	// kalo ga bisa ke salah satu jalan
	if(temp1 == -1)
	{
		temp2++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return temp2;
	}
	else if(temp2 == -1)
	{
		temp1++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return temp1;
	} // kalo dua"nya valid cari yang paling efisien
	else if(temp1 <= temp2)
	{
		temp1++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp1);
	}
	else if(temp2 < temp1)
	{
		temp2++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp2);
	}
	return 0;
}

int bst_countUp(BST *bst, int up, int prev)
{
	//deklarasi total jarak tempuh pake -1 biar tahu pernah jalan nggak
	int temp1 = -1;
	int temp2 = -1;
	int temp3 = -1;

	bst->_root = __bst__search(bst->_top, up); //pastikan root berada di posisi yang benar
	if(bst->_root->upval != -1) //kalo masih bisa naik lagi
	{
		temp1 += bst->_root->distance; //total jarak kalo naik ke atas
		temp1 += bst_countUp(bst, bst->_root->upval, bst->_root->key); //rekursi cek jalan ke atas
	}

	bst->_root = __bst__search(bst->_top, up); //pastikan root berada di posisi yang benar
	if(bst->_root->left != NULL && bst->_root->left->key != prev) //kalo bisa ke kiri dan bukan ke tempat yang sama
	{
		temp2 += bst->_root->left->distance;
		temp2 += bst_countLR(bst, bst->_root->left->key);
	}

	bst->_root = __bst__search(bst->_top, up); //pastikan root berada di posisi yang benar
	if(bst->_root->right != NULL && bst->_root->right->key != prev) //kalo bisa ke kanan dan bukan ke tempat yang sama
	{
		temp3 += bst->_root->right->distance;
		temp3 += bst_countLR(bst, bst->_root->right->key);
	}
	
	if(temp2 == -1 && temp3 == -1) // kalo nggak bisa ke kiri dan kanan
	{	
		temp1++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp1);		
	}
	else if(temp1 == -1 && temp3 == -1) // kalo nggak bisa ke atas dan kanan
	{
		temp2++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp2);
	}
	else if(temp1 == -1 && temp2 == -1)// kalo nggak bisa ke atas dan kiri
	{
		temp3++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp3);
	}

	// kalo cuma ada satu jalan yang nggak valid
	if(temp1 == -1)
	{
		temp1 += temp2 + temp3;
	}
	if(temp2 == -1)
	{
		temp2 += temp1 + temp3;
	}
	if(temp3 == -1)
	{
		temp3 += temp2 + temp1;
	}
	
	// cek rute paling efisien
	if(temp1 <= temp2 && temp1 <= temp3)
	{
		temp1++;
		return(temp1);
	}
	else if (temp2 < temp1 && temp2 <= temp3)
	{
		temp2++;
		return(temp2);
	}
	else
	{
		temp3++;
		return(temp3);
	}
	return 0;
}

int bst_count(BST *bst, int value)
{
	// deklarasi total jarak tempuh pake -1 biar tahu pernah jalan nggak
	int temp1 = -1;
	int temp2 = -1;
	int temp3 = -1;

	bst->_root = __bst__search(bst->_top, value); //pastikan root berada di posisi yang benar

	if(bst->_root->left == NULL && bst->_root->right == NULL) //kalo di kiri sama kanan null berarti sudah di tempat keluar
	{
		return 0; //jadi langsung out 0
	}

	//kalo masih bisa ke atas
	if(bst->_root->upval != -1)
	{
		temp1 += bst->_root->distance; // hitung jarak yang ditempuh ke atas
		temp1 += bst_countUp(bst, bst->_root->upval, bst->_root->key);//hitung jika langkah pertama ke atas
	}
	
	//cek kalo bawah kiri kosong atau nggak
	bst->_root = __bst__search(bst->_top, value); //pastikan root berada di posisi yang benar
	if(bst->_root->left != NULL)
	{
		temp2 += bst->_root->left->distance;//total distance kalo pertama kali ke kiri
		temp2 += bst_countLR(bst, bst->_root->left->key);//total distance jalan selanjutnya
	}

	bst->_root = __bst__search(bst->_top, value); //pastikan root berada di posisi yang benar
	if(bst->_root->right != NULL)
	{
		temp3 += bst->_root->right->distance;//total distance kalo pertama kali ke kanan
		temp3 += bst_countLR(bst, bst->_root->right->key);//total distance jalan selanjutnya
	}

	// kalo ada jalan yang nggak valid (tetep -1)
	if(temp1 == -1)
	{
		temp1 += temp2 + temp3;
	}
	if(temp2 == -1)
	{
		temp2 += temp1 + temp3;
	}
	if(temp3 == -1)
	{
		temp3 += temp2 + temp1;
	}
	
	//cek jalan mana paling cepet
	if(temp1 <= temp2 && temp1 <= temp3)
	{
		temp1++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp1);
	}
	else if(temp2 <= temp1 && temp2 <= temp3)
	{
		temp2++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp2);
	}
	else if(temp3 <= temp2 && temp3 <= temp1)
	{
		temp3++; //ditambah 1 karena buat cek bisa jalan / nggak pake -1
		return(temp3);
	}
	return(0);
}

 
int main()
{
    BST set;
    bst_init(&set);

    int loop, value, distance, i;
    scanf("%d%d", &loop, &value); // cek berapa banyak data yang bakal di input + node pertama
    bst_insert(&set, value, 0);
    for(i = 0; i < loop - 1; i++) // hitung node selanjutnya (total - 1)
    {
    	scanf("%d%d", &value, &distance);
    	bst_insert(&set, value, distance);
	}

	scanf("%d", &loop); // cek berapa banyak test case bakal di tes
	for(i = 0; i < loop; i++)
	{
		scanf("%d", &value);
		printf("%d\n", bst_count(&set, value));
	}
    
    return 0;
}