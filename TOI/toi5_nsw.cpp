#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string s, z; cin >> s >>  z;
    int ar[3];
    for(int i=0; i<3; ++i) ar[i] = s[i] - '0';

    for(char &c : z) {
        int k = c - '0';
        for(int i=0; i<3; ++i) k = ((k + ar[i] - 2) % 9) + 1;
        
        cout << k;
        ar[0] = (ar[0] + ar[0] - 1) % 9 + 1;
        ar[1] = (ar[1] + 7) % 9 + 1;
        ar[2] = (ar[2] + ((ar[2] + 8 - 1) % 9 +1) - 1) % 9 + 1;

        // for(int i=0; i<3; ++i) cout << ar[i] << ' ';
        // cout << endl;
    }
    return 0;
}