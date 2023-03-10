#include <iostream>
using namespace  std;

int main ()
{
    int loop, hadir = 0, gakhadir  =0;

    cin>> loop;

    while(loop--)
    {   
        int nilai;
        cin>> nilai;
        if (nilai== 1 )
        {
            hadir++;
        }
        
        else 
        {
            gakhadir++;
        }
        
    }
    cout << hadir << " " << gakhadir<<endl;
    return 0;
}
    