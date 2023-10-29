#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; cin >> n >> m;
    
    for(int i=1; i<=n*2+1; ++i) {
        for(int j=1; j<=2*m+1; ++j) {
            if(i <= 2 && j <= 2) {
                cout << ".";
                continue ;
            }
            if(i & 1) {
                if(j & 1) cout << "+";
                else cout << "-";
            }else{
                
                if(j & 1) cout << "|";
                else cout << ".";
                
            }
        }
        cout << '\n';
    }
}

int main() {
    
    int q; cin >> q;
    for(int i=1; i<=q; ++i) {
        cout << "Case #" << i << ":\n";
        solve();
    }
    return 0;
}