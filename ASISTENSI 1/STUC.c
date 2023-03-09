#include <stdio.h>
#include <string.h>

int main(){
    int loop;
    int atas = -1; // menyimpan posisi atas tumpukan

    scanf("%d", &loop);
    int tumpukan[loop]; // array untuk menyimpan nilai pada tumpukan
    int flag[loop]; // array untuk menyimpan jumlah angka pada setiap operasi add
    int jumlah_angka = 0; // menyimpan jumlah angka pada tumpukan
    char perintah[10]; // menyimpan perintah

    // melakukan perulangan sebanyak loop
    for (int i = 0; i < loop; i++)
    {
        int nilai, banyak;
        scanf("%s", perintah); // membaca perintah

        // jika perintah adalah add
        if(strcmp(perintah,"add")==0){
            // jika tumpukan penuh
            if(atas == loop - 1){
                printf("Tumpukan Penuh\n");
                return 0;
            }
            scanf("%d %d", &nilai, &banyak); // membaca nilai dan banyak data
            flag[++atas] = banyak; // menyimpan jumlah angka dari operasi add
            tumpukan[atas] = nilai; // menambahkan nilai ke tumpukan
            jumlah_angka += banyak; // menambahkan jumlah angka pada tumpukan
            printf("%d\n", jumlah_angka); // mencetak jumlah angka pada tumpukan
        }
        // jika perintah adalah del
        else if(strcmp(perintah, "del")==0){
            // jika tumpukan kosong
            if(atas == -1){
                printf("Tumpukan Kosong\n");
                return 0;
            }
            scanf("%d", &banyak); // membaca banyak data yang akan dihapus
            printf("%d\n", tumpukan[atas]); // mencetak nilai pada posisi atas tumpukan
            flag[atas] -= banyak; // mengurangi jumlah angka dari operasi add
            jumlah_angka -= banyak; // mengurangi jumlah angka pada tumpukan
            // menghapus data pada tumpukan sesuai dengan banyak data yang dihapus
            while (flag[atas] <= 0 && atas >= 0)
            {
                banyak = -1 * flag[atas];
                flag[--atas] -= banyak;
            }
        }
        // jika perintah adalah adx
        else if(strcmp(perintah,"adx")==0){
            // jika tumpukan kosong
            if(atas == -1){
                printf("Tumpukan Kosong\n");
                return 0;
            }
            scanf("%d", &nilai); // membaca nilai yang akan ditambahkan pada setiap data tumpukan
            // menambahkan nilai pada setiap data tumpukan
            for (int i = 0; i <= atas; i++)
            {
                tumpukan[i] += nilai;
            }
        }
        // jika perintah adalah dex
        else if(strcmp(perintah,"dex")==0){
            // jika tumpukan kosong
            if(atas == -1){
                printf("Tumpukan Kosong\n");
                return 0;
            }
            scanf("%d", &nilai); // membaca nilai yang akan dikurangi pada setiap data tumpukan
            // mengurangi nilai pada setiap data tumpukan;
            for (int i = 0; i <=atas; i++)
            {
                tumpukan[i] -= nilai;
            } 
        }
    }

    return 0;
}
