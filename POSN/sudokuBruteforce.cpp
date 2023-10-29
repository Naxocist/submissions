#include <bits/stdc++.h>
using namespace std;

int s[10][10], p[10][10];
bitset<10> b;
int main() {

    int q, n=9; scanf("%d", &q);
    
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) scanf("%d", &s[i][j]);
    }

    vector<int> res;
    for(int k=1; k<=q; ++k){
        bool ok = 1;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=n; ++j) {
                scanf("%d", &p[i][j]);
                if(s[i][j] && p[i][j] != s[i][j]) ok = 0;
            }
        }

        for(int i=1; i<=n; ++i) {
            b.reset();
            for(int j=1; j<=n; ++j) b[p[i][j]] = 1;
            if(b.count() != n) ok = 0;
        }
        for(int j=1; j<=n; ++j) {
            b.reset();
            for(int i=1; i<=n; ++i) b[p[i][j]] = 1;
            if(b.count() != n) ok = 0;
        }

        if(ok) res.push_back(k);
        
    }

    for(int x : res) cout << x << '\n';
    cout << "END";
    return 0;
}