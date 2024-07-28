#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

vector<int> v;
int n;

int f() {
    vector<int> sum(1003);
    for(int i=0; i<=v[0]; ++i) sum[i] = 1;
    for(int i=1; i<=1000; ++i) sum[i] += sum[i-1];

    for(int i=1; i<n; ++i) {
        reverse(sum.begin(), sum.begin()+v[i]+1);
        fill(sum.begin()+v[i]+1, sum.end(), 0);
        for(int i=1; i<=1000; ++i) sum[i] += sum[i-1], sum[i]%=mod;
    }
    return sum[0];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    v.resize(n);
    int mn = 1e9;
    for(auto &x : v) cin >> x, mn = min(mn, x);
    int res = f();
    if(n&1) {
        while(mn--) {
            for(auto &x : v) x--;
            res += f(), res%=mod;
        }
    }
    cout << res;
    return 0;
}

