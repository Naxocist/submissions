#include <bits/stdc++.h>
using namespace std;

using pi = pair<int, int>;
int main() {

    int t = 5;
    while(t--) {
        int n; scanf("%d", &n);
        int k = n, u, v;

        vector<pi> a, b;
        while(--n) {
            scanf("%d%d", &u, &v);
            if(u > v) swap(u, v);
            a.emplace_back(u, v);
        }
        while(--k) {
            scanf("%d%d", &u, &v);
            if(u > v) swap(u, v);
            b.emplace_back(u, v);
        }
        sort(a.begin(), a.end());  sort(b.begin(), b.end());
        printf("%c", (a == b ? 'Y' : 'N'));
    }
    return 0;
}