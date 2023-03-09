#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Mendefinisikan struktur Node untuk merepresentasikan node dalam linked list
typedef struct Node {
    int data; // Data yang disimpan pada node
    struct Node* next; // Pointer ke node berikutnya 
} Node;

// Mendefinisikan struktur Stack untuk merepresentasikan tumpukan
typedef struct Stack {
    Node* top; // Pointer ke node paling atas pada tumpukan
    unsigned size; // Ukuran tumpukan
} Stack;

// Fungsi untuk menginisialisasi tumpukan
void initStack(Stack* stack) {
    stack->size = 0; // Mengatur ukuran tumpukan menjadi 0
    stack->top = NULL; // Mengatur pointer top ke NULL
}

// Fungsi untuk memeriksa apakah tumpukan kosong atau tidak
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Fungsi untuk menambahkan elemen ke dalam tumpukan
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Mengalokasikan memori untuk node baru
    if (newNode) // Jika alokasi memori berhasil
    {
        stack->size++; // Meningkatkan ukuran tumpukan
        newNode->data = value; // Mengisi data pada node baru dengan nilai yang diberikan
        if (isEmpty(stack)) // Jika tumpukan kosong
        {
            newNode->next = NULL; // Pointer next pada node baru diatur ke NULL
        }
        else // Jika tumpukan tidak kosong
        {
            newNode->next = stack->top; // Pointer next pada node baru diatur ke node paling atas pada tumpukan
        }
        stack->top = newNode; // Mengatur pointer top ke node baru
    }
}

// Fungsi untuk menghapus elemen teratas dari tumpukan
void pop(Stack* stack) {
    if (!isEmpty(stack)) { // Jika tumpukan tidak kosong
        Node* temp = stack->top; // Menyimpan pointer ke node paling atas pada tumpukan
        stack->top = stack->top->next; // Mengatur pointer top ke node di bawahnya
        free(temp); // Membebaskan memori yang dialokasikan untuk node yang dihapus
        stack->size--; // Mengurangi ukuran tumpukan
    }
}

// Fungsi untuk mendapatkan nilai elemen teratas pada tumpukan
int top(Stack* stack) {
    if (!isEmpty(stack)) { // Jika tumpukan tidak kosong
        return stack->top->data; // Mengembalikan nilai pada node paling atas
    }
    return 0; // Mengembalikan 0 jika tumpukan kosong
}

// Fungsi untuk mendapatkan ukuran tumpukan
unsigned size(Stack* stack) {
    return stack->size; // Mengembalikan nilai ukuran tumpukan
}

// Fungsi utama
int main() {
    Stack stack; // Deklarasi tumpukan
    initStack(&stack); // Menginisialisasi tumpukan
    // push elemen 10005 sebagai nilai batas bawah stack
    push(&stack, 10005);

    long long n, sum = 0;
    scanf("%lld", &n);

    // loop sebanyak n kali untuk input nilai setiap elemen
    for (long long i = 0; i < n; i++) {
        long long weight;
        scanf("%lld", &weight);

        // selama nilai weight lebih besar dari nilai elemen paling atas pada stack, pop elemen tersebut
        while (weight >= top(&stack)) {
            pop(&stack);
            sum += (weight < top(&stack) ? weight : top(&stack)); // tambahkan nilai weight atau nilai elemen paling atas stack, mana yang lebih kecil, ke variabel sum
        }

        // push nilai weight ke stack
        push(&stack, weight);
    }

    // pop elemen terakhir pada stack (yaitu nilai batas bawah stack)
    pop(&stack);

    // selama nilai paling atas pada stack bukan 10005, pop elemen dan tambahkan ke variabel sum
    while (top(&stack) != 10005) {
        sum += top(&stack);
        pop(&stack);
    }

    // keluarin nilai variabel sum
    printf("%lld\n", sum);

    return 0;
}