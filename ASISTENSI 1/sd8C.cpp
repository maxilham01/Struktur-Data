#include <vector>
#include <iostream>

int main(){
    // total query
    int q;
    std::cin >> q;

    int a[10];
    std::vector<int>v;

    // vector (simulasi stacc) (gak harus pake vector, bisa pake stack)
    std::vector<int> vec;

    // query
    std::string query;
    int X, Y;
    int offset = 0;
    while(q--){
        std::cin >> query;
        if(query=="add"){
            std::cin >> X >> Y;

            for(int i = 0;i<Y;i++){
                vec.push_back(X-offset);
            }

            // cetak berapa ada isi stack
            std::cout << vec.size() << "\n";
        }
        else if(query == "del"){
            std::cin >> X;
            // cetak bilangan pertama yang dihapus (yang paling belakang) + offset
            std::cout << vec.back() + offset << "\n";
            
            // hapus X elemen terakhir
            for(int i = 0;i<X;i++){
                vec.pop_back();
            }
        }
        else if(query=="adx"){
            std::cin >> X;
            // instead of nambah ke semua elemen, nambah ke offset
            offset += X;
        }
        else if(query=="dex"){
            std::cin >> X;
            // instead of ngurangin ke semua elemen, ngurangin ke offset biar gak perlu ngurangin ke semua elemen (optimasi)
            offset -= X;
        }
    }

    return 0;
}