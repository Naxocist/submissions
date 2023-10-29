#include <bits/stdc++.h>
using namespace std;

map<vector<int>, int> mp;

int main() {

    int n, p; scanf("%d%d", &n, &p);

    for(int i=1; i<=n; ++i) {
        vector<int> t(p);
        for(int j=0; j<p; ++j) scanf("%d", &t[j]);
        mp[t] = i; 
    }

    vector<int> res(p);
    for(int i=0; i<p; ++i) scanf("%d", &res[i]);

    int k = mp[res];
    if(k) {
        cout << k; return 0;
    }

    for(auto x : mp) {
        vector<int> t = res;
        for(int i=0; i<p; ++i) {
            t[i] -= x.first[i];
        }
        if(t == x.first) continue ;
        if(mp.find(t) != mp.end()) {
            int a = x.second, b = mp[t];
            if(a > b) swap(a, b);
            cout << a << ' ' << b; return 0;
        }
    }

    cout << "NO";
    return 0;
}

/*
3 2
1 2
3 4
5 6
6 8
*/