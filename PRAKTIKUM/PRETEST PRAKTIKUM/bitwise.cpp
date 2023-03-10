#include <iostream>
using namespace std;

int a[200005];

int main() {
    int loop, query, i =0;
    cin >> loop;
    while(i<loop)
    {
        cin >> a[i];
        i++;
    }
    cin >> query;
    while (query--) 
    {
        int t;
        cin >> t;
        if (t == 1) 
        {
            int x;
            string perintah;
            cin >> perintah >> x;
            for (int i = 0; i < loop; i++) 
            {
                if (perintah == "XOR") 
                {
                    a[i] ^= x;
                } else if (perintah == "OR") 
                {
                    a[i] |= x;
                } else {
                    a[i] &= x;
                }
            }
        } else {
            for (int i = 0; i < loop; i++) 
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}