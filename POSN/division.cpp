#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 3;
int sieve[N], cnt[N], t[N];

int main() {

    for(int i=1; i<=N; ++i) {
        sieve[i] = i;
        if(i % 2 == 0) sieve[i] = 2;
    }

    for(int i=2; i*i<=N; ++i) {
        if(sieve[i] != i) continue ;
        for(int j=i*i; j<=N; j+=i) {
            if(sieve[j] != j) continue ;
            sieve[j] = i;
        }
    }
    
    int n; scanf("%d", &n);
    int mx = 0;

    for(int i=0; i<n; ++i) {
        int x; scanf("%d", &x);
        set<int> s;
        while(x != 1) {
            t[sieve[x]] ++;
            s.insert(sieve[x]);
            mx = max(mx, sieve[x]);
            x /= sieve[x];
        }

        for(int y : s) {
            cnt[y] = max(cnt[y], t[y]);
            t[y] = 0;
        }
    }
    int res = 0;
    for(int i=2; i<=mx; ++i) {
        res += cnt[i];
    }
    printf("%d", res);
    return 0;
}