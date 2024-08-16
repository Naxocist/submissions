#include <bits/stdc++.h>
using namespace std;

#define deb 0

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    if(deb) {
        freopen("./in.txt", "r", stdin);
        freopen("./out.txt", "w", stdout);
    }

    int n; cin >> n;
    cout << 10*n;

    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cout << "*\n"[j==n-1];
        }
    }

    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        for(auto &x : v) cin >> x;

    }

    return 0;
}
