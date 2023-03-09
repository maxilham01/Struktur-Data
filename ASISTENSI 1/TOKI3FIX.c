#include <stdio.h>
#include <string.h>

int deque[100000001];

int main(){
    int N;
    scanf("%d", &N);
    
    
    int deque_size = 0;
    char command[4];
    int X, Y;
    int offset = 0;
    while(N--){
        scanf("%s", command);
        //Jika command adalah "add", 
        //program akan membaca dua nilai X dan Y yang merepresentasikan nilai elemen yang akan ditambahkan ke dalam deque sebanyak Y kali. 
        //Selanjutnya, nilai X akan ditambahkan ke dalam array deque sebanyak Y kali dengan menggunakan perulangan for, dan ukuran deque akan diupdate.
        if(strcmp(command,"add")==0){
            scanf("%d %d", &X, &Y);

            for(int i = 0;i<Y;i++){
                deque[deque_size] = X-offset;
                deque_size++;
            }

            printf("%d\n", deque_size);
        }
        //Jika command adalah "del", program akan membaca nilai X yang merupakan jumlah elemen yang akan dihapus dari deque.
        //Selanjutnya, program akan mencetak elemen terakhir dari deque dengan menambahkan nilai offset dan deque_size akan dikurangi sebanyak X.
        else if(strcmp(command, "del")==0){
            scanf("%d", &X);
            printf("%d\n", deque[deque_size-1]+offset);
            for(int i = 0;i<X;i++){
                deque_size--;
            }
        }
        //Jika command adalah "adx", program akan membaca nilai X yang merupakan nilai offset yang akan ditambahkan pada semua elemen pada deque.
        else if(strcmp(command,"adx")==0){
            scanf("%d", &X);
            offset += X;
        }
        //Jika command adalah "dex", program akan membaca nilai X yang merupakan nilai offset yang akan dikurangi pada semua elemen pada deque.
        else if(strcmp(command,"dex")==0){
            scanf("%d", &X);
            offset -= X;
        }
    }

    return 0;
}