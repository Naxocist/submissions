#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            int x = i;
            x = min(x, j);
            x = min(x, n-i-1);
            x = min(x, n-j-1);
            
            cout << (x&1 ? " " : "*");
        }
        cout << '\n';
    }
    return 0;
}