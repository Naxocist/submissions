#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 3;
int t[N], s[N], ar[N];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr);
    int n, q; scanf("%d%d", &n, &q);

    for(int i=0; i<n; ++i) {
        scanf("%d", &ar[i]);
        if(ar[i] < 0) {
            t[i] += abs(ar[i]);
        }else {
            s[i] += ar[i];
        }

        if(!i) continue ;
        t[i] += t[i-1];
        s[i] += s[i-1];
    }

    while(q--) {
        int x, h; scanf("%d%d", &x, &h);
        h += t[x-1];
        int idx = lower_bound(t+x, t+n, h) - t;
    
        cout << s[min(n-1, idx)] - s[x-1] << '\n';
    }
    return 0;
}