#include <bits/stdc++.h>
using namespace std;
#define show(x) cout << #x << " is: " << x << '\n';
#define div() cout << "############\n";
#define all(x) x.begin(), x.end()
#define countBit(x) __builtin_popcount(x)
#define lsb(x) x&-x
#define pb emplace_back
using ll = long long;
using pi = pair<int, int>;
using T = tuple<int, int, int>;

#include <cassert>
#include <cstdio>
#include "trip.h"

const int N = 1e5 + 3;
const int LOG = 20;
int usefuel[N][LOG], usefuel2[N][LOG];
vector<ll> qs;
ll c;
int n;

ll dist(int a, int b) {
    if(a < b) swap(a, b);
    return qs[a] - qs[b];
}

void init_trip(int N, int Q, int C, std::vector<int> W) {
    n = N, c = C;
    qs.resize(n+1);
    for(int i=0; i<n-1; ++i) qs[i+2] = W[i];
    for(int i=1; i<=n; ++i) qs[i] += qs[i-1];

    for(int s=1; s<=n; ++s) {
        int l = s+1, r = n;
        int res = n;
        while(l <= r) {
            int md = l + (r-l)/2;
            if(dist(md, s) <= c) res = md, l = md + 1;
            else r = md - 1;
        }
        usefuel[s][0] = res;

        l = 1, r = s-1, res = 1;
        while(l <= r) {
            int md = l + (r-l)/2;
            if(dist(md, s) <= c) res = md, r = md - 1;
            else l = md + 1;
        }
        usefuel2[s][0] = res;
    }
    for(int L=1; L<LOG; ++L) {
        for(int i=1; i<=n; ++i) {
            usefuel[i][L] = usefuel[usefuel[i][L-1]][L-1];
        }
    }

    for(int L=1; L<LOG; ++L) {
        for(int i=1; i<=n; ++i) {
            usefuel2[i][L] = usefuel2[usefuel2[i][L-1]][L-1];
        }
    }
    return ;
}

void toggle(int G) {
    return;
}

int trip(int s, int t, int F) {
    s ++, t ++;
    ll f = F;
    int cnt = 0;
    if(s < t)
    {
        int l = s, r = n;
        int now = s;
        while(l <= r) {
            int md = l + (r-l)/2;
            if(dist(md, s) <= f) now = md, l = md + 1;
            else r = md - 1;
        }
        if(now == t) return 0;
        int nxt = 17;
        while(now != t) {
            int l = 0, r = nxt, res = 0;
            while(l <= r) {
                int md = l + (r-l)/2;
                if(usefuel[now][md] < t) res = md, l = md + 1;
                else r = md - 1;
            }
            nxt = res-1;
            now = usefuel[now][res];
    
            cnt += 1 << res;
        }
    }else {
        int l = 1, r = s;
        int now = s;
        while(l <= r) {
            int md = l + (r-l)/2;
            if(dist(md, s) <= f) now = md, r = md - 1;
            else l = md + 1;
        }
        if(now == t) return 0;
        int nxt = 17;
        while(now != t) {
            int l = 0, r = nxt, res = 0;
            while(l <= r) {
                int md = l + (r-l)/2;
                if(usefuel2[now][md] > t) res = md, l = md + 1;
                else r = md - 1;
            }
            now = usefuel2[now][res];
            nxt = res-1;
            cnt += 1 << res;
        }
    }
    return cnt;
}

signed main(int argc, const char **argv) {
    int N, Q, C;
    assert(scanf("%d%d%d", &N, &Q, &C) == 3);
    std::vector<int> W(N - 1);
    for(int i = 0; i < N - 1; i++) {
        assert(scanf("%d", &W[i]));
    }
    init_trip(N, Q, C, W);
    for(int i = 0; i < Q; i++) {
        int O;
        assert(scanf("%d", &O));
        if(O == 1){
            int G;
            assert(scanf("%d", &G));
            toggle(G);
        }else{
            int S, T, F;
            assert(scanf("%d%d%d", &S, &T, &F) == 3);
            printf("%d\n", trip(S, T, F));
        }
    }
    return 0;
}