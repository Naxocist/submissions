#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using tiii = tuple<int, int, int>;

const int N = 1e5 + 3;
int ar[N];

int main() {
    // freopen("input.in", "r", stdin);
    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    ll l, r;
    l = r = 0;
    for(int i=1; i<=n; ++i) scanf("%d", &ar[i]), r+= ar[i];
    
    ll mx = 0;
    while(l <= r){
        ll md = (l+r)/2, s = 0;
        int use = 0;

        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i=1; i<=n; ++i){
            pq.push(ar[i]);
            s += ar[i];
            while(pq.size() > k) s -= pq.top(), pq.pop(); // pq will keep holding k highest elements

            if(s >= md && pq.size() == k){
                use++;
                s = 0;
                pq = priority_queue<ll, vector<ll>, greater<ll>>();
            }
        }
   
        if(use >= m){
            mx = md;
            l = md + 1;
        }else r = md - 1;
    }

    printf("%lld", mx);
}
