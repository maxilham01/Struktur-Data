#include <deque>
#include <iostream>

int main(){
    // total query
    int q;
    std:: cin >> q;

    // queue
    std::deque<int> qe;
    bool frontIsFront = true;

    // query
    std::string query;
    int X, Y;
    while(q--){
        std::cin >> query;

        if (query=="add"){
            std::cin >> X >> Y;
            for(int i = 0;i<Y ;i++){
                if (frontIsFront){
                    qe.push_back (X);
                }
                else{
                    qe.push_front (X);
                }
            }
            // cetak berapa ada isi queue
            std::cout << qe.size() << "\n";
        }
        else if(query=="del"){
            std::cin >> X;

            if (frontIsFront){
                // cetak bilangan pertama yang dihapus
                std::cout << qe.front() << "\n";
                for(int i = 0;i<X;i++){
                    qe.pop_front();
                }
            }
            else{
                // SAMA
                std::cout << qe.back() << "\n";

                for(int i = 0;i<X;i++){
                    qe.pop_back();
                }
            }

        }
        else if(query == "rev"){
            frontIsFront = !frontIsFront;
        }
    }
    return 0;
}
