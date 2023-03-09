#include <stdio.h>

long long tinggi_bebek[100001], bebek_dapat_diintip[100001], total_bebek_dapat_diintip; 

int main() {
    int jumlah_bebek;

    scanf("%d", &jumlah_bebek);

    for (int i = 1; i <= jumlah_bebek; i++) {
        scanf("%d", &tinggi_bebek[i]);
        bebek_dapat_diintip[i] = 1; // setiap bebek dapat mengintip dirinya sendiri

        // mencari banyaknya bebek yang dapat diintip oleh bebek nomor i
        for (int j = i-1; j >= 1; j--) {
            if (tinggi_bebek[j] <= tinggi_bebek[i]) { // jika tinggi bebek j kurang dari atau sama dengan tinggi bebek i
                bebek_dapat_diintip[i] += bebek_dapat_diintip[j]; // tambahkan jumlah bebek yang dapat diintip oleh bebek j ke jumlah bebek yang dapat diintip oleh bebek i
            }

            // menghindari pencarian ulang pada bebek yang tidak dapat diintip oleh bebek i
            j -= bebek_dapat_diintip[j] - 1;
        }

        total_bebek_dapat_diintip += bebek_dapat_diintip[i]; // tambahkan jumlah bebek yang dapat diintip oleh bebek i ke total jumlah bebek yang dapat diintip
    }

    printf("%lld\n", total_bebek_dapat_diintip);

    return 0;
}
