#include <bits/stdc++.h>
#define endll '\n'
using namespace std;

 
int main() {
    int n; cin >> n;

    int criteria = n/2;

    map<int, int> mp;

    for(int i=0; i<n; ++i){
        int x; cin >> x;
        mp[x] += 1;
    }

    int mx = -1e9, w;

    for(auto k : mp){
        if(k.second > criteria && k.second > mx) {
            mx = k.second;
            w = k.first;
        }
    }

    if(mx < 0){
        cout << "no";
        return 0;
    }
    cout << w;

    return 0;
}

// I'll make eggs, chips and drinks.