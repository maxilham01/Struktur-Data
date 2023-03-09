#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

// Deklarasi deque, ukuran deque, dan offset
int deque[MAX_SIZE];
int deque_size = 0;
int offset = 0;

// Fungsi untuk menambahkan elemen ke deque sebanyak Y kali dengan nilai X
void add(int x, int y) {
    for (int i = 0; i < y; i++) {
        deque[deque_size] = x - offset;
        deque_size++;
    }
    printf("%d\n", deque_size);
}

// Fungsi untuk meng hapus X elemen terakhir dari deque, jika X lebih besar dari ukuran deque, maka semua elemen akan dihapus
void del(int x) {
    if (x > deque_size) {
        x = deque_size;
    }
    int last_element = deque[deque_size - 1] + offset;
    deque_size -= x;
    printf("%d\n", last_element);
}

// Fungsi untuk menambahkan X pada offset
void adx(int x) {
    offset += x;
}

// Fungsi untuk mengurangi X pada offset
void dex(int x) {
    offset -= x;
}

int main() {
    int n;
    scanf("%d", &n);
    char command[10];
    int x, y;
    while (n--) {
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            scanf("%d %d", &x, &y);
            add(x, y);
        } else if (strcmp(command, "del") == 0) {
            scanf("%d", &x);
            del(x);
        } else if (strcmp(command, "adx") == 0) {
            scanf("%d", &x);
            adx(x);
        } else if (strcmp(command, "dex") == 0) {
            scanf("%d", &x);
            dex(x);
        }
    }
    return 0;
}
