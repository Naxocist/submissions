#include <bits/stdc++.h>
using namespace std;
#define INF 2e9
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define allrev(x) x.rbegin(), x.rend()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

void solve() {
    int n; cin >> n;
    vector<int> cnt(n+1), s(n+1);
    for(int i=0;i<n;++i){
        int x;cin>>x;
        cnt[x]++;
    }
    for(int i=0;i<=n;++i) s[cnt[i]]++;
    int res=-1,prv=-1;
    for(int i=n;i>0;--i){
        for(int j=0;j<s[i];++j){
            if(prv==0) goto g;
            if(res==-1)res=i,prv=i;
            else if(i>=prv)res+=prv-1,prv--;
            else res+=i,prv=i;
        }
    }
    g:;
    cout << res << '\n';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
