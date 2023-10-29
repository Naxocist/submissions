#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll base = 41, MOD = 1e9+7;
 
int n, q;
ll powa[200065];
ll fenw[200065], fenw2[200005];
string inp, rev;
 
void upd(ll *arr, int x, ll val) {
    for(;x<=n;x+=x&-x)
        arr[x] = (arr[x] + val) % MOD;
}
 
ll qr(ll *arr, int x) {
    ll sum = 0;
    for(;x;x-=x&-x)
        sum = (sum+arr[x]) % MOD;
    return sum;
}
 
int a, b, c;
char x;
 
int main() {
    powa[0] = 1;
    for(int i=1;i<=200005;i++) powa[i] = (powa[i-1]*base) % MOD;
    cin >> n >> q;
    cin >> rev; inp = rev; reverse(rev.begin(), rev.end());
    rev.insert(rev.begin(), 0); inp.insert(inp.begin(), 0);
    for(int i=1;i<=n;i++) {
        upd(fenw, i, powa[i]*inp[i]);
        upd(fenw2, i, powa[i]*rev[i]);
    }
    while(q--) {
        cin >> a;
        if(a == 2) {
            cin >> b >> c;
            ll str1 = qr(fenw, c) - qr(fenw, b-1) + MOD; str1 %= MOD;
            ll str2 = qr(fenw2, n-b+1) - qr(fenw2, n-c) + MOD; str2 %= MOD;
            str1 = (str1*powa[n-b]) % MOD; str2 = (str2*powa[c-1]) % MOD;
            //cout << str1 << ' ' << str2 << '\n';
            if(str1 == str2) cout << "YES\n";
            else cout << "NO\n";
        } else {
            cin >> b >> x; ll diff = x-inp[b]; //cout << diff << '\n';
            upd(fenw, b, diff*powa[b]); inp[b] = x;
            upd(fenw2, n-b+1, diff*powa[n-b+1]); 
        }
    }
}
