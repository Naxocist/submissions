#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 3;
int neg[N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int z, k, n; cin >> z >> k >> n;
    // brute force
    vector<int> v(n);

    for(int i=0; i<n; ++i) {
        cin >> v[i];
    }

    for(int i=1; i<=z; ++i) {
        if(__gcd(i, k) == 1) neg[i]++;
        neg[i] += neg[i-1];
    }

    int mx = 0;
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            int l = v[i], r = v[j];
            mx = max(mx, abs(2*(neg[r] - neg[l-1]) - (r - l + 1)));
        }
    }

    cout << mx;
    return 0;
}