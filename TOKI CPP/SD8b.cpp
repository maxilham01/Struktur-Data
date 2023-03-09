#include <iostream>
#include <deque>



int main (){
    int loop;
    std:: cin >> loop;

    std:: deque<int>testdeque;

    bool asscending = true;
    std:: string command;
    int x, y;
    for (int i = 0; i < loop; i++)
    {
        std:: cin>> command;
        if (command== "add")
        {
            std::cin >> x >> y;
            for (int i = 0; i < y; i++)
            {
                if (asscending)
                {
                    testdeque.push_back (x);
                }
                else
                {
                    testdeque.push_front(x);
                }
                
            }
            
        }
        
    }
    
    
}