#include <stdio.h>
#include <conio.h>

struct node //struktur untuk node
{
    int data;
    struct node *next;
};

struct node n1, n2, n3; //tiga struktur variabel untuk membuat linked list node


//variabel jenis pointer struktur untuk menyimpan alamat node pertama 
//dan node sementara dalam linked list
struct node *first, *temp; 

int main (){
    n1.data = 10; //Masukkan 10 data ke dalam node pertama N1 
    n1.next =&n2; //lampirkan node kedua yaitu n2 ke node pertama n1 dengan mengatasi alamat 
    // dari n2 ke bidang berikutnya dari node n1
    n2.data = 20;
    n2.next =&n3;
    n3.data=30;
    n3.next=NULL; //salin alamat 'NULL' ke dalam bidang node n3 berikutnya
    first=&n1; //tetapkan alamat node n1 ke struktur awal pointer
    temp= first; //tetapkan alamat node pertama ke dalam penunjuk temp untuk melintasi 
    while (temp!=NULL) //sampai temp pointer tidak berisi alamat NULL mengeksekusi while loop
    {
        printf("\n%d",temp->data); // menampilkan data ke dalam node temp
        temp=temp->next; //Memindahkan penunjuk temp ke node berikutnya ke linked list
    }
    return 0;


}