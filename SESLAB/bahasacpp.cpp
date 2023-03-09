#include <bits/stdc++.h>
/*
penggunaan library diatas adalah untuk mengurangi
penulisan library pada Bahasa C++ yang memang banyak
atau dalam kata lain, library diatas mengandung
semua library Bahasa C++

jika memiliki kesulitan dengan penggunaan library diatas,
fungsi sort ada pada library algorithm
*/
using namespace std;

int main(){
    vector<int> v{3, 4, 2, 5, 1, 7};
    /*
    proses inisialisasi sebuah vector
    tidaklah sama dengan inisialisasi array biasa
    */

    sort(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
        // vector akan urut secara ascending
    }
    cout << endl;

    sort(v.rbegin(), v.rend());

    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
        //vector akan urut secara descending
    }
    cout << endl;

    return 0;
}