#include <stack>
#include <vector>
#include <iostream>

int main(){
    int N;// total bebek
    std::cin >> N;


    long long S = 0;
    int h = 0;

    std::stack<int> bebek_pantau;
    std::vector<int> tinggi_bebek;

    while(N--){
        std::cin >> h;
        tinggi_bebek.push_back(h);
    }

    // cek dari belakang ke depan pantau berapa bebek yang bisa terlihat
    for(int i = tinggi_bebek.size() - 1; i >= 0; i--){
        
        // tiap bebek +1, karna bisa melihat dirinya sendiri
        S++;

        if(bebek_pantau.empty()){
            bebek_pantau.push(tinggi_bebek[i]);
        }else{
            // kalau ketemu yang lebih rendah dari bebek yang di pantau
            if(bebek_pantau.top() >= tinggi_bebek[i]){
                // semua bebek bisa melihat, jadi S+= ukuran stack (total bebek yang sedang mantau)
                S+=bebek_pantau.size();
                // masukin bebek ke stack untuk mantau
                bebek_pantau.push(tinggi_bebek[i]);
            }
            else{
                // ok, bebek yang di pantau lebih tinggi dari pemantau, keluarin semua bebek yang gak eligible
                while(!bebek_pantau.empty() && bebek_pantau.top() < tinggi_bebek[i]){
                    bebek_pantau.pop();
                }
                // tambahkan sisa bebek yang masih bisa mantau
                S+=bebek_pantau.size(); 
                // masukin bebek ke stack untuk mantau
                bebek_pantau.push(tinggi_bebek[i]);
            }
        }
    }

    std::cout << S << std::endl;

    return 0;
}