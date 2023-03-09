#include <stdio.h>

#define MAX_T 100


int T, N[MAX_T];
int C;

int findSum(int i, int j, int k) {
    return N[i] + N[j] + N[k];
}

int main() {
    // Membaca input
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N[i]);
    }
    scanf("%d", &C);

    // Mencari tiga kelompok kambing yang berjumlah C
    int found = 0;
    for (int i = 0; i < T && !found; i++) {
        for (int j = i + 1; j < T && !found; j++) {
            for (int k = j + 1; k < T && !found; k++) {
                if (findSum(i, j, k) == C) {
                    found = 1;
                }
            }
        }
    }

    // Menampilkan output
    if (found) {
        printf("ManTap\n");
    } else {
        printf("HAiiyyaAhh SalAhh\n");
    }

    return 0;
}
