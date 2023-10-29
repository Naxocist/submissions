#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define all(x) x.begin(), x.end()
const int N = 1e6 + 3;
using ll = long long;
unordered_map<int, int> c;
int v[N], a[N],fw[N];

void upd(int i, int x) {
    for(;i<N;i+=i&-i) fw[i] += x;
}

int qry(int i) {
    int s = 0;
    for(;i>0;i-=i&-i) s+=fw[i];
    return s;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;

    for(int i=1; i<=n; ++i) {
        cin >> v[i];
        a[i] = ++c[v[i]];
    }
    c.clear();
    ll res = 0;
    for(int i=n; i>=1; --i) {
        res += qry(a[i]-1);
        upd(++c[v[i]], 1);
    }
    cout << res;
}