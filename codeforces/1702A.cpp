#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; scanf("%d", &n);
    int s = 0, m=n;
    while(m) {
        m/=10; s++;
    }
    int k = s - 1, x = 1;
    while(k--) x*=10;
    
    cout << n - x << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

    int t; scanf("%d", &t);
    while(t--) solve();
}