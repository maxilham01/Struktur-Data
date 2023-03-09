#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main (){
    int banyak, nilai ;
    string command;

    cin >> banyak;
    deque<int> testdeque;

    for (int i = 0; i < banyak; i++)
    {
        cin >> command;
        if (command == "push_front")
        {
            cin >> nilai;
            testdeque.push_front(nilai);
        }
        else if (command == "push_back")
        {
            cin >> nilai;
            testdeque.push_back(nilai);
        }
        else if (command == "pop_back")
        {
            testdeque.pop_back();
        }
        else
        {
            testdeque.pop_front();
        }
    }
    
    for (int i = 0; i < testdeque.size(); i++)
    {
        cout<< testdeque[i] << '\n';
    }

}