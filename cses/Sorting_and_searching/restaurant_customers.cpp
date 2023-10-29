#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
 
int main() {
 
    int n; scanf("%d", &n);
    vector<pi> v;
 
    for(int i=0; i<n; ++i) {
        int a, b; scanf("%d%d", &a, &b);
        v.emplace_back(a, 1);
        v.emplace_back(b, -1);
    }
    sort(v.begin(), v.end());
    int ans = 0, c = 0;
    for(auto e : v) {
        c += e.second;
        ans = max(ans, c);
    }
 
    printf("%d", ans);
 
    return 0;
}
