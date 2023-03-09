#include <stdio.h>

int main() {
    int n, i, j;
    long long s = 0; //gunakan tipe data long long untuk menyimpan nilai S karena hasilnya bisa sangat besar
    scanf("%d", &n);
    int h[n], a[n]; //h menyimpan tinggi badan bebek, a menyimpan nilai Ai
    for (i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        a[i] = 1; //setiap bebek pasti dapat mengintip dirinya sendiri, sehingga nilai awal Ai adalah 1
        //cari bebek-bebek yang dapat diintip oleh bebek i dan update nilai Ai
        for (j = i-1; j >= 0 && h[j] <= h[i]; j--) {
            a[i] += a[j];
        }
    }
    //jumlahkan semua nilai Ai untuk mendapatkan nilai S
    for (i = 0; i < n; i++) {
        s += a[i];
    }
    printf("%lld\n", s);
    return 0;
}
