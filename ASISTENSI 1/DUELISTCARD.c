#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur Node
struct Node {
    int data;
    int max;
    int min;
    struct Node* next;
};

// Pointer ke Head Stack
struct Node* head = NULL;

// Fungsi push, digunakan untuk menambahkan elemen ke stack
void push(int data) {
    // Membuat node baru
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;

    // Jika stack kosong, inisialisasi nilai max dan min dengan data
    if (head == NULL) {
        node->max = data;
        node->min = data;
    }

    else {
    // Jika stack tidak kosong, update nilai max dan min sesuai dengan data
        //Jika data baru lebih besar dari nilai maksimum pada elemen paling atas
        if (data > head->max) {
            node->max = data; // nilai maksimum pada elemen baru adalah data
        } else {
            node->max = head->max; // nilai maksimum pada elemen baru sama dengan nilai maksimum pada elemen paling atas sebelumnya
        }
        //jika data baru lebih kecil dari nilai minimum pada elemen paling atas
        if (data < head->min) {
            node->min = data; // nilai minimum pada elemen baru adalah data
        } else {
            node->min = head->min; // nilai minimum pada elemen baru sama dengan nilai minimum pada elemen paling atas sebelumnya
        }
    }

    // Menambahkan node ke stack
    node->next = head;
    head = node;
}

// Fungsi pop, digunakan untuk menghapus elemen dari stack
void pop() {
    // Jika stack kosong, keluarkan pesan error dan keluar dari fungsi
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    // Menghapus elemen dari stack dan mencetak pesan berhasil
    int data = head->data; // Ambil nilai dari elemen teratas stack
    head = head->next; // Geser pointer head ke elemen selanjutnya di stack
    free(head); // Bebaskan memori dari elemen teratas stack
    printf("Popped %d from stack\n", data);
}

// Fungsi top, digunakan untuk menampilkan elemen teratas pada stack
void top() {
    // Jika stack kosong, keluarkan pesan error dan keluar dari fungsi
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    // Menampilkan elemen teratas pada stack
    printf("Top of stack is %d\n", head->data);
}

// Fungsi max, digunakan untuk menampilkan nilai maksimum pada stack
void max() {
     // Jika stack kosong, keluarkan pesan error dan keluar dari fungsi
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    // Menampilkan nilai maksimum pada stack
    printf("Maximum value in stack is %d\n", head->max);
}

// Fungsi min, digunakan untuk menampilkan nilai minimum pada stack
void min() {
     // Jika stack kosong, keluarkan pesan error dan keluar dari fungsi
    if (head == NULL) {
        printf("Stack is empty!\n");
        return;
    }

    // Menampilkan nilai minimum pada stack
    printf("Minimum value in stack is %d\n", head->min);
}


int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char command[5];
        int data;
        scanf("%s", command);


        if (strcmp(command, "push") == 0) {
            scanf("%d", &data);
            push(data);
        } else if (strcmp(command, "pop") == 0) {
            pop();
        } else if (strcmp(command, "top") == 0) {
            top();
        } else if (strcmp(command, "max") == 0) {
            max();
        } else if (strcmp(command, "min") == 0) {
            min();
        } else {
            printf("Invalid command!\n");
        }
    }
}
   
