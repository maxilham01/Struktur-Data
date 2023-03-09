#include <stdio.h>
#include <string.h>

#define MAX_N 10001 // Maksimum kapasitas deque

int arr[MAX_N]; // Array untuk menyimpan elemen-elemen deque
int front = -1, back = -1; // Front dan back sebagai indeks elemen terdepan dan terbelakang

// Fungsi untuk menambahkan elemen di depan deque
void push_front(int val) {
    if (front == -1 && back == -1) { // Jika deque kosong
        back++; 
        front++; 
        arr[front] = val; // Tambahkan elemen ke deque
    } 
    else  // Jika deque tidak kosong
    {
        for (int i = back; i >= 0; i--) // Geser elemen ke belakang
        {
            arr[i + 1] = arr[i];
        }
        back++; // Naikkan indeks back
        arr[0] = val; // Tambahkan elemen di depan
    } 
}

// Fungsi untuk menambahkan elemen di belakang deque
void push_back(int val) {
        back++; // Naikkan indeks back
        arr[back] = val; // Tambahkan elemen di belakang
}

// Fungsi untuk menghapus elemen terbelakang deque
void pop_back() {
    back--; // Turunkan indeks back
}

// Fungsi untuk menghapus elemen terdepan deque
void pop_front() {
    for (int i = 0; i <= back; i++) // Geser elemen ke depan
    {
        arr[i]=arr[i+1];
    }
    back--; // Turunkan indeks back
}

int main() {
    int n, val;
    scanf("%d", &n); // Input banyaknya operasi yang akan dilakukan

    char cmd[30]; // String untuk menyimpan perintah operasi
    for (int i = 0; i < n; i++) { // Lakukan operasi sebanyak n kali
        scanf("%s", cmd); // Input perintah operasi
        if (strcmp(cmd, "push_front") == 0) { // Jika perintah adalah push_front
            scanf("%d", &val); // Input elemen yang akan ditambahkan
            push_front(val); // Panggil fungsi push_front
        } 
        if (strcmp(cmd, "push_back") == 0) { // Jika perintah adalah push_back
            scanf("%d", &val); // Input elemen yang akan ditambahkan
            push_back(val); // Panggil fungsi push_back
        }
        if (strcmp(cmd, "pop_back") == 0) { // Jika perintah adalah pop_back
            pop_back(); // Panggil fungsi pop_back
        }
        if (strcmp(cmd, "pop_front") == 0) { // Jika perintah adalah pop_front
            pop_front(); // Panggil fungsi pop_front
        }
        
    }
    for (int i = 0; i <= back; i++) // Cetak elemen-elemen deque
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
