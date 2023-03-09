#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100000001 // Mendefinisikan ukuran maksimum antrian

int queue[MAX_QUEUE_SIZE]; // Deklarasi antrian
int back = -1; // Indeks terakhir pada antrian, awalnya -1 karena antrian masih kosong
int front = -1; // Indeks depan pada antrian, awalnya -1 karena antrian masih kosong

void enqueue(int x) {
    if (front == -1) { // Jika antrian masih kosong
        front++; // Maka indeks depan akan ditambah 1
    }
    back++; // Indeks belakang pada antrian selalu ditambah 1 karena elemen baru akan ditambahkan di belakang
    queue[back] = x; // Elemen baru ditambahkan ke antrian
}

void dequeue() {
    if (front <= back) { // Jika masih ada elemen pada antrian
        front++; // Maka indeks depan akan ditambah 1 untuk menghapus elemen pertama pada antrian
    }
}

void reverse() {
    int temp; // Variabel sementara untuk menukar nilai
    int mid = (back - front + 1) / 2; // Menghitung indeks tengah pada antrian
    for (int i = 0; i < mid; i++) {
        // Menukar nilai elemen pada posisi i dengan elemen pada posisi belakang - i
        temp = queue[back - i];
        queue[back - i] = queue[front + i];
        queue[front + i] = temp;
    }
}

int main() {
    int num_operations, value, num_values;
    char op[100];

    scanf("%d", &num_operations);

    for (int i = 0; i < num_operations; i++) {
        scanf("%s", op);

        if (strcmp(op, "add") == 0) {
            scanf("%d %d", &value, &num_values);
            for (int j = 0; j < num_values; j++) {
                enqueue(value); // Menambahkan elemen baru ke antrian
            }
            printf("%d\n", back - front + 1); // Menampilkan jumlah elemen pada antrian
        } 
        else if (strcmp(op, "del") == 0) {
            scanf("%d", &num_values);
            printf("%d\n", queue[front]); // Menampilkan nilai elemen pertama pada antrian
            for (int j = 0; j < num_values; j++) {
                dequeue(); // Menghapus elemen pada antrian
            }
        } 
        else if (strcmp(op, "rev") == 0) {
            reverse(); // Membalik urutan elemen pada antrian
        }
    }

    return 0;
}
